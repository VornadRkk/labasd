#include <iostream>
#include <vector>
#include <functional>



class BinaryTree {
    
    // todo
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
            std::cout << key << std::endl;
            if (left) left->print();
            if (right) right->print();
        }
        bool insert(int _key) {
            if (_key < key) {
                if (left == nullptr) {
                    left = new Node(_key);
                }
                else {
                    return left->insert(_key);
                }
            }
            else if (_key > key) {
                if (right == nullptr) {
                    right = new Node(_key);
                }
                else {
                    return right->insert(_key);
                }
            }
            return false;
        }
        bool contains(int _key)const {
            if (_key == key) return true;
            if (_key < key && left) return left->contains(_key);
            if (_key > key && right) return right->contains(_key);
            return false;
        }
        bool Findelem(int _key) {
            if (_key == key) {
                return true;
            }
            if (_key < key) {
                if (left != nullptr) {
                    return left->Findelem(_key);
                }  
            }
            else {
                if (right != nullptr) {
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
            erase(node->left, _key);
        }
        else if (_key > node->key) {
            erase(node->right, _key);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                node->right = nullptr;
                delete node;
                node = temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                node->left = nullptr;
                delete node;
                node = temp;
            }
            else if(node->right == nullptr && node->left == nullptr) {
                Node* minRight = node->right;
                while (minRight->left != nullptr) {
                    minRight = minRight->left;
                }
                node->key = minRight->key;
                erase(node->right, minRight->key);
            }
            else {
                delete node;
            }
        }
    }

public:
    BinaryTree() :root(nullptr) {};
    bool Findelem(int _key) {
        return root->Findelem(_key);
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
    void print() const {
        if (root != nullptr) root->print();
    }
    bool insert(int _key) {
        if (!root) {
            root = new Node(_key);
        }
        return root->insert(_key);
    }
    bool contains(int _key)const  {
        return root->contains(_key);
    }
    void erase(int _key) {
        erase(root, _key);
    }
    static void walk(const Node* other,std::vector<int>& vec) {
        if (!other) {
            return;
        }
        walk(other->left, vec);
        vec.push_back(other->key);
        walk(other->right, vec);
    }
    std::vector<int> to_vector() const {
        std::vector <int> convert;
        walk(root, convert);
        convert.push_back(root->key);
        return convert;
    }

    //void walk(std::function<int> f) const {
    //    //

    //}
};


BinaryTree search_intersection(const BinaryTree& A,const BinaryTree& B) {
    BinaryTree result;

    for (auto i : A.to_vector()) {
        if (B.contains(i))
            result.insert(i);
    }
    return result;
}

//vector<int> difference(const vector<int>& A,const vector<int>& B) {
//    vector<int> difference;
//    for (int i : A) {
//        if (!find(B, i) && !find(difference, i)) {
//            difference.push_back(i);
//        }
//    }
//    for (int i : B) {
//        if (!find(A, i) && !find(difference, i)) {
//            difference.push_back(i);
//        }
//    }
//    return difference;
//}
BinaryTree search_difference(const BinaryTree& A, const BinaryTree& B) {
    BinaryTree result;

    for (auto i : A.to_vector()) {
        if (B.contains(i))
            result.insert(i);
    }
    return result;
}

    