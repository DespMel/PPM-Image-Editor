#include <iostream>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include <string>
#include <cstdio>
using namespace std;
namespace image {


	float * ReadPPM(const char * filename, int * w, int * h) {

		float * array_data; //a pointer to a newly allocated float array containing the image data.
		
		string header; // the header of the image 
		unsigned int height;
		unsigned int width;
		unsigned int RGB;


		ifstream image_input; // the image that we load 
		image_input.open(filename, std::ios::binary);
		

		if (image_input.good())
		{
			// >> overload operator , we load
			image_input >> header;
			image_input >> width;
			image_input >> height;
			image_input >> RGB;
			image_input.get();
	
		
			// we want p6 format , so we check it first
			if (strcmp(header.c_str(), "P6") != 0) {
				cout << " The format is not P6, we only support P6 format!"<<endl;

				return nullptr;
			}

			cout <<"We are loading image " << filename << endl;
			cout << "The dimensions of the image are: " << " Width: " << width << ", Height : " << height << endl;

			// we have to check if the RGB is over 255, because we only support 24bit images, values until 255 only.
			if (RGB > 255) {
				cout << "Only 24bit images are supported!"<<endl;

				return nullptr;
			}

			array_data = new float[3 * width*height]; // pointer to a new float array of 3 X w X h floats, that contains the image data.
			unsigned char var;
			// we store one byte for each color
			for (unsigned int i = 0; i < width*height; i++)
			{
				image_input.read((char*)&var, sizeof(unsigned char));
				array_data[3 * i] = var / 255.0f;
				image_input.read((char*)&var, sizeof(unsigned char));
				array_data[3 * i + 1] = var / 255.0f;
				image_input.read((char*)&var, sizeof(unsigned char));
				array_data[3 * i + 2] = var / 255.0f;
			}

			*w = width;
			*h = height;

			image_input.close();

			return array_data;
		}
		else
		{
			cout << " The image could not be loaded ! "<<endl;

			return nullptr;
		}
	}


	bool WritePPM(const float * data, int w, int h, const char * filename) {
		// we check if the image is empty
		if (w == 0 || h == 0 || data == nullptr) {
			cout << "The image is empty !"<<endl;

			return false;
		}


		ofstream image_file = ofstream(filename, ios_base::out | ios_base::binary);

		if (image_file.good() == true)
		{
			// we write the values of the header 
			image_file << "P6" << endl;
			image_file << w << endl;
			image_file << h << endl;
			image_file << 255 << endl; 


			//Assign values
			unsigned char foo;
			for (int i = 0; i < w*h; i++)
			{
				foo = data[3 * i] * 255.0f;
				image_file.write((char*)&foo, sizeof(unsigned char));
				foo = data[3 * i + 1] * 255.0f;
				image_file.write((char*)&foo, sizeof(unsigned char));
				foo = data[3 * i + 2] * 255.0f;
				image_file.write((char*)&foo, sizeof(unsigned char));
			}
			image_file.close();

			return true;
		}
		else
		{
			cout << "The image could not be opened ! "<<endl;

			return false;
		}
	}
}





