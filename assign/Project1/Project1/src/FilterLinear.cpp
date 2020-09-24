#include <iostream>
#include "Filter.h"
#include "imageio.h"
#include "vec3.h"
#include "Image.h"

using namespace math;
using namespace image;

typedef Vec3<float> Color;

FilterLinear::FilterLinear(Color aV, Color cV)
{

	a.r = aV.r;
	a.g = aV.g;
	a.b = aV.b;
	c.r = cV.r;
	c.g = cV.g;
	c.b = cV.b;

}

FilterLinear::FilterLinear()
{
	a.r = 0.0f;
	a.g = 0.0f;
	a.b = 0.0f;
	c.r = 0.0f;
	c.g = 0.0f;
	c.b = 0.0f;
}

FilterLinear::FilterLinear(const Color& src)
{
	a.r = src.r;
	a.g = src.g;
	a.b = src.b;

	c.r = src.r;
	c.g = src.g;
	c.b = src.b;
}

Image FilterLinear::operator<<(const Image & image)
{


	unsigned int width = image.getWidth();
	unsigned int height = image.getHeight();
	
	Image fimage = image;

	if (height > 0 && width > 0)
	{
		for (unsigned int i = 0; i < width; i++) {

			for (unsigned int j = 0; j < height; j++) {
				Color imageItem = fimage(i, j);
				imageItem = imageItem * a + c;
				for (unsigned int k = 0; k < 3; k++)
				{
					if (imageItem[k] > 1)
					{
						imageItem[k] = 1;
						
					}
					else if (imageItem[k] < 0)
					{
						imageItem[k] = 0;
						

					}
					
				}


				fimage.setColor(i, j, imageItem);

			}
		}

	}

	return fimage;


}
