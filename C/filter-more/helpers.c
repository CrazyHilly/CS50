#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

RGBTRIPLE get_average(RGBTRIPLE pixel[], int number);
RGBTRIPLE get_weighted_sum(RGBTRIPLE pixels[], int size);
int calculate_total(int x, int y);
int fix_overflow(int n);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            BYTE gray = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
            pixel.rgbtBlue = pixel.rgbtGreen = pixel.rgbtRed = gray;

            image[i][j] = pixel;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    if (width == 1)
    {
        return;
    }

    for (int i = 0; i < height; i++)
    {
        float half_length = (width - 1) / 2.0;
        for (int j = 0; j < half_length; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copying image to temp
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Bluring neighbouring pixels depending on their position
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Creating variables from neighbouring 3x3 pixels
            RGBTRIPLE top_left, top_middle, top_right, left, middle, right, bottom_left, bottom_middle, bottom_right;
            int pixels_amount;

            top_left = temp[i - 1][j - 1];
            top_middle = temp[i - 1][j];
            top_right = temp[i - 1][j + 1];

            left = temp[i][j - 1];
            middle = temp[i][j];
            right = temp[i][j + 1];

            bottom_left = temp[i + 1][j - 1];
            bottom_middle = temp[i + 1][j];
            bottom_right = temp[i + 1][j + 1];

            // Go through the first row of the image
            if (i == 0)
            {
                // Corners
                pixels_amount = 4;

                // Left corner
                if (j == 0)
                {
                    RGBTRIPLE corner_pixels[] = {middle, right, bottom_middle, bottom_right};
                    image[i][j] = get_average(corner_pixels, pixels_amount);
                    continue;
                }

                // Right corner
                if (j == (width - 1))
                {
                    RGBTRIPLE corner_pixels[] = {middle, left, bottom_middle, bottom_left};
                    image[i][j] = get_average(corner_pixels, pixels_amount);
                    continue;
                }

                // Middle edge
                pixels_amount = 6;
                RGBTRIPLE edge_pixels[] = {left, middle, right, bottom_left, bottom_middle, bottom_right};
                image[i][j] = get_average(edge_pixels, pixels_amount);
                continue;
            }

            // Go through the last row of the image
            if (i == (height - 1))
            {
                // Corners
                pixels_amount = 4;

                // Left corner
                if (j == 0)
                {
                    RGBTRIPLE corner_pixels[] = {middle, right, top_middle, top_right};
                    image[i][j] = get_average(corner_pixels, pixels_amount);
                    continue;
                }

                // Right corner
                if (j == (width - 1))
                {
                    RGBTRIPLE corner_pixels[] = {middle, left, top_middle, top_left};
                    image[i][j] = get_average(corner_pixels, pixels_amount);
                    continue;
                }

                // Middle edge
                pixels_amount = 6;
                RGBTRIPLE edge_pixels[] = {left, middle, right, top_left, top_middle, top_right};
                image[i][j] = get_average(edge_pixels, pixels_amount);
                continue;
            }

            // Go through the middle rows of the image
            pixels_amount = 6;

            // Left edge
            if (j == 0)
            {
                RGBTRIPLE edge_pixels[] = {middle, right, top_middle, top_right, bottom_middle, bottom_right};
                image[i][j] = get_average(edge_pixels, pixels_amount);
                continue;
            }

            // Right edge
            if (j == (width - 1))
            {
                RGBTRIPLE edge_pixels[] = {middle, left, top_middle, top_left, bottom_middle, bottom_left};
                image[i][j] = get_average(edge_pixels, pixels_amount);
                continue;
            }

            // Middle
            pixels_amount = 9;
            RGBTRIPLE middle_pixels[] = {top_left, top_middle, top_right, left, middle, right, bottom_left, bottom_middle, bottom_right};
            image[i][j] = get_average(middle_pixels, pixels_amount);
        }
    }
}

