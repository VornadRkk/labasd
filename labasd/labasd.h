// labasd.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>

using namespace std;
class Tree {
	int key;
	Tree* left;
	Tree* right;
public:
	Tree() :left(nullptr), right(nullptr), key(0) {};
	Tree(int key) :left(nullptr), right(nullptr), key(key) {};
	Tree(const Tree& other) {
		key = other.key;
		if (other.left) {
			left = new Tree(*other.left);
		}
		else {
			left = nullptr;
		}
		if (other.right) {
			right = new Tree(*other.right);
		}
		else {
			right = nullptr;
		}
	}
	~Tree() {
		delete left;
		delete right;
	}
	Tree& operator=(const Tree& other) {
		if (this != &other){
			key = other.key;
			if (other.left) {
				left = new Tree(*other.left);
			}
			else {
				left = nullptr;
			}
			if (other.right) {
				right = new Tree(*other.right);
			}
			else {
				right = nullptr;
			}
		}
		return *this;
	}
	void print() {
		cout << key << endl;
		if (left) {
			left->print();
		}
		if (right) {
			right->print();
		}
	}
	bool insert(int _key) {
		if (_key < key) {
			if (left == nullptr) {
				left = new Tree(_key);
			}
			else {
				left->insert(_key);
			}
		}
		if (_key > key) {
			if (right == nullptr) {
				right = new Tree(_key);
			}
			else {
				right->insert(_key);
			}
		}
		return false;
	}
	bool contains(int _key) {
		if (_key == key) {
			return true;
		}
		bool found = false;
		if (left) {
			found = left->contains(_key);
		}
		if (!found && right) {
			found = right->contains(_key);
		}
		return found;
	}

};