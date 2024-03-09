#include <iostream>
#include "labasd.h"
#include <ctime>
#include <time.h>

using namespace std;

int BinaryTree::count_completion = 0;
int BinaryTree::count_search = 0;
int BinaryTree::count_del = 0;
int main()	
{
	srand(time(NULL));
	BinaryTree test1(3);
	BinaryTree test2(3);
	test1.insert(5);
	test1.insert(6);
	test1.insert(7);
	test1.insert(8);
	test2.insert(6);
	test2.insert(5);
	test2.insert(7);
	test2.insert(8);
	vector<int> task;
	task = search_intersection(test1.root, test2.root);
	for (int i = 0; i < task.size(); ++i) {
		cout << task[i] << " ";
	}
	/*BinaryTree A(500);
	BinaryTree B(600);
	BinaryTree C(700);
	int size_begin = 1000;
	int size_medium = 10000;
	int size_end = 100000;
	int n_time = 100;
	int n_time_search = 1000;
	for (int j = 0; j < n_time; j++) {
		for (int i = 0; i < size_begin; ++i) {
			A.insert(rand() % size_begin);
		}
	}
	cout << A.get_count_completion()/ n_time << endl;
	for (int j = 0; j < n_time; j++) {
		for (int i = 0; i < size_medium; ++i) {
			B.insert(rand() % size_medium);
		}
	}
	cout << B.get_count_completion() / n_time << endl;
	for (int j = 0; j < n_time; j++) {
		for (int i = 0; i < size_end; ++i) {
			C.insert(rand() % size_end);
		}
	}
	cout << C.get_count_completion() / n_time << endl;
	for (int j = 0; j < n_time_search; j++) {
		A.Findelem(rand() % size_begin);
	}
	cout << A.get_count_search() / n_time_search << endl;
	for (int j = 0; j < n_time_search; j++) {
		B.Findelem(rand() % size_medium);
	}
	cout << B.get_count_search() / n_time_search << endl;
	for (int j = 0; j < n_time_search; j++) {
		C.Findelem(rand() % size_end);
	}
	cout << C.get_count_search() / n_time_search << endl;
	for (int j = 0; j < n_time_search; j++) {
		A.erase(rand() % size_begin);
	}
	cout << A.get_count_del() / n_time_search << endl;
	for (int j = 0; j < n_time_search; j++) {
		B.erase(rand() % size_medium);
	}
	cout << B.get_count_del() / n_time_search << endl;
	for (int j = 0; j < n_time_search; j++) {
		C.erase(rand() % size_end);
	}
	cout << C.get_count_del() / n_time_search << endl;*/
}