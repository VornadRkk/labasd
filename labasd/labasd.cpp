// labasd.cpp: определяет точку входа для приложения.
//

#include "labasd.h"

using namespace std;

int main()
{
	BinaryTree A(5);
	A.insert(4);
	A.erase(4);
	A.print();
}