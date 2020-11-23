#include "IntArray.h"
#include <iostream>

IntArray::IntArray(unsigned int newSize) {
	if (newSize == 0)
	{
		std::cerr << "���������� ������� ������ 0 �������" << std::endl;
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
		std::cerr << "��������� �� ��������������� ������� "<< index <<" ��� ������� ������� "<< size << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return numbers[index];
}