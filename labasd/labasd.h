#include <iostream>
#include <vector>
using namespace std;


class BinaryTree {
public:
    static int count_completion;
    static int count_search;
    static int count_del;
    class Node {
    public:
        int key;
        Node* left;
        Node* right;
        Node() : key(0), left(nullptr), right(nullptr) {}
        Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
        ~Node() {
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
                    count_completion++;
                    left = new Node(_key);
                }
                else {
                    count_completion++;
                    return left->insert(_key);
                }
            }
            else if (_key > key) {
                if (right == nullptr) {
                    count_completion++;
                    right = new Node(_key);
                }
                else {
                    count_completion++;
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
        bool Findelem(int _key) {
            if (_key == key) {
                count_search++;
                return true;
            }
            if (_key < key) {
                count_search++; 
                if (left != nullptr) {
                    count_search++;
                    return left->Findelem(_key);
                }  
            }
            else {
                count_search;
                if (right != nullptr) {
                    count_search++;
                    return right->Findelem(_key);
                }
            }
            return false;
        }
    };
     Node* root;

   

    Node* copyTree(const Node* node) {
        if (node == nullptr) return nullptr;
        Node* newNode = new Node(node->key);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    void erase(Node*& node, int _key) {
        if (node == nullptr) return;
        if (_key < node->key) {
            count_del++;
            erase(node->left, _key);
        }
        else if (_key > node->key) {
            count_del++;
            erase(node->right, _key);
        }
        else {
            count_del++;
            if (node->left == nullptr) {
                count_del++;
                Node* temp = node->right;
                node->right = nullptr;
                delete node;
                node = temp;
            }
            else if (node->right == nullptr) {
                count_del++;
                Node* temp = node->left;
                node->left = nullptr;
                delete node;
                node = temp;
            }
            else {
                count_del++;
                Node* minRight = node->right;
                while (minRight->left != nullptr) {
                    minRight = minRight->left;
                }
                node->key = minRight->key;
                erase(node->right, minRight->key);
            }
        }
    }

public:
    int get_key() {
        return root->key;
    }
    Node* get_left() {
        return root->left;
    }
    bool Findelem(int _key) {
        return root->Findelem(_key);
    }
    int get_count_completion() {
        return count_completion;
    }
    int get_count_search() {
        return count_search;
    }
    int get_count_del() {
        return count_del;
    }
    BinaryTree(int key) : root(new Node(key)) {}
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
bool find(const vector<int>& task, int value) {
    for (int element : task) {
        if (element == value) {
            return true;
        }
    }
    return false;
}
vector<int> search_intersection(const BinaryTree::Node* A,const BinaryTree::Node* B) {
    vector<int> arr_intersection;
    if (A == nullptr || B == nullptr) {
        return arr_intersection;
    }
    if (A->key == B->key) {
        arr_intersection.push_back(A->key);
    }
    vector<int> left_intersection_A = search_intersection(A->left, B);
    vector<int> right_intersection_A = search_intersection(A->right, B);
    vector<int> left_intersection_B = search_intersection(A, B->left);
    vector<int> right_intersection_B = search_intersection(A, B->right);
    for (int i : left_intersection_A) {
        if (!find(arr_intersection, i)) {
            arr_intersection.push_back(i);
        }
    }
    for (int i : right_intersection_A) {
        if (!find(arr_intersection, i)) {
            arr_intersection.push_back(i);
        }
    }
    for (int i : left_intersection_B) {
        if (!find(arr_intersection, i)) {
            arr_intersection.push_back(i);
        }
    }
    for (int i : right_intersection_B) {
        if (!find(arr_intersection, i)) {
            arr_intersection.push_back(i);
        }
    }
    return arr_intersection;
}
vector<int> converter(const BinaryTree::Node* other) {
    vector <int> convert;
    vector<int> convert_right;
    vector<int> convert_left;
    convert.push_back(other->key);
    if(other->left != nullptr){
        convert_left = converter(other->left);
        
    }
    if (other->right != nullptr) {
        convert_right = converter(other->right);
    }
    for (int i : convert_right) {
        if (!find(convert, i)) {
            convert.push_back(i);
        }
    }
    for (int i : convert_left) {
        if (!find(convert, i)) {
            convert.push_back(i);
        }
    }
    return convert;
}
vector<int> difference(const vector<int>& A,const vector<int>& B) {
    vector<int> difference;
    for (int i : A) {
        if (!find(B, i) && !find(difference, i)) {
            difference.push_back(i);
        }
    }
    for (int i : B) {
        if (!find(A, i) && !find(difference, i)) {
            difference.push_back(i);
        }
    }
    return difference;
}
vector<int> search_difference(const BinaryTree::Node* A, const BinaryTree::Node* B) {
    vector<int> arr_intersection;
    if (A == nullptr || B == nullptr) {
        return arr_intersection;
    }
    arr_intersection = difference(converter(A), converter(B));
    return arr_intersection;
}

    