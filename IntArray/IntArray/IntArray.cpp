#include "IntArray.h"
#include <iostream>

IntArray::IntArray(unsigned int newSize) {
	if (newSize == 0)
	{
		std::cerr << "Ќевозможно создать массив 0 размера" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	numbers = new int[newSize];
	size = newSize;
}
IntArray::~IntArray(void)
{ 
	delete[] numbers;
}

int& IntArray::operator[](unsigned int index) {
	if (index >= size)
	{
		std::cerr << "ќбращение по несуществующему индексу "<< index <<" при размере массива "<< size << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return numbers[index];
}