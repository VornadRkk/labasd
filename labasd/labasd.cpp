// labasd.cpp: определяет точку входа для приложения.
//

#include "labasd.h"

using namespace std;

int main()
{
	Tree A(5);
	A.insert(4);
	A.insert(3);
	A.insert(7);
	A.contains(7);
	A.print();
}