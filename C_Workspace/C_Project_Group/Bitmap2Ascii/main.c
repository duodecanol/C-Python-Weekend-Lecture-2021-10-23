#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bitmapstruct.h"

// https://dojang.io/mod/page/view.php?id=704
#define PIXEL_SIZE	3 // 3 bytes per pixel
#define PIXEL_ALIGN	4 // 픽셀 데이터의 가로 한 줄에서 남는 공간(padding)을 구하기 위한 정렬값입니다
// (비트맵 포맷은 픽셀 데이터의 가로 한 줄을 저장할 때 4의 배수 크기로 저장합니다)
// CPU에서 4바이트 크기가 효율적이기 때문입니다.

int main() {
	FILE* fpBmp; // Bitmap file filepointer
	FILE* fpTxt; // Text file filepointer
	BITMAPFILEHEADER fileHeader; // bitmap file header struct 
	BITMAPINFOHEADER infoHeader; // bitmap info header struct

	unsigned char* image; // Pixel data pointer
	int imgSize;		  // Pixel data size
	int width, height;    // width, height of the bitmap image
	int padding;		  // the remaining space's size in case where the width of the bitmap image is not 4-fold

	// 각 픽셀을 표현할 ASCII 문자를 배열로 만듭니다. 
	// 비트맵 이미지에서 픽셀의 RGB 색상값이 모두 0이면 검정색이고, 모두 255이면 흰색입니다.
	// 즉, 값이 작을수록 어두워지고 값이 클수록 밝아집니다. 
	// 따라서 배열의 낮은 인덱스에는 획수가 많은 문자를 배치하고 높은 인덱스에는 획수가 적은 문자를 배치합니다. 
	// 그리고 가장 큰 인덱스에는 공백 문자를 넣습니다.
	char ascii[] = { '&', '#', '@', '%', '=', '+', '*', ':', '-', '.', ' ' };    // 11개


	/*  BLOCK 2
	fopen 함수로 비트맵 파일을 바이너리 모드(rb)로 연 뒤 fread 함수로 비트맵 파일 헤더를 읽습니다. 
	그다음에 비트맵 파일이 맞는지 확인하기 위해 bfType의 값이 'MB'가 맞는지 확인합니다
	(2바이트 크기의 'BM'을 리틀 엔디언 방식으로 읽었으므로 'B'와 'M'이 뒤집혀서 'MB'가 됩니다). 
	만약 이 값이 맞지 않으면 비트맵 파일이 아닙니다.
	*/
	fpBmp = fopen("C:\\Users\\C weekend\\Pictures\\pimang.bmp", "rb"); // Open bitmap file with read-only binary mode
	if (fpBmp == NULL) {// If file opening fails,
		puts("Failed to open file");
		return 0;	   // Exit program
	}

	// Read bitmap file header. If reading fails, close the file pointer and the exit program.
	if (fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1) { // if succeed, returns 1.
		fclose(fpBmp);
		puts("Failed to read bitmap file header");
		return 0;
	}

	// Check if the magic number is 'MB'  (2바이트 크기의 BM을 리틀 엔디언으로 읽었으므로 MB가 됨)
	if (fileHeader.bfType != 'MB') { // 
		fclose(fpBmp);
		puts("It seems the file is not a bitmap file. The magic number is not BM.");
		return 0;
	}
	/* BLOCK 3
	이번에는 비트맵 정보 헤더를 읽습니다. 
	비트맵 정보 헤더는 비트맵 파일 헤더 바로 뒤에 있으므로 파일 포인터를 이동시키지 않고 
	바로 fread 함수로 읽으면 됩니다. 비트맵 정보 헤더를 읽었으면 biBitCount의 값이 24인지 확인합니다. 
	이번 예제에서는 24비트 비트맵만 처리할 것이므로 24가 아니면 파일 포인터를 닫고 프로그램을 종료합니다.
	*/
	if (fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1) {
		fclose(fpBmp);
		puts("Failed to read bitmap info header");
		return 0;
	}
	if (infoHeader.biBitCount != 24) {
		fclose(fpBmp);
		puts("The bitmap file is other than 24-bit bitmap.");
		return 0;
	}

	// 픽셀 데이터의 크기, 이미지의 가로, 세로 크기와 같이 자주 사용하는 정보는 변수에 따로 저장해놓습니다.
	imgSize = infoHeader.biSizeImage;    // 픽셀 데이터 크기
	width = infoHeader.biWidth;       // 비트맵 이미지의 가로 크기
	height = infoHeader.biHeight;     // 비트맵 이미지의 세로 크기
	// 이미지의 가로 크기에 픽셀 크기를 곱하여 가로 한 줄의 크기를 구하고 4로 나머지를 구함
	// 그리고 4에서 나머지를 빼주면 남는 공간을 구할 수 있음.
	// 만약 남는 공간이 0이라면 최종 결과가 4가 되므로 여기서 다시 4로 나머지를 구함
	padding = (PIXEL_ALIGN - (width * PIXEL_SIZE) % PIXEL_ALIGN) % PIXEL_ALIGN;

	// if 'infoHeader.biSizeImage is 0, you have to calculate the size of the image.
	if (imgSize == 0) {
		imgSize = (width * PIXEL_SIZE + padding) * height;
	}

	image = malloc(imgSize);  // 픽셀 데이터의 크기만큼 동적 메모리 할당
	/* BLOCK 4
	이제 비트맵 이미지의 픽셀 데이터를 읽습니다. 
	24비트 비트맵 파일에서는 비트맵 정보 헤더 바로 다음에 픽셀 데이터가 있어서
	바로 fread 함수로 읽어도 됩니다. 하지만 여기서는 bfOffBits 값을 활용하여 파일 포인터를
	픽셀 데이터의 시작 위치로 이동시켰습니다.
	*/

	// move file pointer to the start position of the pixel data
	fseek(fpBmp, fileHeader.bfOffBits, SEEK_SET);

	// Read from file as much as the size of image. If reading fails, close FP and exit program.
	if (fread(image, imgSize, 1, fpBmp) < 1) {
		fclose(fpBmp);
		puts("Failed to read bitmap image.");
		return 0;
	}

	fclose(fpBmp);
	puts("Successfully read the image file.");

	fpTxt = fopen("ascii.txt", "w"); // Open text file for test print
	if (fpTxt == NULL) {			// if file open fails,
		free(image);				// unload the memory
		puts("Failed to open text file for printing");
		return 0;
	}

	/* BLOCK 5
	이제 픽셀 데이터를 ASCII 문자로 변환하는 부분입니다.
	보통 비트맵 파일의 픽셀 데이터는 아래 위가 뒤집혀서 저장됩니다. 
	따라서 반복문에서는 그림의 아래쪽부터 처리해야 합니다.

	*/

	// Iterating through height pixel inversely
	for (int y = height - 1; y >= 0; y--) {
		// Iterating through width pixel forward
		for (int x = 0; x < width; x++) {
			// Calc index to access the element of pixel array
			// Horizontal Pixel Position : ( x * PIXEL_SIZE )
			// Longditudnal Pixel Position : ( y * ( width * PIXEL_SIZE))
			// Accumulated Remaining Spaces : padding * y
			int index = (x * PIXEL_SIZE) + (y * (width * PIXEL_SIZE)) + (padding * y);

			// Convert current pixel address into RGBTRIPLE pointer
			RGBTRIPLE* pixel = (RGBTRIPLE*)&image[index];

			// Fetch red, green blue values using RGBTRIPLE struct
			unsigned char blue = pixel->rgbtBlue;
			unsigned char green = pixel->rgbtGreen;
			unsigned char red = pixel->rgbtRed;

			// Get Monochrome value by calculating average of (R, G, B)
			unsigned char gray = (red + green + blue) / PIXEL_SIZE;

			// Get the index of predefined ascii charset (11 elems) from below eqaution.
			// [0 ~ 255] * 11 / 256
			char c = ascii[gray * sizeof(ascii) / 256];

			// 비트맵 이미지에서는 픽셀의 가로, 세로 크기가 똑같지만
			// 보통 ASCII 문자는 세로로 길쭉한 형태이므로 정사각형 모양과 비슷하게 보여주기 위해
			// 같은 문자를 두 번 저장해줌
			fprintf(fpTxt, "%c%c", c, c);    // 텍스트 파일에 문자 출력
			//printf(fpTxt, "%c%c", c, c); // 문자 꺠져서 나옴
		}
		fprintf(fpTxt, "\n");    // 가로 픽셀 저장이 끝났으면 줄바꿈을 해줌
		//printf(fpTxt, "\n");
	}
	fclose(fpTxt);    // 텍스트 파일 닫기

	free(image);      // 픽셀 데이터를 저장한 동적 메모리 해제

	return 1;
}