/*
3120121 HLIAS MPECHLIS
3140116 DESPOINA MELAKI

*/


#include <iostream>
#include <string>
#include <sstream>
#include "imageio.h"
#include "vec3.h"
#include "Filter.h"
#include "ppm.h"
#include "array2d.h"
#include "array2d.hpp"
#include "Image.h"
#include <iterator>

using namespace std;
using namespace image;
using namespace math;


void Filters(Image image, string filename);

typedef Vec3<float> Color;

int main(int argc, char **argv)
{
	string filename;

	Image image1;

	Filters(image1, filename);

	system("pause");

	return 0;
}

void Filters(Image im, string filename)
{
	cout << " Give me the input e.g: filter -f linear 2 2 2 0 0 0 Image01.ppm" << endl;
	string input;

	string pow, aR, aG, aB, cR, cG, cB;

	std::getline(std::cin, input);

	vector<string> input_array;
	istringstream iss(input);
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(input_array));


	int size_array = input_array.size();
	input = input_array[size_array - 1];
	filename = input;

	bool load = im.load(filename, "ppm");
	if (!load) {
		return;
	}

	int i = 0;
	if (input_array[i] == (string)("filter")) {

		i++;
		while (i < size_array - 1) {
			if (input_array[i] == (string)("-f")) {
				i++;
				if (input_array[i] == (string)("gamma"))
				{
					cout << "We put filter gamma!" << endl;
					i++;
					pow = input_array[i];
					float p = stof(pow);
					FilterGamma gamma(p);
					im = gamma << im;
				}

				else if (input_array[i] == (string)("linear"))
				{
					cout << "We put filter linear!" << endl;
					i++;
					aR = input_array[i];
					i++;
					aG = input_array[i];
					i++;
					aB = input_array[i];
					i++;
					cR = input_array[i];
					i++;
					cG = input_array[i];
					i++;
					cB = input_array[i];



					Color a(stof(aR), stof(aG), stof(aB)); // klisi constructor
					Color c(stof(cR), stof(cG), stof(cB));

					FilterLinear linear(a, c);
					im = linear << im;
				}
				else {
					cout << "You did not give the correct filter name!" << endl;
				}
			}
			else {
				cout << "You did not give the '-f' parameter" << endl;
			}
			i++;

		}


	}
	else {
		cout << "You did not give filter, the program terminated!" << endl;
		return;
	}

	im.save("filtered_" + filename, "ppm");


}





