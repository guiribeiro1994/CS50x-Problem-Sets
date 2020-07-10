/* A function that takes a bitmap image, its height, and its width values, and
applies a blur filter effect. */
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // Temporary array to store blurred values
    RGBTRIPLE tempArr[height][width];

    // Variables to hold color values
    float blue, green, red;

    // Loops through height <-- Note: for some reason the image gets processed from bottom left to top right.
    for (int i = 0; i < height; i++)
    {

        // Loops through width
        for (int j = 0; j < width; j++)
        {

            // Top Left
            if (i == height - 1 && j == 0)
            {

                // Red values
                red = (image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                       image[i][j].rgbtRed + image[i][j + 1].rgbtRed) / 4.00;

                // Green values
                green = (image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                        image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen) / 4.00;

                // Blue values
                blue = (image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                        image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue) / 4.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }

            // Top Edge
            if (i == height - 1 && j > 0 && j < width - 1)
            {

                // Red values
                red = (image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                       image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed +
                       image[i][j].rgbtRed + image[i][j + 1].rgbtRed) / 6.00;

                // Green values
                green = (image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                         image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen +
                         image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.00;

                // Blue values
                blue = (image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                        image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                        image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }

            // Top Right
            if (i == height - 1 && j == width - 1)
            {

                // Red values
                red = (image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                       image[i][j - 1].rgbtRed + image[i][j].rgbtRed) / 4.00;

                // Green values
                green = (image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                         image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen) / 4.00;

                // Blue values
                blue = (image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                        image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue) / 4.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }

            // Left Edge
            if (i > 0 && i < height - 1 && j == 0)
            {

                // Red values
                red = (image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                       image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                       image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.00;

                // Green values
                green = (image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                         image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                         image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.00;

                // Blue values
                blue = (image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                        image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                        image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }

            // Middle
            if ((i > 0 && i < height - 1) && (j > 0 && j < width - 1))
            {

                // Red values
                red = (image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                       image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed +
                       image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                       image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed +
                       image[i + 1][j + 1].rgbtRed) / 9.00;

                // Green values
                green = (image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                         image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen +
                         image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                         image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen +
                         image[i + 1][j + 1].rgbtGreen) / 9.00;

                // Blue values
                blue = (image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                        image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue +
                        image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                        image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue +
                        image[i + 1][j + 1].rgbtBlue) / 9.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }

            // Right Edge
            if (i > 0 && i < height - 1 && j == width - 1)
            {

                // Red values
                red = (image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed +
                       image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                       image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 6.00;

                // Green values
                green = (image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                         image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen +
                         image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6.00;

                // Blue values
                blue = (image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                        image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue +
                        image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }

            // Bottom Left
            if (i == 0 && j == 0)
            {

                // Red values
                red = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                       image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.00;

                // Green values
                green = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                         image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.00;

                // Blue values
                blue = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                        image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }

            // Bottom Edge
            if (i == 0 && j > 0 && j < width - 1)
            {

                // Red values
                red = (image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                       image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                       image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.00;

                // Green values
                green = (image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen +
                         image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                         image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.00;

                // Blue values
                blue = (image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue +
                        image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                        image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }

            // Bottom Right
            if (i == 0 && j == width - 1)
            {

                // Red values
                red = (image[i][j - 1].rgbtRed + image[i][j].rgbtRed +
                       image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 4.00;

                // Green values
                green = (image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen +
                         image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 4.00;

                // Blue values
                blue = (image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue +
                        image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 4.00;

                // Assigns values
                tempArr[i][j].rgbtBlue = round(blue);
                tempArr[i][j].rgbtGreen = round(green);
                tempArr[i][j].rgbtRed = round(red);
                continue;
            }
        }
    }

    // Replaces image values with tempArr values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempArr[i][j];
        }
    }

    return;
}
