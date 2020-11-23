#include "UnityMatrix.h"
UnityMatrix::UnityMatrix(void)
{
	setSize(1);
	setNumber(0, 0, 1);
}

UnityMatrix::UnityMatrix(unsigned int newSize) : Matrix(newSize)
{
	for (unsigned int row = 0; row < newSize; ++row) {
		for (unsigned int col = 0; col < newSize; ++col) {
			if (row == col)
				setNumber(col, row, 1);
			else
				setNumber(col, row, 0);
		}
	}
}

UnityMatrix::UnityMatrix(const UnityMatrix& instanceToCopyFrom)
	: Matrix(instanceToCopyFrom.getSize())
{
	unsigned int size = instanceToCopyFrom.getSize();
	for (unsigned int row = 0; row < size; ++row) {
		for (unsigned int col = 0; col < size; ++col) {
			setNumber(col, row, row == col ? 1 : 0);
		}
	}
}
unsigned int UnityMatrix::getSize(void) const
{
	return Matrix::getSize();
}
	
void UnityMatrix::setSize(unsigned int newSize)
{
	Matrix::setSize(newSize);
}
	
int UnityMatrix::getNumber(unsigned int column, unsigned int row) const
{
	return column == row ? 1 : 0;
}
	
void UnityMatrix::writeToStream(std::ostream& output) const
{
	Matrix::writeToStream(output);
}
std::ostream& operator<<(std::ostream& someStream, const UnityMatrix& matrix)
{
	matrix.writeToStream(someStream);
	return someStream;
}