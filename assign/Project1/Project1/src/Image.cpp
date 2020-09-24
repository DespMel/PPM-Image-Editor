#include "imageio.h"
#include "vec3.h"
#include"ppm.h"
#include "array2d.h"
#include <iostream>
#include <string>
#include "Image.h"
using namespace std;
using namespace math;
using namespace image;

#ifndef _IMAGE
#define _IMAGE

typedef Vec3<float> Color; // alias for math::Vec3<float> -> Color



namespace image {

	//default
	Image::Image() :Array2D(0,0,0) {
	}


	//constructor me orismata
	Image::Image(unsigned int width, unsigned int height, const Color * data_ptr) : Array2D(width, height, data_ptr) {

	}

	//copy constructor
	Image::Image(const Image & src) : Array2D(src) {

	}

	Image::~Image(){

	}


}

#endif

