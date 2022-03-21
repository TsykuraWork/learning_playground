#include "helpers.h"
// #include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    // for (int i = 0; i < width; i++)
    // {
    //     for (int j = 0; j < height; j++)
    //     {
    //         image[i][j].rgbtRed = rint(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
    //         image[i][j].rgbtGreen = rint(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
    //         image[i][j].rgbtBlue = rint(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

    //         if (image[i][j].rgbtRed > 255)
    //             image[i][j].rgbtRed = 255;
    //         if (image[i][j].rgbtGreen > 255)
    //             image[i][j].rgbtGreen = 255;
    //         if (image[i][j].rgbtBlue > 255)
    //             image[i][j].rgbtBlue = 255;
    //     }
    // }
    // return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // int reflHeight;
    // RGBTRIPLE tmp;
    // if (height%2 == 0)
    //     reflHeight = height/2 - 1;
    // else
    //     reflHeight = height/2;

    // for (int i = 0; i < width; i++)
    // {
    //     for (int j = 0; j < reflHeight; j++)
    //     {
    //         tmp = image[i][j];
    //         image[i][j] = image[i][height - j - 1];
    //         image[i][height - j - 1] = tmp;
    //     }
    // }
    // return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //     int i;
    //     int j;
    //     RGBTRIPLE scndImage[height+2][width+2];
    //     //копируем во вторую таблицу значения первой, оставляя пустыми крайние поля
    //     for (i = 1; i < width+1; i++)
    //     {
    //         for (j = 1; j < height+1; j++)
    //         {
    //             scndImage[i][j].rgbtRed = image[i-1][j-1].rgbtRed;
    //             scndImage[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
    //             scndImage[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
    //         }
    //     }

    //     // добавляем нолики по краям

    //     // по столбикам
    //     for (j = 0; j < height + 2; j++ )
    //     {
    //         scndImage[0][j].rgbtRed = 0;
    //         scndImage[0][j].rgbtBlue = 0;
    //         scndImage[0][j].rgbtGreen = 0;
    //         scndImage[width + 1][j].rgbtRed = 0;
    //         scndImage[width + 1][j].rgbtBlue = 0;
    //         scndImage[width + 1][j].rgbtGreen = 0;
    //     }

    //     // по рядам
    //     for (i = 0; i < width + 2; i ++)
    //     {
    //         scndImage[i][0].rgbtRed = 0;
    //         scndImage[i][0].rgbtBlue = 0;
    //         scndImage[i][0].rgbtGreen = 0;
    //         scndImage[i][height + 1].rgbtRed = 0;
    //         scndImage[i][height + 1].rgbtBlue = 0;
    //         scndImage[i][height + 1].rgbtGreen = 0;
    //     }

    //     RGBTRIPLE blurImage[height][width];
    //     int counterRed = 0;
    //     int counterBlue = 0;
    //     int counterGreen = 0;
    //     int sumRed=0;
    //     int sumGreen=0;
    //     int sumBlue=0;
    //     int avg;

    //     for (i = 0; i < width; i++)
    //     {
    //         for (j = 0; j < height; j++)
    //         {
    //             for (int k = -1; k < 2; k++)
    //             {
    //                 for (int l = -1; l < 2; l++ )
    //                 {
    //                     if (scndImage[i+k][j+l].rgbtRed != 0)
    //                     {
    //                         counterRed++;
    //                         sumRed += scndImage[i + k][j + l].rgbtRed;
    //                     }
    //                     if (scndImage[i + k][j + l].rgbtBlue != 0)
    //                     {
    //                         counterBlue++;
    //                         sumBlue += scndImage[i + k][j + l].rgbtBlue;
    //                     }
    //                     if (scndImage[i + k][j + l].rgbtGreen != 0)
    //                     {
    //                         counterGreen++;
    //                         sumGreen += scndImage[i + k][j + l].rgbtGreen;
    //                     }
    //                 }
    //             }
    //             blurImage[i][j].rgbtRed = sumRed/counterRed;
    //             blurImage[i][j].rgbtBlue = sumBlue / counterBlue;
    //             blurImage[i][j].rgbtGreen = sumGreen / counterGreen;
    //         }
    //     }

    //     return;
}
