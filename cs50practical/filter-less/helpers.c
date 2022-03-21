#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red, green, blue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = (int)round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            green = (int)round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            blue = (int)round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (red > 255)
                red = 255;
            if (green > 255)
                green = 255;
            if (blue > 255)
                blue = 255;
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int reflHeight;
    RGBTRIPLE tmp;
    if (height % 2 == 0)
        reflHeight = height / 2 - 1;
    else
        reflHeight = height / 2;

    for (int i = 0; i < reflHeight; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurImage[height][width];
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //заполняем крайние поля
            //[0][0]
            if (i == 0 && j == 0)
            {
                blurImage[0][0].rgbtRed = round((image[0][0].rgbtRed + image[1][0].rgbtRed + image[0][1].rgbtRed + image[1][1].rgbtRed) / 4);
                blurImage[0][0].rgbtGreen = round((image[0][0].rgbtGreen + image[1][0].rgbtGreen + image[0][1].rgbtGreen + image[1][1].rgbtGreen) / 4);
                blurImage[0][0].rgbtBlue = round((image[0][0].rgbtBlue + image[1][0].rgbtBlue + image[0][1].rgbtBlue + image[1][1].rgbtBlue) / 4);
            }
            //[height-1][0]
            else if (i == height - 1 && j == 0)
            {
                blurImage[height - 1][0].rgbtRed = round((image[height - 1][0].rgbtRed + image[height - 2][0].rgbtRed + image[height - 1][1].rgbtRed + image[height - 2][1].rgbtRed) / 4);
                blurImage[height - 1][0].rgbtGreen = round((image[height - 1][0].rgbtGreen + image[height - 2][0].rgbtGreen + image[height - 1][1].rgbtGreen + image[height - 2][1].rgbtGreen) / 4);
                blurImage[height - 1][0].rgbtBlue = round((image[height - 1][0].rgbtBlue + image[height - 2][0].rgbtBlue + image[height - 1][1].rgbtBlue + image[height - 2][1].rgbtBlue) / 4);
            }

            //[0][width-1]
            else if (i == 0 && j == width - 1)
            {
                blurImage[0][width - 1].rgbtRed = round((image[0][width - 2].rgbtRed + image[1][width - 2].rgbtRed + image[1][width - 1].rgbtRed + image[0][width - 1].rgbtRed) / 4);
                blurImage[0][width - 1].rgbtGreen = round((image[0][width - 2].rgbtGreen + image[1][width - 2].rgbtGreen + image[1][width - 1].rgbtGreen + image[0][width - 1].rgbtGreen) / 4);
                blurImage[0][width - 1].rgbtBlue = round((image[0][width - 2].rgbtBlue + image[1][width - 2].rgbtBlue + image[1][width - 1].rgbtBlue + image[0][width - 1].rgbtBlue) / 4);
            }

            //[height][width]
            else if (i == height - 1 && j == width - 1)
            {
                blurImage[height - 1][width - 1].rgbtRed = round((image[height - 1][width - 1].rgbtRed + image[height - 2][width - 1].rgbtRed + image[height - 1][width - 2].rgbtRed + image[height - 2][width - 2].rgbtRed) / 4);
                blurImage[height - 1][width - 1].rgbtGreen = round((image[height - 1][width - 1].rgbtGreen + image[height - 2][width - 1].rgbtGreen + image[height - 1][width - 2].rgbtGreen + image[height - 2][width - 2].rgbtGreen) / 4);
                blurImage[height - 1][width - 1].rgbtBlue = round((image[height - 1][width - 1].rgbtBlue + image[height - 2][width - 1].rgbtBlue + image[height - 1][width - 2].rgbtBlue + image[height - 2][width - 2].rgbtBlue) / 4);
            }

            // по верхней линии не крайний
            else if (i == 0 && j != 0 && j != width - 1)
            {
                blurImage[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6);
                blurImage[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6);
                blurImage[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6);
            }

            // по нижней линии не крайний
            else if (i == height - 1 && j != 0 && j != width - 1)
            {
                blurImage[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6);
                blurImage[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6);
                blurImage[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6);
            }

            // по левой линии не крайний
            else if (j == 0 && i != 0 && i != height - 1)
            {
                blurImage[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6);
                blurImage[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6);
                blurImage[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6);
            }

            // по правой линии не крайний
            else if (j == width - 1 && i != 0 && i != height - 1)
            {
                blurImage[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6);
                blurImage[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6);
                blurImage[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6);
            }

            // все остальные, шо образуют 3х3
            else
            {
                blurImage[i][j].rgbtRed = round((image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) / 9);
                blurImage[i][j].rgbtGreen = round((image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 9);
                blurImage[i][j].rgbtBlue = round((image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 9);
            }
        }
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j] = blurImage[i][j];
        }
    }
    return;
}
