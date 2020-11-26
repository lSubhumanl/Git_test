#include "Matrix.h"
#include <cstdlib>
#include <iostream>

using std::cerr;
using std::endl;
using std::exit;

 /* номер элемента в массиве => строка и столбец:
	  * row = (i / size)
	  * col = (i % size)
	  * строка и столбец => номер элемента в массиве:
	  * idx = row * size + col
	 */
void Matrix::readFromStream(std::istream& input)
{
	unsigned int newSize;
	input >> newSize;
	if (newSize != size) {
		setSize(newSize);
	}
	for (unsigned int i = 0; i < size * size; ++i)
		input >> numbers[i];
}
void Matrix::writeToStream(std::ostream& output) const
{
	output << size;
	for (unsigned int i = 0; i < size * size; ++i) {
		if (i % size == 0)
			output << endl;
		output << numbers[i] << " ";
	}
	output << endl;
}

Matrix& Matrix::operator=(const Matrix& rightMatrix)
{
	if (this != &rightMatrix) {
		if (size != rightMatrix.getSize()) {
			this->setSize(rightMatrix.getSize());
		}

		for (unsigned int i = 0; i < size * size; ++i) {
			numbers[i] = rightMatrix.getNumber(i % size, i / size);
		}
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix& rightMatrix) const
{
	if (this->size != rightMatrix.getSize()) {
		cerr << "Вычитание матриц разного размера" << endl;
		exit(EXIT_FAILURE);
	}

	Matrix result = *this;
	for (unsigned int i = 0; i <= size * size; ++i) {
		int difference = result.getNumber(i % size, i / size) -
			rightMatrix.getNumber(i % size, i / size);
		result.setNumber(i % size, i / size, difference);
	}
	return result;
}

Matrix Matrix::operator+(const Matrix& rightMatrix) const
{
	Matrix result = *this;
	result.plusAssign(rightMatrix);
	return result;
}

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
	if (newSize == 0) {
		cerr << "Невозможно выставить нулевой размер матрицы" << endl;
		exit(EXIT_FAILURE);
	}
	if (newSize == size)
		return;

	size_t n_numbers = (size_t ) newSize * newSize;
	int* newNumbers = new int[n_numbers];
	for (unsigned int row = 0; row < newSize; ++row) {
		for (unsigned int col = 0; col < newSize; ++col) {
			size_t idx=(size_t) row * newSize + col;
			if (row < size && col < size)
				newNumbers[row * newSize + col] =
				numbers[row * size + col];
			else if (idx < n_numbers)
				newNumbers[idx] = 0;
		}
	}
	delete[] numbers;
	numbers = newNumbers;
	size = newSize;
}

int Matrix::getNumber(unsigned int column, unsigned int row) const
{
	if (row < size && column < size)
		return numbers[row * size + column];
	else {
		cerr << "Запрос несуществующего элемента матрицы "
			<< row << " " << column << " " << size * size << endl;
		exit(EXIT_FAILURE);
	}

}

void Matrix::setNumber(unsigned int column, unsigned int row, int newNumber)
{
	if (row < size && column < size)
		numbers[row * size + column] = newNumber;
	else {
		cerr << "Попытка изменения несуществующего объекта элемента матрицы "
			<< row << " " << column << " " << size * size << endl;
		exit(EXIT_FAILURE);
	}
}

void Matrix::plusAssign(const Matrix& summand)
{
	if (size == summand.getSize()) {
		for (unsigned int i = 0; i < size * size; ++i)
			numbers[i] += summand.getNumber(i % size, i / size);
	}
	else {
		cerr << "Добавление матрицы иного размера" << endl;
		exit(EXIT_FAILURE);
	}
}
void Matrix::randomize()
{
	for (unsigned int i = 0; i < size * size; ++i) {
		numbers[i] = rand() % 100;
	}
}

std::istream& operator>>(std::istream& someStream, Matrix& matrix)
{
	matrix.readFromStream(someStream);
	return someStream;
}
std::ostream& operator<<(std::ostream& someStream, const Matrix& matrix)
{
	matrix.writeToStream(someStream);
	return someStream;
}