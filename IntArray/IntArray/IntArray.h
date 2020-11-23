#pragma once
#include <iostream>

class IntArray {
	private:
		unsigned int size;
		int* numbers;
	public:
		IntArray(void) = delete;
		IntArray(const IntArray& object) = delete;
		~IntArray(void);
		IntArray(unsigned int newSize);
		int& operator[](unsigned int index);
};