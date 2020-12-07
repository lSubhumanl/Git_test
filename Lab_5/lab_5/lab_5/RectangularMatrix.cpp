#include "RectangularMatrix.h"
#include <cstdlib>
#include <iostream>

using std::cerr;
using std::endl;
using std::exit;

Matrix RectangularMatrix::operator+ (const Matrix& rightMatrix) const{
	cerr << "Невозможно сложить матрицы разного типа" << endl;
	exit(EXIT_FAILURE);
}

Matrix RectangularMatrix::operator- (const Matrix& rightMatrix) const {
	cerr << "Невозможно вычесть матрицы разного типа" << endl;
	exit(EXIT_FAILURE);
}

Matrix& RectangularMatrix::operator= (const Matrix& rightMatrix){
	cerr << "Невозможно присвоить матрицы разного типа" << endl;
	exit(EXIT_FAILURE);
}

RectangularMatrix::RectangularMatrix(void) 
	:Matrix(), width(1), height(1) 
{
}

RectangularMatrix::RectangularMatrix(unsigned int newWidth, unsigned int newHeight)
	: Matrix(newWidth > newHeight ? newWidth : newHeight), width(newWidth), height(newHeight)
{
}

RectangularMatrix::RectangularMatrix(const RectangularMatrix& instanceToCopyFrom)
	:Matrix(instanceToCopyFrom.getWidth() > instanceToCopyFrom.getHeight() ?
		instanceToCopyFrom.getWidth() : instanceToCopyFrom.getHeight()),
	width(instanceToCopyFrom.getWidth()), height(instanceToCopyFrom.getHeight())
{
	for (unsigned int row = 0; row < height; ++row) {
		for (unsigned int col = 0; col < width; ++col) {
			setNumber(col, row, instanceToCopyFrom.getNumber(col, row));
		}
	}
}

unsigned int RectangularMatrix::getWidth(void) const
{
	return width;
}

unsigned int RectangularMatrix::getHeight(void) const
{
	return height;
}

unsigned int RectangularMatrix::getSize(void) const {
	return width > height ? width : height;
}

int RectangularMatrix::getNumber(unsigned int column, unsigned int row) const
{
	if (column >= width && row >= height) {
		cerr << "Запрос несущетсвующего элемента" << endl;
		exit(EXIT_FAILURE);
	}

	return Matrix::getNumber(column, row);
}


void RectangularMatrix::setSize(unsigned int newSize) {
	setSize(newSize, newSize);
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
	if (column >= width && row >= height) {
		cerr << "Запрос на изменение несущетсвующего элемента" << endl;
		exit(EXIT_FAILURE);
	}
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

void RectangularMatrix::plusAssign(const Matrix& summand) {
	cerr << "Невозможно сложить матрицы разного типа" << endl;
	exit(EXIT_FAILURE);
}

RectangularMatrix RectangularMatrix::operator+(const RectangularMatrix& rightMatrix)const
{
	RectangularMatrix result = *this;
	result.plusAssign(rightMatrix);
	return result;
}

RectangularMatrix RectangularMatrix::operator-(const RectangularMatrix& rightMatrix)const
{
	if (this->getWidth() != rightMatrix.getWidth() || this->getHeight() != rightMatrix.getHeight())
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
	output << width << ' ' << height << endl;
	for (unsigned int row = 0; row < height; ++row) {
		for (unsigned int col = 0; col < width; ++col) {
			output << getNumber(col, row)<<' ';
		}
		output << endl;
	}
}

void RectangularMatrix::readFromStream(std::istream& input) 
{
	unsigned int newWidth, newHeight;
	input >> newWidth >> newHeight;
	setSize(newWidth, newHeight);
	for (unsigned int row = 0; row < height; ++row){
		for (unsigned int col = 0; col < width; ++col){
			int newNumber;
			input >> newNumber;
			setNumber(col, row, newNumber);
		}
	}
}

void RectangularMatrix::randomize(int min, int max) {
	for (unsigned int col = 0; col < width; ++col) {
		for (unsigned int row = 0; row < height; ++row) {
			setNumber(col, row, rand() % (max - min + 1) + min);
		}
	}
}

std::istream& operator>>(std::istream& someStream, RectangularMatrix& matrix)
{
	matrix.readFromStream(someStream);
	return someStream;
}
std::ostream& operator<<(std::ostream& someStream, const RectangularMatrix& matrix)
{
	matrix.writeToStream(someStream);
	return someStream;
}