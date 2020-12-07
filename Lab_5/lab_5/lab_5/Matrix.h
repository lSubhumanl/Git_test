#ifndef _MATRIX_H
#define _MATRIX_H
#include <iostream> 

class Matrix {
private:
	unsigned int size; 
	int* numbers;

public:
	Matrix(void);
	Matrix(unsigned int newSize);
	Matrix(const Matrix& instanceToCopyFrom);
	~Matrix(void);
	virtual unsigned int getSize(void) const;
	virtual void setSize(unsigned int newSize);
	virtual int getNumber(unsigned int column, unsigned int row) const;
	virtual void setNumber(unsigned int column, unsigned int row,
		int newNumber);

	virtual void plusAssign(const Matrix& summand);
	virtual Matrix operator+(const Matrix& rightMatrix) const;
	virtual Matrix operator-(const Matrix& rightMatrix) const;
	virtual Matrix& operator=(const Matrix& rightMatrix);
	virtual void writeToStream(std::ostream& output) const;
	virtual void readFromStream(std::istream& input);
	virtual void randomize(int min, int max);
};
std::istream& operator>>(std::istream& someStream, Matrix& matrix);
std::ostream& operator<<(std::ostream& someStream, const Matrix& matrix);

#endif