#include "RectangularMatrix.h"
#include <cstdlib>
#include <iostream>

using std::cerr;
using std::endl;
using std::exit;

RectangularMatrix::RectangularMatrix(void) 
	:Matrix(), width(1), height(1) 
{

}

RectangularMatrix::RectangularMatrix(unsigned int newWidth, unsigned int newHeight)
	: Matrix(newWidth > newHeight ? newWidth : newHeight), width(newWidth), height(newHeight)
{

}

RectangularMatrix::RectangularMatrix(const RectangularMatrix& instanceToCopyFrom)
	:Matrix(instanceToCopyFrom.getWidth() > instanceToCopyFrom.getWidth() ?
		instanceToCopyFrom.getWidth() : instanceToCopyFrom.getHeight()),
	width(instanceToCopyFrom.getWidth()), height(instanceToCopyFrom.getWidth())
{

}

unsigned int RectangularMatrix::getWidth(void) const
{
	return width;
}

unsigned int RectangularMatrix::getHeight(void) const
{
	return height;
}

int RectangularMatrix::getNumber(unsigned int column, unsigned int row) const
{
	//todo проверить допустимость индексов
	return Matrix::getNumber(column, row);
}

void RectangularMatrix::setSize(unsigned int newWidth, unsigned int newHeight) 
{
	if (newWidth == 0 || newHeight == 0)
	{
		cerr << "Здесь армяне в нарды играют" << endl;
		exit(EXIT_FAILURE);
	}
	width = newWidth;
	height = newHeight;
	Matrix::setSize(width > height ? width:height);
}

void RectangularMatrix::setNumber(unsigned int column, unsigned int row, int newNumber)
{
	//todo проверить допустимость индексов
	Matrix::setNumber(column, row, newNumber);
}

void RectangularMatrix::plusAssign(const RectangularMatrix& summand)
{
	if (width != summand.getWidth() || height != summand.getHeight()) {
		cerr << "Добавление матрицы иного размера" << endl;
		exit(EXIT_FAILURE);
	}

	for (unsigned int col = 0; col < width; ++col) {
		for (unsigned int row = 0; row < height; ++row) {
			setNumber(col, row, getNumber(col, row) + summand.getNumber(col, row));
		}
	}
}

RectangularMatrix RectangularMatrix::operator+(const RectangularMatrix& rightMatrix)const
{
	RectangularMatrix result = *this;
	result.plusAssign(rightMatrix);
	return result;
}

RectangularMatrix RectangularMatrix::operator-(const RectangularMatrix& rightMatrix)const
{
	if (this->getWidth() != rightMatrix.getWidth() || this->getHeight() != rightMatrix.getHeight)
	{
		cerr << "Вычитание матриц разного размера" << endl;
		exit(EXIT_FAILURE);
	}
	RectangularMatrix result = *this;
	for (unsigned int col = 0; col < width; ++col) {
		for (unsigned int row = 0; row < height; ++row) {
			int difference = getNumber(col, row) - rightMatrix.getNumber(col, row);
			result.setNumber(col, row, difference);
		}
	}
	return result;
}

RectangularMatrix& RectangularMatrix::operator=(const RectangularMatrix& rightMatrix)
{
	if (this != &rightMatrix) {
		if (width != rightMatrix.getWidth() || height != rightMatrix.getHeight()) {
			this->setSize(height,width);
		}

		for (unsigned int col = 0; col < width ; ++col) {
			for (unsigned int row = 0; row < height; ++row) {
				setNumber(col,row, rightMatrix.getNumber(col, row));
			}
		}
	}
	return *this;
}

void RectangularMatrix::writeToStream(std::ostream& output) const
{
	output << size;
	for (unsigned int i = 0; i < size * size; ++i) {
		if (i % size == 0)
			output << endl;
		output << numbers[i] << " ";
	}
	output << endl;
}