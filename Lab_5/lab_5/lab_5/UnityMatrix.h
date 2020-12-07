#ifndef _UNITY_MATRIX_H
#define _UNITY_MATRIX_H
#include "Matrix.h"
#include <iostream>

class UnityMatrix : private Matrix {
public:
	UnityMatrix(void);
	UnityMatrix(unsigned int newSize);
	UnityMatrix(const UnityMatrix& instanceToCopyFrom);
	unsigned int getSize(void) const;
	void setSize(unsigned int newSize);
	int getNumber(unsigned int column, unsigned int row) const;
	void writeToStream(std::ostream& output) const;
};
std::ostream& operator<<(std::ostream& someStream, const UnityMatrix& matrix);
#endif