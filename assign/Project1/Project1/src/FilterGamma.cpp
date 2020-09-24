#include <iostream>
#include "Filter.h"
#include "imageio.h"
#include "vec3.h"
#include "Image.h"

using namespace math;
using namespace image;

typedef Vec3<float> Color;

FilterGamma::FilterGamma() {
	pw = 0.5f;
	
}

FilterGamma::FilterGamma(float p)
{
	if (p >= 0.5 && p <= 2.0) //values for ã between 0.5 and 2.0
		pw = p;
	else
	{
		if (pw < 0.5f)
			pw = 0.5f;
		else if (pw > 2.0f)
			pw = 2.0f;
	}


	
	

}


Image FilterGamma::operator << (const Image & image)
{

	Image fimage = image;
	
	
	for (unsigned int j = 0; j < image.getHeight(); j++)
	{
		for (unsigned int i = 0; i < image.getWidth(); i++)
		{
		Color imageItem = fimage(i, j);
		
			imageItem.r = pow(imageItem.r, pw);
			imageItem.g = pow(imageItem.g, pw);
			imageItem.b = pow(imageItem.b, pw);

			
			fimage.setColor(i, j, imageItem);
		}
	}
	
	

	return fimage;
	
}