RGBTRIPLE get_average(RGBTRIPLE pixels[], int n)
{
    RGBTRIPLE average;
    float sum_blue = 0;
    float sum_green = 0;
    float sum_red = 0;

    for (int i = 0; i < n; i++)
    {
        sum_blue += pixels[i].rgbtBlue;
        sum_green += pixels[i].rgbtGreen;
        sum_red += pixels[i].rgbtRed;
    }

    average.rgbtBlue = round(sum_blue / n);
    average.rgbtGreen = round(sum_green / n);
    average.rgbtRed = round(sum_red / n);

    return average;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copying image to temp
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE top_left, top_middle, top_right, left, middle, right, bottom_left, bottom_middle, bottom_right, black;
            int matrix_size = 9;

            black.rgbtBlue = 0;
            black.rgbtGreen = 0;
            black.rgbtRed = 0;

            top_left = temp[i - 1][j - 1];
            top_middle = temp[i - 1][j];
            top_right = temp[i - 1][j + 1];

            left = temp[i][j - 1];
            middle = temp[i][j];
            right = temp[i][j + 1];

            bottom_left = temp[i + 1][j - 1];
            bottom_middle = temp[i + 1][j];
            bottom_right = temp[i + 1][j + 1];

            // Go through the first row of the image
            if (i == 0)
            {
                top_left = black;
                top_middle = black;
                top_right = black;

                // Left corner
                if (j == 0)
                {
                    left = black;
                    bottom_left = black;
                }

                // Right corner
                if (j == (width - 1))
                {
                    right = black;
                    bottom_right = black;
                }

                // Middle edge
                RGBTRIPLE pixel_matrix[] = {top_left, top_middle, top_right, left, middle, right, bottom_left, bottom_middle, bottom_right};
                image[i][j] = get_weighted_sum(pixel_matrix, matrix_size);
                continue;
            }

            // Go through the last row of the image
            if (i == (height - 1))
            {
                bottom_left = black;
                bottom_middle = black;
                bottom_right = black;

                // Left corner
                if (j == 0)
                {
                    top_left = black;
                    left = black;
                }

                // Right corner
                if (j == (width - 1))
                {
                    top_right = black;
                    right = black;
                }

                // Middle edge
                RGBTRIPLE pixel_matrix[] = {top_left, top_middle, top_right, left, middle, right, bottom_left, bottom_middle, bottom_right};
                image[i][j] = get_weighted_sum(pixel_matrix, matrix_size);
                continue;
            }

            // Go through the middle rows of the image
            // Left edge
            if (j == 0)
            {
                top_left = black;
                left = black;
                bottom_left = black;
            }

            // Right edge
            if (j == (width - 1))
            {
                top_right = black;
                right = black;
                bottom_right = black;
            }

            // Middle
            RGBTRIPLE pixel_matrix[] = {top_left, top_middle, top_right, left, middle, right, bottom_left, bottom_middle, bottom_right};
            image[i][j] = get_weighted_sum(pixel_matrix, matrix_size);
        }
    }
}

RGBTRIPLE get_weighted_sum(RGBTRIPLE pixels[], int size)
{
    RGBTRIPLE result = pixels[4];

    // Creating horizontal X and vertical Y convolutional matrices as arrays
    int X[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Y[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    typedef struct
    {
        int blue;
        int green;
        int red;
    }
    SUM;
    SUM Xsum, Ysum, total;

    Xsum.blue = 0;
    Xsum.green = 0;
    Xsum.red = 0;

    Ysum.blue = 0;
    Ysum.green = 0;
    Ysum.red = 0;

    // Calculating weighted sum of surrounding pixels
    for (int i = 0; i < size; i++)
    {
        Xsum.blue += pixels[i].rgbtBlue * X[i];
        Xsum.green += pixels[i].rgbtGreen * X[i];
        Xsum.red += pixels[i].rgbtRed * X[i];

        Ysum.blue += pixels[i].rgbtBlue * Y[i];
        Ysum.green += pixels[i].rgbtGreen * Y[i];
        Ysum.red += pixels[i].rgbtRed * Y[i];
    }

    // Ending function if edges are not found
    if
    (
        (abs(Xsum.blue) < 100) && (abs(Xsum.green) < 100) && (abs(Xsum.red) < 100)
        &&
        (abs(Ysum.blue) < 100) && (abs(Ysum.green) < 100) && (abs(Ysum.red) < 100)
    )
    {
        return result;
    }

    // Getting total values for found edges
    total.blue = calculate_total(Xsum.blue, Ysum.blue);
    total.green = calculate_total(Xsum.green, Ysum.green);
    total.red = calculate_total(Xsum.red, Ysum.red);

    // Fixing channel values oveflow
    result.rgbtBlue = fix_overflow(total.blue);
    result.rgbtGreen = fix_overflow(total.green);
    result.rgbtRed = fix_overflow(total.red);

    return result;
}

int calculate_total(int x, int y)
{
    int total = round(sqrt(x * x + y * y));

    return total;
}

int fix_overflow(int value)
{
    if (value < 0)
    {
        value = 0;
    }
    else if (value > 255)
    {
        value = 255;
    }

    return value;
}