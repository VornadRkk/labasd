#include <iostream>
#include "labasd.h"
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std;
double fillTime(BinaryTree& container, const size_t size) {
	srand(time(NULL));
	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < size; ++i) {
		container.insert(rand() % 100000);
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	return duration.count();
}
double searchTime( BinaryTree& container, int value) {
	auto start = std::chrono::high_resolution_clock::now();

	bool found = container.Findelem(value);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	if (found) {
		return duration.count();
	}
	else {
		return 0;
	}
}
double insertionTime(BinaryTree& container,int  value) {
	auto start = std::chrono::high_resolution_clock::now();

	container.insert(value);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	return duration.count();
}
double eraseTime(BinaryTree& container, int  value) {
	auto start = std::chrono::high_resolution_clock::now();

	container.erase(value);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	return duration.count();
}
// Перегрузка vector,а то я потерялся
double fillTime(vector<int> container, const size_t size) {
	srand(time(NULL));
	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < size; ++i) {
		container.push_back(rand() % 10000);
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	return duration.count();
}
double searchTime(vector<int>& container, int value) {
	auto start = std::chrono::high_resolution_clock::now();

	bool found = find(container,value);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	if (found) {
		return duration.count();
	}
	else {
		return 0;
	}
}
double insertionTime(vector<int>& container, int  value) {
	auto start = std::chrono::high_resolution_clock::now();

	container.push_back(value);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	return duration.count();
}
double eraseTime(vector<int>& container, int  value) {
	auto start = std::chrono::high_resolution_clock::now();

	if (find(container, value)) {
		container.erase(std::remove(container.begin(), container.end(), value), container.end());
	}
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	return duration.count();
}
//конец 
int main()	
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	BinaryTree test(1);
	/*BinaryTree test1(3);
	BinaryTree test2(3);
	test1.insert(5);
	test1.insert(6);
	test1.insert(7);
	test1.insert(8);
	test2.insert(6);
	test2.insert(5);
	test2.insert(7);
	test2.insert(8);
	test1.insert(111);
	test2.insert(220);
	vector<int> task;
	task = search_intersection(test1.root, test2.root);
	vector<int> task2;
	task2 = search_difference(test1.root, test2.root);*/
	BinaryTree A1000(1);
	BinaryTree A10000(1);
	BinaryTree A100000(1);
	for (int i = 0; i < 1000; i++) {
		A1000.insert(rand() % 100000);
	}
	for (int i = 0; i < 10000; i++) {
		A10000.insert(rand() % 100000);
	}
	for (int i = 0; i < 100000; i++) {
		A100000.insert(rand() % 100000);
	}
	double count = 0;
	for (int i = 0; i < 100; i++) {
		count += fillTime(test, 1000);
	}
	cout << " Среднее время заполнения для 1000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += fillTime(test, 10000);
	}
	cout << " Среднее время заполнения для 10000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += fillTime(test, 100000);
	}
	cout << " Среднее время заполнения для 100000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += searchTime(A1000, rand() % 100000);
	}
	cout << " Среднее время поиска для 1000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += searchTime(A10000, rand() % 100000);
	}
	cout << " Среднее время поиска для 10000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += searchTime(A100000, rand() % 100000);
	}
	cout << " Среднее время поиска для 100000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += insertionTime(A1000, rand() % 100000);
	}
	cout << " Среднее время добавления для 1000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += insertionTime(A10000, rand() % 100000);
	}
	cout << " Среднее время добавления для 10000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += insertionTime(A100000, rand() % 100000);
	}
	cout << " Среднее время добавления для 100000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += eraseTime(A1000, rand() % 100000);
	}
	cout << " Среднее время удаления для 1000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += eraseTime(A10000, rand() % 100000);
	}
	cout << " Среднее время удаления для 10000 элементов: " << count / 100 << " Сек" << endl;
	count = 0;
	for (int i = 0; i < 100; i++) {
		count += eraseTime(A100000, rand() % 100000);
	}
	cout << " Среднее время удаления для 100000 элементов: " << count / 100 << " Сек" << endl;
	// Пошел теперь vector
	vector<int> test_vector;
	vector<int> A1000_vector;
	vector<int> A10000_vector;
	vector<int> A100000_vector;
	for (int i = 0; i < 1000; i++) {
		A1000_vector.push_back(rand() % 100000);
	}
	for (int i = 0; i < 10000; i++) {
		A10000_vector.push_back(rand() % 100000);
	}
	for (int i = 0; i < 100000; i++) {
		A100000_vector.push_back(rand() % 100000);
	}
	double count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += fillTime(test_vector, 1000);
	}
	cout << "(Vector)Среднее время заполнения для 1000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += fillTime(test_vector, 10000);
	}
	cout << "(Vector) Среднее время заполнения для 10000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += fillTime(test_vector, 100000);
	}
	cout << "(Vector) Среднее время заполнения для 100000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += searchTime(A1000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время поиска для 1000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += searchTime(A10000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время поиска для 10000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += searchTime(A100000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время поиска для 100000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += insertionTime(A1000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время добавления для 1000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += insertionTime(A10000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время добавления для 10000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += insertionTime(A100000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время добавления для 100000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += eraseTime(A1000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время удаления для 1000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += eraseTime(A10000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время удаления для 10000 элементов: " << count_vector / 100 << " Сек" << endl;
	count_vector = 0;
	for (int i = 0; i < 100; i++) {
		count_vector += eraseTime(A100000_vector, rand() % 100000);
	}
	cout << "(Vector) Среднее время удаления для 100000 элементов: " << count_vector / 100 << " Сек" << endl;

}