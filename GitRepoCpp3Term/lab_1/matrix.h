#pragma once
class Matrix {
private:
	unsigned int size;
	int* numbers;

public:
	Matrix(void);
	Matrix(unsigned int newSize);
	// ��������, ��� ����� ����������� ����������� � ���
	// ��������, ����� �� ��� ��� ���
	// �������� ��� ����������� ������ � ���
	// ��������� � ����� ������� ��� ����������� �����������
	// (���� ����������� ����������� �����������,
	// ���� ������� ������ � ����������� ���)
	Matrix(const Matrix& instanceToCopyFrom);
	~Matrix(void);
	unsigned int getSize(void) const;
	void setSize(unsigned int newSize);
	int getNumber(unsigned int column, unsigned int row) const;
	void setNumber(unsigned int column, unsigned int row, int newNumber);
	/* ���� ������� m1.plusAssign(m2), �� ������ ������ ������ m1 ����� this,
		 * � ������ summand ����� m2. */
	void plusAssign(const Matrix& summand);
	void output() const;
	void multAssign(const Matrix& factor);
	void multAssign(int num);
};