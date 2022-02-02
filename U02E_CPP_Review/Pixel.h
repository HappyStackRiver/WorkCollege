#ifndef _PIXEL_H
#define _PIXEL_H

// TODO: Create Pixel struct
struct Pixel
{
	int r;
	int g;
	int b;

	Pixel()
	{
		r = 0;
		g = 0;
		b = 0;
	}

	Pixel(int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}

};
#endif
