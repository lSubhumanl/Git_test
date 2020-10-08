#pragma once
class Matrix {
private:
	unsigned int size;
	int* numbers;

public:
	Matrix(void);
	Matrix(unsigned int newSize);
	// почитать, что такое конструктор копирования в цпп
	// подумать, нужен он тут или нет
	// почитать про константные методы в цпп
	// воплотить в жизнь решение про конструктор копирования
	// (либо реализовать полноценный конструктор,
	// либо сделать пустой и заприватить его)
	Matrix(const Matrix& instanceToCopyFrom);
	~Matrix(void);
	unsigned int getSize(void) const;
	void setSize(unsigned int newSize);
	int getNumber(unsigned int column, unsigned int row) const;
	void setNumber(unsigned int column, unsigned int row, int newNumber);
	/* если вызвать m1.plusAssign(m2), то внутри метода вместо m1 будет this,
		 * а вместо summand будет m2. */
	void plusAssign(const Matrix& summand);
	void output() const;
	void multAssign(const Matrix& factor);
	void multAssign(int num);
};