#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	int avg = 0;
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
			image[i][j].rgbtBlue = avg;
			image[i][j].rgbtGreen = avg;
			image[i][j].rgbtRed = avg;
		}
	}
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
	int sepiaRed, sepiaGreen, sepiaBlue;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
			sepiaGreen =.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
			sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

			image[i][j].rgbtBlue = sepiaBlue > 255 ? (image[i][j].rgbtBlue = 255) : (image[i][j].rgbtBlue = sepiaBlue); 
			image[i][j].rgbtGreen = sepiaGreen > 255 ? (image[i][j].rgbtGreen = 255) : (image[i][j].rgbtGreen = sepiaGreen); 
			image[i][j].rgbtRed = sepiaRed > 255 ? (image[i][j].rgbtRed = 255) : (image[i][j].rgbtRed = sepiaRed); 
		}
	}
	return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE temp;
	int nw = width / 2;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < nw; j++)
		{
			temp.rgbtBlue = image[i][j].rgbtBlue;
			temp.rgbtGreen = image[i][j].rgbtGreen;
			temp.rgbtRed = image[i][j].rgbtRed;

			image[i][j].rgbtBlue = image[i][width - j].rgbtBlue;
			image[i][j].rgbtGreen = image[i][width - j].rgbtGreen;
			image[i][j].rgbtRed = image[i][width - j].rgbtRed;

			image[i][width - j].rgbtBlue = temp.rgbtBlue;
			image[i][width - j].rgbtGreen = temp.rgbtGreen;
			image[i][width - j].rgbtRed = temp.rgbtRed;
		}
	}
	return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	int avg[3];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if(i==0 && j==0)
			{
				avg[0] = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
					image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4;
				
				avg[1] = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
					image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4;

				avg[2] = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
					image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4;
					
				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
			else if(i==0 && j > 0 && j < width)
			{
				avg[0] = (image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
					image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6;
				
				avg[1] = (image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
						image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)
					/ 6;

				avg[2] = (image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
						image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6;

				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
			else if(i==0 && j == width)
			{
				avg[0] = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
					image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4;
				
				avg[1] = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
					image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4;

				avg[2] = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
					image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4;
					
				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
			else if(i > 0 && j == 0 && i < height)
			{
				avg[0] = (image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
						image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + 
						image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6;

				avg[1] = (image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
							image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + 
							image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6;

				avg[2] = (image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
						image[i][j].rgbtRed + image[i][j + 1].rgbtRed + 
						image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6;

				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
			else if(i > 0 && i < height && j > 0 && j < width)
			{
				avg[0] = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue +
					image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
					image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i -1][j - 1].rgbtBlue) / 9;

				avg[1] = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen +
					image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
					image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i -1][j - 1].rgbtGreen) / 9;

				avg[2] = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed +
					image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
					image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i -1][j - 1].rgbtRed) / 9;

				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
			else if(i > 0 && j == width && i < height)
			{

				avg[0] = (image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
						image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + 
						image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6;

				avg[1] = (image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
							image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + 
							image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6;

				avg[2] = (image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed +
						image[i][j].rgbtRed + image[i][j - 1].rgbtRed + 
						image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6;

				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
			else if(i == height && j == 0)
			{

				avg[0] = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
					image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 4;
				
				avg[1] = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
					image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4;

				avg[2] = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
					image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4;
					
				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
			else if(i == height && j > 0 && j < width)
			{

				avg[0] = (image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
						image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6;
				
				avg[1] = (image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
						image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen)
					/ 6;

				avg[2] = (image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
						image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6;

				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
			else if(i == height && j == width)
			{
				avg[0] = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
					image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4;
				
				avg[1] = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
					image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4;

				avg[2] = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
					image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4;
					
				image[i][j].rgbtBlue = avg[0];
				image[i][j].rgbtGreen = avg[1];
				image[i][j].rgbtRed = avg[2];
			}
		}
	}
	return;
}
