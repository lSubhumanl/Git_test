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
	void randomize(int min,int max);
};

std::istream& operator>>(std::istream& someStream, RectangularMatrix& matrix);
std::ostream& operator<<(std::ostream& someStream, const RectangularMatrix& matrix);

#endif // !_RECTANGULAR_MATRIX_H
