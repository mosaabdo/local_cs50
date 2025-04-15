#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int buf = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = buf;
            image[i][j].rgbtGreen = buf;
            image[i][j].rgbtRed = buf;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE buf = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buf;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = 0, g = 0, b = 0, count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        r += copy[ni][nj].rgbtRed;
                        g += copy[ni][nj].rgbtGreen;
                        b += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round(r / (float)count);
            image[i][j].rgbtGreen = round(g / (float)count);
            image[i][j].rgbtBlue = round(b / (float)count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Copy the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Apply Sobel operator
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize Gx and Gy
            int rgx = 0, ggx = 0, bgx = 0;
            int rgy = 0, ggy = 0, bgy = 0;

            // Compute Gx and Gy
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di, nj = j + dj;

                    // Check if the neighbor pixel is within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        rgx += copy[ni][nj].rgbtRed * gx[di + 1][dj + 1];
                        rgy += copy[ni][nj].rgbtRed * gy[di + 1][dj + 1];
                        ggx += copy[ni][nj].rgbtGreen * gx[di + 1][dj + 1];
                        ggy += copy[ni][nj].rgbtGreen * gy[di + 1][dj + 1];
                        bgx += copy[ni][nj].rgbtBlue * gx[di + 1][dj + 1];
                        bgy += copy[ni][nj].rgbtBlue * gy[di + 1][dj + 1];
                    }
                }
            }

            // Calculate final gradient values
            int G_red = round(sqrt((rgx * rgx) + (rgy * rgy)));
            int G_green = round(sqrt((ggx * ggx) + (ggy * ggy)));
            int G_blu = round(sqrt((bgx * bgx) + (bgy * bgy)));

            // Cap values to 255
            G_red = (G_red > 255) ? 255 : G_red;
            G_green = (G_green > 255) ? 255 : G_green;
            G_blu = (G_blu > 255) ? 255 : G_blu;

            // Update pixel values
            image[i][j].rgbtRed = G_red;
            image[i][j].rgbtGreen = G_green;
            image[i][j].rgbtBlue = G_blu;
        }
    }

    return;
}
