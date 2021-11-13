#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bitmapstruct.h"

// https://dojang.io/mod/page/view.php?id=704
#define PIXEL_SIZE	3 // 3 bytes per pixel
#define PIXEL_ALIGN	4 // �ȼ� �������� ���� �� �ٿ��� ���� ����(padding)�� ���ϱ� ���� ���İ��Դϴ�
// (��Ʈ�� ������ �ȼ� �������� ���� �� ���� ������ �� 4�� ��� ũ��� �����մϴ�)
// CPU���� 4����Ʈ ũ�Ⱑ ȿ�����̱� �����Դϴ�.

int main() {
	FILE* fpBmp; // Bitmap file filepointer
	FILE* fpTxt; // Text file filepointer
	BITMAPFILEHEADER fileHeader; // bitmap file header struct 
	BITMAPINFOHEADER infoHeader; // bitmap info header struct

	unsigned char* image; // Pixel data pointer
	int imgSize;		  // Pixel data size
	int width, height;    // width, height of the bitmap image
	int padding;		  // the remaining space's size in case where the width of the bitmap image is not 4-fold

	// �� �ȼ��� ǥ���� ASCII ���ڸ� �迭�� ����ϴ�. 
	// ��Ʈ�� �̹������� �ȼ��� RGB ������ ��� 0�̸� �������̰�, ��� 255�̸� ����Դϴ�.
	// ��, ���� �������� ��ο����� ���� Ŭ���� ������ϴ�. 
	// ���� �迭�� ���� �ε������� ȹ���� ���� ���ڸ� ��ġ�ϰ� ���� �ε������� ȹ���� ���� ���ڸ� ��ġ�մϴ�. 
	// �׸��� ���� ū �ε������� ���� ���ڸ� �ֽ��ϴ�.
	char ascii[] = { '&', '#', '@', '%', '=', '+', '*', ':', '-', '.', ' ' };    // 11��


	/*  BLOCK 2
	fopen �Լ��� ��Ʈ�� ������ ���̳ʸ� ���(rb)�� �� �� fread �Լ��� ��Ʈ�� ���� ����� �н��ϴ�. 
	�״����� ��Ʈ�� ������ �´��� Ȯ���ϱ� ���� bfType�� ���� 'MB'�� �´��� Ȯ���մϴ�
	(2����Ʈ ũ���� 'BM'�� ��Ʋ ����� ������� �о����Ƿ� 'B'�� 'M'�� �������� 'MB'�� �˴ϴ�). 
	���� �� ���� ���� ������ ��Ʈ�� ������ �ƴմϴ�.
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

	// Check if the magic number is 'MB'  (2����Ʈ ũ���� BM�� ��Ʋ ��������� �о����Ƿ� MB�� ��)
	if (fileHeader.bfType != 'MB') { // 
		fclose(fpBmp);
		puts("It seems the file is not a bitmap file. The magic number is not BM.");
		return 0;
	}
	/* BLOCK 3
	�̹����� ��Ʈ�� ���� ����� �н��ϴ�. 
	��Ʈ�� ���� ����� ��Ʈ�� ���� ��� �ٷ� �ڿ� �����Ƿ� ���� �����͸� �̵���Ű�� �ʰ� 
	�ٷ� fread �Լ��� ������ �˴ϴ�. ��Ʈ�� ���� ����� �о����� biBitCount�� ���� 24���� Ȯ���մϴ�. 
	�̹� ���������� 24��Ʈ ��Ʈ�ʸ� ó���� ���̹Ƿ� 24�� �ƴϸ� ���� �����͸� �ݰ� ���α׷��� �����մϴ�.
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

	// �ȼ� �������� ũ��, �̹����� ����, ���� ũ��� ���� ���� ����ϴ� ������ ������ ���� �����س����ϴ�.
	imgSize = infoHeader.biSizeImage;    // �ȼ� ������ ũ��
	width = infoHeader.biWidth;       // ��Ʈ�� �̹����� ���� ũ��
	height = infoHeader.biHeight;     // ��Ʈ�� �̹����� ���� ũ��
	// �̹����� ���� ũ�⿡ �ȼ� ũ�⸦ ���Ͽ� ���� �� ���� ũ�⸦ ���ϰ� 4�� �������� ����
	// �׸��� 4���� �������� ���ָ� ���� ������ ���� �� ����.
	// ���� ���� ������ 0�̶�� ���� ����� 4�� �ǹǷ� ���⼭ �ٽ� 4�� �������� ����
	padding = (PIXEL_ALIGN - (width * PIXEL_SIZE) % PIXEL_ALIGN) % PIXEL_ALIGN;

	// if 'infoHeader.biSizeImage is 0, you have to calculate the size of the image.
	if (imgSize == 0) {
		imgSize = (width * PIXEL_SIZE + padding) * height;
	}

	image = malloc(imgSize);  // �ȼ� �������� ũ�⸸ŭ ���� �޸� �Ҵ�
	/* BLOCK 4
	���� ��Ʈ�� �̹����� �ȼ� �����͸� �н��ϴ�. 
	24��Ʈ ��Ʈ�� ���Ͽ����� ��Ʈ�� ���� ��� �ٷ� ������ �ȼ� �����Ͱ� �־
	�ٷ� fread �Լ��� �о �˴ϴ�. ������ ���⼭�� bfOffBits ���� Ȱ���Ͽ� ���� �����͸�
	�ȼ� �������� ���� ��ġ�� �̵����׽��ϴ�.
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
	���� �ȼ� �����͸� ASCII ���ڷ� ��ȯ�ϴ� �κ��Դϴ�.
	���� ��Ʈ�� ������ �ȼ� �����ʹ� �Ʒ� ���� �������� ����˴ϴ�. 
	���� �ݺ��������� �׸��� �Ʒ��ʺ��� ó���ؾ� �մϴ�.

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

			// ��Ʈ�� �̹��������� �ȼ��� ����, ���� ũ�Ⱑ �Ȱ�����
			// ���� ASCII ���ڴ� ���η� ������ �����̹Ƿ� ���簢�� ���� ����ϰ� �����ֱ� ����
			// ���� ���ڸ� �� �� ��������
			fprintf(fpTxt, "%c%c", c, c);    // �ؽ�Ʈ ���Ͽ� ���� ���
			//printf(fpTxt, "%c%c", c, c); // ���� ������ ����
		}
		fprintf(fpTxt, "\n");    // ���� �ȼ� ������ �������� �ٹٲ��� ����
		//printf(fpTxt, "\n");
	}
	fclose(fpTxt);    // �ؽ�Ʈ ���� �ݱ�

	free(image);      // �ȼ� �����͸� ������ ���� �޸� ����

	return 1;
}