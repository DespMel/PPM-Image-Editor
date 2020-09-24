#pragma once
#include <iostream>
#include <cmath>
#include "imageio.h"
#include "vec3.h"
#include "Image.h"

using namespace math;

class Filter
{

public:

	virtual Image operator << (const Image& image) = 0; //pure virtual method
	virtual ~Filter(){}
	


};

typedef Vec3<float> Color;

class FilterLinear : public Filter
{
protected:
	Color a, c;
public:

	FilterLinear(Color a, Color c); // constructor

	FilterLinear(); //default constructor

	FilterLinear(const Color& src); //copy constructor

	Image operator << (const Image& image); 
};

class FilterGamma : public Filter
{
protected:
	float pw;

public:

	FilterGamma(float p); //constructor

	FilterGamma(); //default constructor

	Image operator << (const Image& image); 
};



