#pragma once
#include "imageio.h"
#include "vec3.h"
#include"ppm.h"
#include "array2d.h"
#include <iostream>
#include <string>
#include "array2d.h"
using namespace std;
using namespace math;
using namespace image;


typedef Vec3<float> Color; // alias for math::Vec3<float> -> Color


namespace image
{
	class Image : public ImageIO, public Array2D<Color> {
	public:

		Image();
		Image(unsigned int width, unsigned int height, const Color * data_ptr);
		Image(const Image &src); 
		~Image(); 

		void setColor(unsigned x, unsigned y, Color val) { Array2D::setItem(x, y, val); }
		

		bool ImageIO::load(const std::string & filename, const std::string & format) {

			int length = filename.length();
			if (filename.substr(length - 3, length - 1) != format) {
				cout << "We accept ppm files only!" << endl;
				return false;
			}

			int widt;
			int heig;
			float * array = ReadPPM(filename.c_str(), &widt, &heig);
			if (array != nullptr)
			{
				width = widt;
				height = heig;
				buffer.resize(widt*heig);

				for (int i = 0; i < widt*heig; i++) {
					buffer[i] = Color(array[3 * i], array[3 * i + 1], array[3 * i + 2]);
				}

				delete[]array;

				return true;

			}
			return false;
		}


		bool ImageIO::save(const std::string & filename, const std::string & format) {

			int length = filename.length();

			if (filename.substr(length - 3, length - 1) != format) {
				cout << "We accept ppm files only!" << endl;

				return false;
			}

			if (buffer.empty())
			{
				cout << "The image is not initialized !"<<endl;

				return false;
			}

			float * newArray = new float[width * height * 3];

			unsigned int bar = 0;

			for (unsigned int i = 0; i < width * height; i++)
			{
				bar = 3 * i;
				newArray[bar] = buffer[i].r;
				newArray[bar + 1] = buffer[i].g;
				newArray[bar + 2] = buffer[i].b;

			}

			bool savedImage = WritePPM(newArray, width, height, filename.c_str());

			delete[]newArray;

			if (savedImage)
			{
				cout << "The image was saved!" << endl;

				return true;
			}
			else {
				cout << " The image was not saved!" << endl;

				return false;
			}
		}




		


	};

}

