#include <iostream>

/* TODO : 
        Print recursion
        Keep a count of duplicates
*/

// forward declaration
template <class T> class Node;

template <class T>
class BinarySearchTree{
public:
    BinarySearchTree() : root(0) { }
    BinarySearchTree(T val) : root(new Node<T>(val)) { }

    void insert(const T&);
    void print_sorted();

private:
    Node<T>* root;
    void insert(Node<T>*&, Node<T>*&, const T&);
    void print_sorted(Node<T>*);
};


template <class T>
class Node{
friend class BinarySearchTree<T>;
public:
    Node() : left(0), right(0) { }
    Node(T val) : value(val), left(0), right(0) { }
private:
    T value;
    Node<T>* left;
    Node<T>* right;
};


/******************* Member and Nonmember Function Definitions ***************/

template <class T>
void BinarySearchTree<T>::insert(const T& val){
    if (root){ // if root exists, check val against root's value. then recursive call
        if(val < root->value){
            insert(root->left, root, val);            
        }
        else if (val > root->value){
            insert(root->right, root, val);
        }
    } else { // empty tree, insert value here
        root = new Node<T>(val);
    }
}

template <class T>
void BinarySearchTree<T>::insert(Node<T>*& child, Node<T>*& parent, const T& val){
    if (child){
        if(val < child->value){
            insert(child->left, child, val);
        } else if (val > child->value){
            insert(child->right, child, val);
        }
    } else { // node does not exist, child is where we insert new child
        if (val < parent->value){
            child = new Node<T>(val);
            parent->left = child;
        } else if (val > parent->value){
            child = new Node<T>(val);
            parent->right = child;
        }
    }
}

template <class T>
void BinarySearchTree<T>::print_sorted(){
    if (root){
        if(root->left){
            print_sorted(root->left);
        }
        std::cout << root->value << ' ';
        if (root->right){
            print_sorted(root->right);
        }
    }

    std::cout << std::endl;
}

template <class T>
void BinarySearchTree<T>::print_sorted(Node<T>* node){
    if (node){
        if(node->left){
            print_sorted(node->left);
        }
        std::cout << node->value << ' ';
        if (node->right){
            print_sorted(node->right);
        }
    }
}