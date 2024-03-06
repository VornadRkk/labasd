#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Tree {
        int key;
        Tree* left;
        Tree* right;

        Tree(int _key) : key(_key), left(nullptr), right(nullptr) {}

        ~Tree() {
            delete left;
            delete right;
        }

        void print() {
            cout << key << endl;
            if (left) left->print();
            if (right) right->print();
        }

        bool insert(int _key) {
            if (_key < key) {
                if (left == nullptr) {
                    left = new Tree(_key);
                }
                else {
                    return left->insert(_key);
                }
            }
            else if (_key > key) {
                if (right == nullptr) {
                    right = new Tree(_key);
                }
                else {
                    return right->insert(_key);
                }
            }
            return false;
        }

        bool contains(int _key) {
            if (_key == key) return true;
            if (_key < key && left) return left->contains(_key);
            if (_key > key && right) return right->contains(_key);
            return false;
        }
    };

    Tree* root;

    Tree* copyTree(const Tree* node) {
        if (node == nullptr) return nullptr;
        Tree* newNode = new Tree(node->key);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    void erase(Tree*& node, int _key) {
        if (node == nullptr) return;
        if (_key < node->key) {
            erase(node->left, _key);
        }
        else if (_key > node->key) {
            erase(node->right, _key);
        }
        else {
            if (node->left == nullptr) {
                Tree* temp = node->right;
                node->right = nullptr;
                delete node;
                node = temp;
            }
            else if (node->right == nullptr) {
                Tree* temp = node->left;
                node->left = nullptr;
                delete node;
                node = temp;
            }
            else {
                Tree* minRight = node->right;
                while (minRight->left != nullptr) {
                    minRight = minRight->left;
                }
                node->key = minRight->key;
                erase(node->right, minRight->key);
            }
        }
    }

public:
    BinaryTree(int key) : root(new Tree(key)) {}

    ~BinaryTree() {
        delete root;
    }

    BinaryTree(const BinaryTree& other) {
        root = copyTree(other.root);
    }

    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            delete root;
            root = copyTree(other.root);
        }
        return *this;
    }

    void print() {
        if (root != nullptr) root->print();
    }

    bool insert(int _key) {
        return root->insert(_key);
    }

    bool contains(int _key) {
        return root->contains(_key);
    }

    void erase(int _key) {
        erase(root, _key);
    }
};
