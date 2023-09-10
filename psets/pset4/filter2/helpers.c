#include "helpers.h"
#include<math.h>

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE temp[height][width];
	int gx[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
	int gy[3][3] = {{-1,-2,-1}, {0,0,0}, {1,2,1}};
	double gxb, gxg, gxr, gyb, gyg, gyr;
	int sum[3];
	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			temp[x][y] = image[x][y];
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if(i==0 && j==0)
			{
				gxb = gx[0][0] * 0 + gx[0][1] * 0 + gx[0][2] * 0 +  
					gx[1][0] * 0 + gx[1][1] * temp[i][j].rgbtBlue + gx[1][2] * temp[i][j+1].rgbtBlue + 
					gx[2][0] * 0 + gx[2][1] * temp[i+1][j].rgbtBlue + gx[2][2] * temp[i+1][j+1].rgbtBlue;

				gyb = gy[0][0] * 0 + gy[0][1] * 0 + gy[0][2] * 0 + 
					gy[1][0] * 0 + gy[1][1] * temp[i][j].rgbtBlue + gy[1][2] * temp[i][j+1].rgbtBlue + 
					gy[2][0] * 0 + gy[2][1] * temp[i+1][j].rgbtBlue + gy[2][2] * temp[i+1][j+1].rgbtBlue;


				gxg = gx[0][0] * 0 + gx[0][1] * 0 + gx[0][2] * 0 + 
					gx[1][0] * 0 + gx[1][1] * temp[i][j].rgbtGreen + gx[1][2] * temp[i][j+1].rgbtGreen + 
					gx[2][0] * 0 + gx[2][1] * temp[i+1][j].rgbtGreen + gx[2][2] * temp[i+1][j+1].rgbtGreen;

				gyg = gy[0][0] * 0 + gy[0][1] * 0 + gy[0][2] * 0 + 
					gy[1][0] * 0 + gy[1][1] * temp[i][j].rgbtGreen + gy[1][2] * temp[i][j+1].rgbtGreen + 
					gy[2][0] * 0 + gy[2][1] * temp[i+1][j].rgbtGreen + gy[2][2] * temp[i+1][j+1].rgbtGreen;

				gxr = gx[0][0] * 0 + gx[0][1] * 0 + gx[0][2] * 0 + 
					gx[1][0] * 0 + gx[1][1] * temp[i][j].rgbtRed + gx[1][2] * temp[i][j+1].rgbtRed + 
					gx[2][0] * 0 + gx[2][1] * temp[i+1][j].rgbtRed + gx[2][2] * temp[i+1][j+1].rgbtRed;

				gyr = gy[0][0] * 0 + gy[0][1] * 0 + gy[0][2] * 0 + 
					gy[1][0] * 0 + gy[1][1] * temp[i][j].rgbtRed + gy[1][2] * temp[i][j+1].rgbtRed + 
					gy[2][0] * 0 + gy[2][1] * temp[i+1][j].rgbtRed + gy[2][2] * temp[i+1][j+1].rgbtRed;

				image[i][j].rgbtBlue = sqrt(pow(gxb,2) + pow(gyb,2));
				image[i][j].rgbtGreen = sqrt(gxg + gyg);
				image[i][j].rgbtRed = sqrt(gxr + gyr);
 
			}
			else if(i==0 && j > 0 && j < width)
			{

			}
			else if(i==0 && j == width)
			{
				sum[0] = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
					image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4;
				
				sum[1] = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
					image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 4;

				sum[2] = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
					image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4;
					
				image[i][j].rgbtBlue = sum[0];
				image[i][j].rgbtGreen = sum[1];
				image[i][j].rgbtRed = sum[2];
			}
			else if(i > 0 && j == 0 && i < height)
			{
				sum[0] = (image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
						image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + 
						image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6;

				sum[1] = (image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
							image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + 
							image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6;

				sum[2] = (image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
						image[i][j].rgbtRed + image[i][j + 1].rgbtRed + 
						image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6;

				image[i][j].rgbtBlue = sum[0];
				image[i][j].rgbtGreen = sum[1];
				image[i][j].rgbtRed = sum[2];
			}
			else if(i > 0 && i < height && j > 0 && j < width)
			{
				sum[0] = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue +
					image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
					image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i -1][j - 1].rgbtBlue) / 9;

				sum[1] = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen +
					image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
					image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i -1][j - 1].rgbtGreen) / 9;

				sum[2] = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed +
					image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
					image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i -1][j - 1].rgbtRed) / 9;

				image[i][j].rgbtBlue = sum[0];
				image[i][j].rgbtGreen = sum[1];
				image[i][j].rgbtRed = sum[2];
			}
			else if(i > 0 && j == width && i < height)
			{

				sum[0] = (image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
						image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + 
						image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 6;

				sum[1] = (image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
							image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + 
							image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen) / 6;

				sum[2] = (image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed +
						image[i][j].rgbtRed + image[i][j - 1].rgbtRed + 
						image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 6;

				image[i][j].rgbtBlue = sum[0];
				image[i][j].rgbtGreen = sum[1];
				image[i][j].rgbtRed = sum[2];
			}
			else if(i == height && j == 0)
			{

				sum[0] = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
					image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 4;
				
				sum[1] = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
					image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4;

				sum[2] = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
					image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4;
					
				image[i][j].rgbtBlue = sum[0];
				image[i][j].rgbtGreen = sum[1];
				image[i][j].rgbtRed = sum[2];
			}
			else if(i == height && j > 0 && j < width)
			{

				sum[0] = (image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
						image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6;
				
				sum[1] = (image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
						image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen)
					/ 6;

				sum[2] = (image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
						image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6;

				image[i][j].rgbtBlue = sum[0];
				image[i][j].rgbtGreen = sum[1];
				image[i][j].rgbtRed = sum[2];
			}
			else if(i == height && j == width)
			{
				sum[0] = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue +
					image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4;
				
				sum[1] = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen +
					image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4;

				sum[2] = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed +
					image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4;
					
				image[i][j].rgbtBlue = sum[0];
				image[i][j].rgbtGreen = sum[1];
				image[i][j].rgbtRed = sum[2];
			}
		}
	}
    return;
}
