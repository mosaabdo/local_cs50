# Image Processing Functions Documentation
### Frome cs50 problem set week 4
#### Fillter_more :  helper.c file

This documentation provides a detailed explanation of the implementation of four image processing functions: **grayscale**, **reflect**, **blur**, and **edges**. These functions operate on a 2D array of RGBTRIPLE structs representing an image. Each function is explained with its purpose, approach, and code snippets.

## Table of Contents
1. [Grayscale Conversion](#grayscale-conversion)
2. [Horizontal Reflection](#horizontal-reflection)
3. [Blurring](#blurring)
4. [Edge Detection](#edge-detection)

---

## Grayscale Conversion

### Purpose
The `grayscale` function converts a color image to grayscale by averaging the RGB values of each pixel and assigning the average to all three color channels (Red, Green, Blue).

### Code
```c
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
```

### Explanation
1. **Input:** Height and width of the image, and a 2D array of RGBTRIPLE structs.
2. **Operation:** For each pixel:
   - Calculate the average of the `rgbtBlue`, `rgbtGreen`, and `rgbtRed` values.
   - Assign this average to all three channels of the pixel.
3. **Output:** The input image is modified to be grayscale.

---

## Horizontal Reflection

### Purpose
The `reflect` function flips an image horizontally by swapping pixels on the left side with those on the right side.

### Code
```c
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
```

### Explanation
1. **Input:** Height and width of the image, and a 2D array of RGBTRIPLE structs.
2. **Operation:** For each row:
   - Iterate through half of the row's pixels.
   - Swap each pixel with its horizontally opposite pixel.
3. **Output:** The input image is horizontally mirrored.

---

## Blurring

### Purpose
The `blur` function applies a box blur effect by averaging the RGB values of a pixel and its neighbors.

### Code
```c
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
```

### Detailed Explanation
1. **Input:** The function takes the image height and width along with a 2D array representing the image's pixels.

2. **Step 1: Copy the Image**
   - The original image is copied to a temporary array (`copy`) to preserve original values while calculations are performed. This avoids altering values prematurely during processing.

3. **Step 2: Iterate Over Each Pixel**
   - For each pixel `(i, j)` in the image:
     - Initialize variables to accumulate the sum of RGB values (`r`, `g`, `b`) and a counter (`count`) to track how many pixels contribute to the average.

4. **Step 3: Consider Neighboring Pixels**
   - A nested loop checks the surrounding 3x3 grid of pixels around `(i, j)`. This includes diagonally adjacent pixels, accounting for edge and corner cases where neighbors might fall outside the image bounds.

5. **Step 4: Compute Averages**
   - Calculate the average for each color channel by dividing the sum of the values by the `count` of contributing pixels.

6. **Step 5: Update Original Image**
   - Assign the averaged values back to the original image, creating a blurred effect.

7. **Output:** The image is updated with a smoothed version, reducing sharp transitions between pixels.

---

## Edge Detection
#### [Detailed](https://github.com/mosaabdo/local_cs50/blob/main/cs50_submit/week4/md/func_edg_fil_more.md)

### Purpose
The `edges` function applies the Sobel operator to detect edges in an image. It computes gradients in the horizontal and vertical directions to identify regions of rapid intensity change.

### Code
```c
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

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
            int rgx = 0, ggx = 0, bgx = 0;
            int rgy = 0, ggy = 0, bgy = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di, nj = j + dj;

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

            int G_red = round(sqrt((rgx * rgx) + (rgy * rgy)));
            int G_green = round(sqrt((ggx * ggx) + (ggy * ggy)));
            int G_blue = round(sqrt((bgx * bgx) + (bgy * bgy)));

            G_red = (G_red > 255) ? 255 : G_red;
            G_green = (G_green > 255) ? 255 : G_green;
            G_blue = (G_blue > 255) ? 255 : G_blue;

            image[i][j].rgbtRed = G_red;
            image[i][j].rgbtGreen = G_green;
            image[i][j].rgbtBlue = G_blue;
        }
    }

    return;
}
```

### Detailed Explanation
1. **Input:** The function processes a 2D array of image pixels using the Sobel operator.

2. **Step 1: Copy the Image**
   - A duplicate (`copy`) of the image is created to retain original values during processing.

3. **Step 2: Define Sobel Kernels**
   - Two convolution matrices `gx` and `gy` represent horizontal and vertical gradients, respectively. These are applied to the image.

4. **Step 3: Compute Gradients**
   - For each pixel `(i, j)`:
     - Apply `gx` and `gy` to the surrounding 3x3 grid of pixels to compute horizontal and vertical gradients for each color channel.

5. **Step 4: Calculate Gradient Magnitude**
   - Combine the gradients using the formula:
     \[ G = \sqrt{Gx^2 + Gy^2} \]
   - Clamp the result to a maximum of 255 to ensure valid color intensity.

6. **Step 5: Update Original Image**
   - Replace the pixel values with the computed gradients, emphasizing edges in the image.

7. **Output:** The processed image highlights regions with significant intensity changes, revealing edges.

