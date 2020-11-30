#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "Matrix.h"
#include "Matrix.h"
#include "Matrix.h"
#include "Matrix.h"
#include "UnityMatrix.h"
#include "RectangularMatrix.h"
using std::cerr;
using std::cout;
using std::endl;
using std::exit;


int main(void)
{
	{
		std::ofstream ofs("rect_matrix.txt");
		RectangularMatrix m(5, 3);
		m.randomize(0,100);
		cout << "Матрица до записи: " << endl << m << endl;
		ofs << m;
	}
	{
		std::ifstream ifs("rect_matrix.txt");
		RectangularMatrix m;
		ifs >> m;
		cout << "Матрица после записи:" << endl << m << endl;
	}
}