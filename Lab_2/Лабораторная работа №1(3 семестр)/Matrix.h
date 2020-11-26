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

	void plusAssign(const Matrix& summand);
	Matrix operator+(const Matrix& rightMatrix) const;
	Matrix operator-(const Matrix& rightMatrix) const;
	Matrix& operator=(const Matrix& rightMatrix);
	void writeToStream(std::ostream& output) const;
	void readFromStream(std::istream& input);
	void randomize();
};
std::istream& operator>>(std::istream& someStream, Matrix& matrix);
std::ostream& operator<<(std::ostream& someStream, const Matrix& matrix);

#endif