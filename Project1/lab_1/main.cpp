#include <iostream>
#include <cstdlib>

using std::cerr;
using std::exit;

class Matrix {
private:
	unsigned int size; //количество строк и столбцов
	int* numbers;

public:
	Matrix(void);
	Matrix(unsigned int newSize);
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
	Matrix operator+(Matrix& rightMatrix);
	Matrix operator-(Matrix& rightMatrix);
	Matrix& operator=(Matrix& rightMatrix);

	// cout << m1() << endl;	
};

/* внеклассовое определение метода указывается следующим образом:
 * ReturnType ClassName::methodName(ArgType arg1, ArgType arg2) { ... }
 *
 *
 */

 // TODO важный момент:
 // на данном этапе (до изученных эксэпшэнов)
 // в любой нештатной ситуации пишем ошибку на std::cerr
 // и делаем std::exit(EXIT_FAILURE) из <cstdlib>


	 /* номер элемента в массиве => строка и столбец:
	  * row = (i / size)
	  * col = (i % size)
	  * строка и столбец => номер элемента в массиве:
	  * idx = row * size + col
	 */
	 /*
	 int x, y, z = 6;

	 x = y = z;

	 MyClass m1, m2, m3(4,5);

	 m1 = m2 = m3;

	 */
Matrix& Matrix::operator=(Matrix& rightMatrix)
{
	if (this != &rightMatrix) {
		if (size != rightMatrix.getSize()) {
			this->setSize(rightMatrix.getSize());
		}

		for (unsigned int i = 0; i < size * size; ++i) {
			numbers[i] = rightMatrix.getNumber(i % size, i / size);
		}
	}
	/*
	Опишите разницу между *this, this и &this.
	*this - объект (может быть неявно преобразован в ссылку на объект)
	this - указатель на объект (может быть неявно преобразован в ссылку на указатель на объект)
	&this - двойной указатель (может быть неявно преобразован в ссылку на двойной указатель)
	*/
	return *this;

}

Matrix Matrix::operator-(Matrix& rightMatrix)
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

Matrix Matrix::operator+(Matrix& rightMatrix)
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

Matrix::Matrix(const Matrix& instanceToCopyFrom)
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
	size = newSize;
	// TODO неужели матрица 3*3 элемента НАСТОЛЬКО легко превратится
	// в матрицу 5*5?
}

int Matrix::getNumber(unsigned int column, unsigned int row) const
{
	if (row < size && column < size)
		return numbers[row * size + column];
	// TODO else?
}

void Matrix::setNumber(unsigned int column, unsigned int row, int newNumber)
{
	if (row < size && column < size)
		numbers[row * size + column] = newNumber;
	else {
		cerr << "Попытка изменения несуществующего объекта элемента матрицы "
			<< row << " " << column << " " << size * size << std::endl;

	}
	// TODO else
}

void Matrix::plusAssign(const Matrix& summand)
{
	if (size == summand.getSize) {
		for (unsigned int i = 0; i < size; ++i)
			numbers[i] += summand.getNumber(i % size, i / size);
	}
	else {
		std::cerr << "Добавление матрицы иного размера" << std::endl;
		std::exit(1);
	}
}
/* метод выше - обычный, и вызывается как summand1.plusAssign(summand2);
 * операторный метод должен уметь вызываться по выражению summand1 += summand2; */

void Matrix::output() const
{
	/* Нарисуйте вывод матрицы 4x4. Посмотрите, какие индексы будут у элементов,
	   после которых вы хотите увидеть перенос строки. Посмотрите, какой у них
	   остаток от деления на размер матрицы. Посчитайте аналогичный случай
	   для матрицы 7x7. Сделайте вывод.
	   0  1   2   3
	   4  5   6   7
	   8  9   10  11
	   12 13  14  15

		0  1  2  3  4  5  6
		7  8  9  10 11 12 13
		14 15 16 17 18 19 20
		21 22 23 24 25 26 27
		28 29 30 31 32 33 34
		35 36 37 38 39 40 41
		42 43 44 45 46 47 48
	   */
	for (unsigned int i = 0; i < size * size; ++i) {
		std::cout << numbers[i] << " ";
		if (i % size == size - 1)
			std::cout << std::endl;
	}
}

int main(void)
{
	Matrix a, b;
	a.plusAssign(b);
}