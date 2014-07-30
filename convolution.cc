#include "convolution.h"
#include "iostream"

void Convolution::convolution()
{
	//pixels : image data matrix
	//dim : kernel matrix dimention -  - for a 3X3 kernel k_dim will be 3
	//kernel : kernel matrix
	//kdim : image dimention - for a 512X512 image dim will be 512
	// These are members of Convolution class
	//You can use them in your algorithm
	
	//open kernel file
	ifstream kernelF ("kernel.txt");
	
	//copy data from kernel file into kernel array
	string data;
	if (kernelF.is_open())
	{
		int i = 0;
		while ( getline (kernelF, data))
		{
			//convert sting to float
			float kValue = atof(data.c_str());
			
			//initialize array
			kernel[i] = kValue;
			i++;
		}
		kernelF.close();
	}
	
	//calculate convolution data
	//for each row in image
	for (int l = 0; l < dim; l++){
		//for each element in row of image
		for (int z = 0; z <dim; z++){
			int sum = 0;
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
				sum += pixels[(l)*dim + (z)] * kernel[i *k_dim + j];		
				}
			}
			//for each row in kernel
			pixels[l*dim + z] = sum;
		}
		
	}
}


void Convolution::calculateConvolution(char * inputFile, char * outputFile)
{
	readImage(inputFile, outputFile);

	convolution();

	writeImage();
}
