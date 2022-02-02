#ifndef _IMAGE_H
#define _IMAGE_H

#include <string>
using namespace std;

#include "Pixel.h"

class PpmImage
{
	public:
		PpmImage(); //default const
		PpmImage(int colorDepth, int width, int height); //parameter const
		~PpmImage(); //destructor
		
		void setup(int colorDepth, int width, int height);
		int getTotalPixels() const;

		bool loadImage(const string& filename);
		bool saveImage(const string& filename);

		void setPixel(int x, int y, int r, int g, int b);

		
		void fillAll(int r, int g, int b);
		int getIndexOfPixelAt(int x, int y);

		void applyFilter1();
		void applyFilter2();


	private:
		Pixel* m_pixels;
		int arraySize;
		int width;
		int height;
		int colorDepth;

		void allocateMemory(int size);
		void deallocateMemory();
};


#endif
