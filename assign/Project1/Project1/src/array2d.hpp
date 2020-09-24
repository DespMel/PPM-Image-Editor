#pragma once
#include "array2d.h"
#include <iostream>
using namespace std;

#ifndef _ARRAY2D_IMPLEMENTATION_
#define _ARRAY2D_IMPLEMENTATION_


namespace math {

	template<typename T>
	const unsigned int Array2D<T>::getWidth() const {

		return width;
	}

	template<typename T>
	const unsigned int Array2D<T>::getHeight() const {

		return height;
	}

	template<typename T>
	T * Array2D<T>::getRawDataPtr() {

		return &buffer[0];
	}

	template<typename T>
	void Array2D<T>::setData(const T * const & data_ptr) {
		if (buffer.size() == data_ptr.size()) {

			for (unsigned int i = 0; i < width*height; i++)
			{
				buffer[i] = data_ptr[i];
			}
		}

	}

	//leitourgei san getItem methodo 
	template<typename T>
	T & Array2D<T>::operator()(unsigned int x, unsigned int y) {

		if (x < width && y < height)
		{
			return buffer[y*width + x]; 
		}
		else {
			return buffer[0];
		}
		
	}


	template<typename T>
	Array2D<T>::Array2D(unsigned int width, unsigned int height, const T * data_ptr) {
		this->width = width;
		this->height = height;
		int sizeOfBuffer = width * height * 3;
		data_ptr = new T[width*height]; 
		

	}

	template<typename T>
	Array2D<T>::Array2D(const Array2D & src) {

		width = src.width;
		height = src.height;
		buffer = src.buffer;
		

		for (unsigned int i = 0; i < width*height; i++)
		{
			buffer[i] = src.buffer[i];
		}
	

	}


	template<typename T>
	Array2D<T>::~Array2D() {
		
	}


	template<typename T> Array2D<T> & Array2D<T>::operator=(const Array2D & right) {

	
		width = right.width;
		height = right.height;

		for (unsigned int i = 0; i < width*height; i++) {
			buffer[i] = right.buffer[i];
		}

		return *this;
	}


	template<typename T>
	void Array2D<T>::setItem(unsigned int x, unsigned int y, T & value)
	{
		if (x >= 0 && x < width && y >= 0 && y < height)
		{
			Array2D<T>::operator()(x, y) = value;
		}
	}




}
#endif




