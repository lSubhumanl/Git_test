#ifndef _RECTANGULAR_MATRIX_H
#define _RECTANGULAR_MATRIX_H
#include <iostream>
#include "Matrix.h"

class RectangularMatrix : private Matrix {
	unsigned int width, height;
public: 
	RectangularMatrix(void);
	RectangularMatrix(unsigned int newWidth, unsigned int newHeight);
	RectangularMatrix(const RectangularMatrix& instanceToCopyFrom);
	unsigned int getWidth(void) const;
	unsigned int getHeight(void) const;
	int getNumber(unsigned int column, unsigned int row) const;
	void setSize(unsigned int newWidth, unsigned int newHeight);
	void setNumber(unsigned int column, unsigned int row, int newNumber);
	void plusAssign(const RectangularMatrix& summand);
	RectangularMatrix operator+(const RectangularMatrix& rightMatrix)const;
	RectangularMatrix operator-(const RectangularMatrix& rightMatrix)const;
	RectangularMatrix& operator=(const RectangularMatrix& rightMatrix);
	void writeToStream(std::ostream& output) const;
	void readFromStream(std::istream& input);
	// предложение: скопировать объ€влени€ всех методов родительского класса,
	// и подписать, кака€ судьба у него в дочернем классе:
	// либо ему нет места в дочернем классе,
	// либо у него будет полностью нова€ реализаци€,
	// либо у него будет частично дочерн€€ реализаци€, и вызов метода родител€.

	/* 
	void writeToStream(std::ostream& output) const; - родительский метод не нужен, нужно писать отдельный
	void readFromStream(std::istream& input); - родительский метод не нужен, нужно писать отдельный
	void randomize(); - родительский метод не нужен, нужно писать отдельный
};
std::istream& operator>>(std::istream& someStream, Matrix& matrix); - нужно переписать операторную функцию
std::ostream& operator<<(std::ostream& someStream, const Matrix& matrix); - нужно переписать операторную функцию
***ƒополнительно***


*/
};

#endif // !_RECTANGULAR_MATRIX_H
