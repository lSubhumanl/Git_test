#include "matrix.h"
#include <iostream>
#include <cstdlib>

Matrix::Matrix(void)
{
	size = 1;
	numbers = new int[1];
	*numbers = 0;
}

Matrix::Matrix(unsigned int newSize)
{
	unsigned int arraySize = newSize * newSize;
	size = newSize;
	numbers = new int[arraySize];
	for (unsigned int i = 0; i != arraySize; ++i) {
		numbers[i] = 0;
	}
}

Matrix::Matrix(const Matrix& instanceToCopyFrom)
{
	size = instanceToCopyFrom.getSize();
	unsigned int arraySize = size * size;
	numbers = new int[arraySize];
	for (unsigned int i = 0; i != arraySize; ++i) {
		numbers[i] = instanceToCopyFrom.getNumber(i % size, i / size);
	}
}

/* ����� ���� ������� 3*3 �� ���������� ���������:
   0 1 2
   3 4 5
   6 7 8
   ���������, ����� �� ������� ������� ���������� ���������
   ��� ����������� � ������ ������.
   */

   // ����� ���� ����� ������ row, ����� ������ column, ������ ������� size.
   // ����������, ��� ��������� ������ ���������������� �������� � ���������� �������.
   // ������ ������ ����������, ���� �� ���������� ������� 10x10.

Matrix::~Matrix(void)
{
	delete[] numbers;
}

unsigned int Matrix::getSize(void) const
{
	return size;
}

void Matrix::setSize(unsigned int newSize)
{
	size = newSize;
}

int Matrix::getNumber(unsigned int column, unsigned int row) const
{
	if (row < size && column < size)
		return numbers[row * size + column];
}

void Matrix::setNumber(unsigned int column, unsigned int row, int newNumber)
{
	if (row < size && column < size)
		numbers[row * size + column] = newNumber;
}

void Matrix::plusAssign(const Matrix& summand)
{
	if (size == summand.getSize) {
		for (unsigned int i; i < size; ++i)
			numbers[i] = summand.getNumber(i % size, i / size);
	}
	else {
		std::cerr << "���������� ������� ����� �������" << std::endl;
		std::exit(1);
	}
}

void Matrix::output() const
{
	/* ��������� ����� ������� 4x4. ����������, ����� ������� ����� � ���������,
	   ����� ������� �� ������ ������� ������� ������. ����������, ����� � ���
	   ������� �� ������� �� ������ �������. ���������� ����������� ������
	   ��� ������� 7x7. �������� �����.
	   0  1   2   3
	   4  5   6   7
	   8  9   10  11
	   12 13  14  15

		0  1  2  3  4  5  6
		7  8  9  10 11 12 13
		14 15 16 17 18 19 20
		21 22 23 24 25 26 27
		28 29 30 31 32 33 34
		35 36 37 38 39 40 41
		42 43 44 45 46 47 48
	   */
	for (unsigned int i = 0; i < size * size; ++i) {
		std::cout << numbers[i] << " ";
		if (i % size == size - 1)
			std::cout << std::endl;
	}
}