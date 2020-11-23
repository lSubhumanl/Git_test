#include <iostream>
#include <random>
#include "IntArray.h"

int main(void)
{
	IntArray a(10);
	std::default_random_engine re;
	for (unsigned int i = 0; i < 10; ++i)
		a[i] = re() % 100;
	for (unsigned int i = 0; i < 10; ++i)
		std:: cout << a[i] << " " ;
}