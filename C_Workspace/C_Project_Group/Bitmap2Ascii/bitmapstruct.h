#pragma pack(push, 1)                // ����ü�� 1����Ʈ ũ��� ����
/*
BITMAPFILEHEADER: https://msdn.microsoft.com/ko-kr/library/windows/desktop/dd183374(v=vs.85).aspx
BITMAPINFOHEADER: https://msdn.microsoft.com/ko-kr/library/windows/desktop/dd183376(v=vs.85).aspx
RGBTRIPLE: https://msdn.microsoft.com/ko-kr/library/windows/desktop/dd162939(v=vs.85).aspx
*/

typedef struct _BITMAPFILEHEADER     // BMP ��Ʈ�� ���� ��� ����ü
{
    unsigned short bfType;           // BMP ���� ���� �ѹ�
    unsigned int   bfSize;           // ���� ũ��
    unsigned short bfReserved1;      // ����
    unsigned short bfReserved2;      // ����
    unsigned int   bfOffBits;        // ��Ʈ�� �������� ���� ��ġ
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP ��Ʈ�� ���� ��� ����ü(DIB ���)
{
    unsigned int   biSize;           // ���� ����ü�� ũ��
    int            biWidth;          // ��Ʈ�� �̹����� ���� ũ��
    int            biHeight;         // ��Ʈ�� �̹����� ���� ũ��
    unsigned short biPlanes;         // ����ϴ� �������� ��
    unsigned short biBitCount;       // �ȼ� �ϳ��� ǥ���ϴ� ��Ʈ ��
    unsigned int   biCompression;    // ���� ���
    unsigned int   biSizeImage;      // ��Ʈ�� �̹����� �ȼ� ������ ũ��
    int            biXPelsPerMeter;  // �׸��� ���� �ػ�(���ʹ� �ȼ�)
    int            biYPelsPerMeter;  // �׸��� ���� �ػ�(���ʹ� �ȼ�)
    unsigned int   biClrUsed;        // ���� ���̺��� ���� ���Ǵ� ���� ��
    unsigned int   biClrImportant;   // ��Ʈ���� ǥ���ϱ� ���� �ʿ��� ���� �ε��� ��
} BITMAPINFOHEADER;

typedef struct _RGBTRIPLE            // 24��Ʈ ��Ʈ�� �̹����� �ȼ� ����ü
{
    unsigned char rgbtBlue;          // �Ķ�
    unsigned char rgbtGreen;         // �ʷ�
    unsigned char rgbtRed;           // ����
} RGBTRIPLE;

#pragma pack(pop)