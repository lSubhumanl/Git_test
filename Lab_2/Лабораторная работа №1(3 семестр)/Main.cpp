#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "Matrix.h"
#include "Matrix.h"
#include "Matrix.h"
#include "Matrix.h"
#include "UnityMatrix.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exit;








/* номер элемента в массиве => строка и столбец:
     * row = (i / size)
	 * col = (i % size)
	 * строка и столбец => номер элемента в массиве: 
	 * idx = row * size + col
    */
void Matrix::readFromStream(std::istream &input)
{
	unsigned int newSize;
	input >> newSize;
	if (newSize != size) {
		setSize(newSize);
	}
	for (unsigned int i = 0; i < size * size; ++i)
		input >> numbers[i];
}
void Matrix::writeToStream(std::ostream &output) const
{
	output << size;
	for (unsigned int i = 0; i < size * size; ++i) {
		if (i % size == 0)
			output << endl;
		output << numbers[i] << " ";
	}
	output << endl;
}

Matrix &Matrix::operator=(Matrix &rightMatrix)
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

Matrix Matrix::operator-(Matrix &rightMatrix)
{
	if (this->size != rightMatrix.getSize()) {
		cerr << "Вычитание матрица разного размера" << std::endl;
		exit(EXIT_FAILURE);
	}

	Matrix result = *this;
	// у каждого элемента result вызываем сеттер со значением разности
	// значений геттеров this и rightMatrix
	for (unsigned int i = 0; i <= size * size; ++i) {
		int difference = result.getNumber(i % size, i / size) -
				 rightMatrix.getNumber(i % size, i / size);
		result.setNumber(i % size, i / size, difference);
	}
	return result;
}

Matrix Matrix::operator+(Matrix &rightMatrix)
{
	Matrix result = *this;
	result.plusAssign(rightMatrix);
	return result;
	/* Matrix m3 = m1 + m2;
	 * это преобразуется в...
	 * Matrix m3 = m1.operator+(m2); */
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

Matrix::Matrix(const Matrix &instanceToCopyFrom)
{
	size = instanceToCopyFrom.getSize();
	unsigned int arraySize = size * size;
	numbers = new int[arraySize];
	for (unsigned int i = 0; i != arraySize; ++i) {
		numbers[i] = instanceToCopyFrom.getNumber(i % size, i / size);
	}
}

/* пусть есть матрица 3*3 со следующими индексами:
   0 1 2
   3 4 5
   6 7 8
   Прикиньте, будет ли сохранён порядок следования элементов
   при копировании в другой объект.
   */

// пусть есть номер строки row, номер строки column, размер матрицы size.
// придумайте, как посчитать индекс соответствующего элемента в одномерном массиве.
// задача сильно облегчится, если вы посмотрите матрицу 10x10.

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

	int *newNumbers = new int[newSize * newSize];

	for (unsigned int row = 0; row < newSize; ++row) {
		for (unsigned int col = 0; col < newSize; ++col) {
			if (row < size && col < size)
				newNumbers[row * newSize + col] =
					numbers[row * size + col];
			else
				newNumbers[row * newSize + col] = 0;
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
		cerr << "Попытка взятия несуществующего объекта элемента матрицы "
			<< row << " " << column << " " << size * size << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Matrix::setNumber(unsigned int column, unsigned int row, int newNumber)
{
	if (row < size && column < size)
		numbers[row * size + column] = newNumber;
	else {
		cerr << "Попытка изменения несуществующего объекта элемента матрицы "
		     << row << " " << column << " " << size * size << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Matrix::plusAssign(const Matrix &summand)
{
	if (size == summand.getSize()) {
		for (unsigned int i = 0; i < size * size; ++i)
			numbers[i] += summand.getNumber(i % size, i / size);
	} else {
		std::cerr << "Добавление матрицы иного размера" << std::endl;
		std::exit(1);
	}
}
/* метод выше - обычный, и вызывается как summand1.plusAssign(summand2);
 * операторный метод должен уметь вызываться по выражению summand1 += summand2; */

int main(void)
{
	UnityMatrix a(4);
	cout << a;
}