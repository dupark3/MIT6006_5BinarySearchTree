#include <iostream>

/* TODO : 
        Insert recursion
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
    void print();

private:
    Node<T>* root;
    void insert(Node<T>*&, Node<T>*&, const T&);
    void print(Node<T>*);
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
            std::cout << "Going Left" << std::endl;
            insert(root->left, root, val);            
        }
        else if (val > root->value){
            std::cout << "Going Right" << std::endl;
            insert(root->right, root, val);
        }
    } else { // empty tree, insert value here
        std::cout << "Inserting at Root" << std::endl;
        root = new Node<T>(val);
    }
}

template <class T>
void BinarySearchTree<T>::insert(Node<T>*& child, Node<T>*& parent, const T& val){
    if (child){
        if(val < child->value){
            insert(child->left, parent, val);
        } else if (val > child->value){
            insert(child->right, parent, val);
        }
    } else { // node does not exist, child is where we insert new child
        if (val < parent->value){
            std::cout << val << " Connecting parent to left child" << std::endl;
            child = new Node<T>(val);
            parent->left = child;
        } else if (val > parent->value){
            std::cout << "Connecting parent to right child" << std::endl;
            parent->right = new Node<T>(val);
        }
    }
}

template <class T>
void BinarySearchTree<T>::print(){
    if (root){
        Node<T>* temp = root;
        while (temp){
            std::cout << temp->value << ' ';
            temp = temp->left;
        }
    }

    std::cout << std::endl;
}

template <class T>
void BinarySearchTree<T>::print(Node<T>* node){

}