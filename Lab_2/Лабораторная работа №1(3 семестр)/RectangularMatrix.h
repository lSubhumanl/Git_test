#ifndef _RECTANGULAR_MATRIX_H
#define _RECTANGULAR_MATRIX_H
#include <iostream>
#include "Matrix.h"

class RectangularMatrix : private Matrix {
	unsigned int width, height;
public: 
	// предложение: скопировать объявления всех методов родительского класса,
	// и подписать, какая судьба у него в дочернем классе:
	// либо ему нет места в дочернем классе,
	// либо у него будет полностью новая реализация,
	// либо у него будет частично дочерняя реализация, и вызов метода родителя.

	/*
	Matrix(void); - передаем управление на конструктор родительского класса 
	Matrix(unsigned int newSize); - не нужен метод с одним аргументом, но нужен от двух
	Matrix(const Matrix& instanceToCopyFrom); - частично используется конструктор родительского класса  
	~Matrix(void); - не нужен 
	virtual unsigned int getSize(void) const;  - метод родительского класса не нужен, нужно написать отдельный геттер
	virtual void setSize(unsigned int newSize); - метод родительского класса не нужен, нужно написать отдельный сеттер
	virtual int getNumber(unsigned int column, unsigned int row) const; - передаем управление на метод родительского класса
	(Проверка допустимости индекса)

	virtual void setNumber(unsigned int column, unsigned int row,
		int newNumber); - передаем управление на метод родительского класса (Проверка допустимости индекса)

	void plusAssign(const Matrix& summand); - передаем управление на метод родительского класса
	Matrix operator+(Matrix& rightMatrix); - родительский метод не нужен, нужно писать отдельный
	Matrix operator-(Matrix& rightMatrix); - родительский метод не нужен, нужно писать отдельный
	Matrix& operator=(Matrix& rightMatrix); - родительский метод не нужен, нужно писать отдельный
	void writeToStream(std::ostream& output) const; - родительский метод не нужен, нужно писать отдельный
	void readFromStream(std::istream& input); - родительский метод не нужен, нужно писать отдельный
	void randomize(); - родительский метод не нужен, нужно писать отдельный
};
std::istream& operator>>(std::istream& someStream, Matrix& matrix); - нужно переписать операторную функцию
std::ostream& operator<<(std::ostream& someStream, const Matrix& matrix); - нужно переписать операторную функцию
***Дополнительно***


*/
};

#endif // !_RECTANGULAR_MATRIX_H
