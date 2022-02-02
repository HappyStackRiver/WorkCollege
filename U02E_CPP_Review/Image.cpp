#include "Image.h"

#include <fstream>
#include <iostream>
using namespace std;

PpmImage::PpmImage()
{
	m_pixels = nullptr;
	setup(255, 10, 10);
}

PpmImage::PpmImage(int colorDepthInput, int widthInput, int heightInput)
{
	m_pixels = nullptr;
	setup(colorDepth, width, height);
}

PpmImage::~PpmImage()
{

}

void PpmImage::setup(int colorDepthInput, int widthInput, int heightInput)
{
	colorDepth = colorDepthInput;
	width = widthInput;
	height = heightInput;
	allocateMemory(getTotalPixels());
}

int PpmImage::getIndexOfPixelAt(int x, int y)
{
	return (y * width) + x;
}

void PpmImage::fillAll(int r, int g, int b)
{
	for (size_t i = 0; i < arraySize; i++)
	{
		m_pixels[i].r = r;
		m_pixels[i].g = g;
		m_pixels[i].b = b;
	}
}

void PpmImage::setPixel(int x, int y, int r, int g, int b)
{
	int index = getIndexOfPixelAt(x, y);
	m_pixels[index].r = r;
	m_pixels[index].g = g;
	m_pixels[index].b = b;

}

bool PpmImage::saveImage(const string& filename)
{
	ofstream output(filename);

	if (output.fail())
	{
		cout << "Error:Could not open file!" << endl;
		return false;
	}

	output << "P3" << endl;
	output << "# Comment" << endl;
	output << width << " ";
	output << colorDepth << endl;

	for (size_t i = 0; i < arraySize; i++)
	{
		output << m_pixels[i].r << endl;
		output << m_pixels[i].g << endl;
		output << m_pixels[i].b << endl;

	}
}

bool PpmImage::loadImage(const string& filename)
{
	ifstream input(filename);
	if (input.fail())
	{
		cout << "Error: Cannot open File!" << endl;
		return false;
	}

	string strBuffer;
	input >> strBuffer;
	input.ignore();
	getline(input, strBuffer);
	input >> width;
	input >> height;
	input >> colorDepth;

	deallocateMemory();
	allocateMemory(getTotalPixels());

	for (size_t i = 0; i < arraySize; i++)
	{
		input >> m_pixels[i].r;
		input >> m_pixels[i].g;
		input >> m_pixels[i].b;
	}
	return true;
}

void PpmImage::applyFilter1()
{
	for (size_t i = 0; i < arraySize; i++)
	{
		int r = m_pixels[i].r;
		int g = m_pixels[i].g;
		int b = m_pixels[i].b;

		m_pixels[i].r = g;
		m_pixels[i].g = b;
		m_pixels[i].b = r;
	}
}

void PpmImage::applyFilter2()
{
	for (size_t i = 0; i < arraySize; i++)
	{
		int r = m_pixels[i].r;
		int g = m_pixels[i].g;
		int b = m_pixels[i].b;

		m_pixels[i].r = r - 10;
		m_pixels[i].g = b - 10;
		m_pixels[i].b = r - 10;
	}
}

void PpmImage::allocateMemory(int sizeInput)
{
	if (m_pixels != nullptr)
	{
		cout << "Error: Memory Already Allocated!" << endl;
	}

	m_pixels = new Pixel[sizeInput];
	arraySize = sizeInput;

}

void PpmImage::deallocateMemory()
{
	if (m_pixels != nullptr)
	{
		delete[] m_pixels;
		m_pixels = nullptr;
	}
}

int PpmImage::getTotalPixels() const
{
	return width * height;
}