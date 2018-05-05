#include <iostream>

/* TODO : 
        Refactor remove(Node, Node) to smaller functions    
        Keep a count of duplicates
*/

// forward declaration
template <class T> class Node;

template <class T>
class BinarySearchTree{
public:
    BinarySearchTree() : root(0) { }
    BinarySearchTree(T val) : root(new Node<T>(val)) { }

    Node<T>* search(const T&);
    void insert(const T&);
    void remove(const T&);
    void print_range(const T&, const T&);
    void print_sorted();

private:
    Node<T>* root;
    Node<T>* inorder_successor(Node<T>*);
    // overloaded functions to serve as recursive calls within search, insert, remove, print
    Node<T>* search(Node<T>*&, const T&);
    void remove(Node<T>*, Node<T>*, const T&);
    void remove(Node<T>*, Node<T>*);
    void insert(Node<T>*&, Node<T>*&, const T&);
    void print_sorted(Node<T>*);
};


template <class T>
class Node{
friend class BinarySearchTree<T>;
public:
    Node() : left(0), right(0), parent(0) { }
    Node(T val) : value(val), left(0), right(0), parent(0) { }

    T get_value() { return value; }

private:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
};


/******************* Member and Nonmember Function Definitions ***************/

template <class T>
Node<T>* BinarySearchTree<T>::search(const T& val){
    if(root){
        if (val < root->value){
            return search(root->left, val);
        } else if (val > root->value){
            return search(root->right, val);
        } else if (val == root->value){
            return root;
        }
    } else {
        return 0;
    }
}

template <class T>
Node<T>* BinarySearchTree<T>::search(Node<T>*& node, const T& val){
    if(node){
        if (val < node->value){
            return search(node->left, val);
        } else if (val > node->value){
            return search(node->right, val);
        } else if (val == node->value){
            return node;
        }
    } else {
        return 0;
    }
}

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
    } else { // node does not exist, child is where we insert the element
        if (val < parent->value){
            child = new Node<T>(val);
            parent->left = child;
            child->parent = parent;
        } else if (val > parent->value){
            child = new Node<T>(val);
            parent->right = child;
            child->parent = parent;
        }
    }
}

template <class T>
void BinarySearchTree<T>::remove(const T& val){
    if (root){
        if (val < root->value){
            remove(root->left, root, val);
        } else if (val > root->value){
            remove(root->right, root, val);
        } else if (val == root->value){
            remove(root, 0); // value found, delete this root
        }
    } 
}

template <class T>
void BinarySearchTree<T>::remove(Node<T>* node, Node<T>* parent, const T& val){
    if (node){
        if (val < node->value){
            remove(node->left, node, val);
        } else if (val > node->value){
            remove(node->right, node, val);
        } else if (val == node->value){
            remove(node, parent); // value found, delete this node
        }
    } 
}

template <class T>
void BinarySearchTree<T>::remove(Node<T>* node, Node<T>* parent){
    // node is a leaf, set his parent's left or right pointer to null and delete node
    if (!node->left && !node->right){
        if (parent->left == node) 
            parent->left = 0;
        else if (parent->right == node) 
            parent->right = 0;
        delete node;
    }

    // node has one left child, set node's parent's correct pointer to the node's left child
    else if (node->left && !node->right){
        if (parent->left == node){
            parent->left = node->left;
            parent->left->parent = parent;
        }
        else if (parent->right == node){
            parent->right = node->left;
            parent->right->parent = parent;
        }
        delete node;
    } 

    // node has one right child, set node's parent's correct pointer to the node's right child
    else if (!node->left && node->right){
        if (parent->left == node){
            parent->left = node->right;
            parent->left->parent = parent;
        }
        else if (parent->right == node){
            parent->right = node->right;
            parent->right->parent = parent;
        }
        delete node;
    }

    // node has both children, copy inorder successor's value and remove that node
    else if (node->left && node->right){
        // find inorder successor and copy its value into the node with value we are removing
        Node<T>* successor = inorder_successor(node);
        node->value = successor->value;
        remove(successor, successor->parent);
    }
}

template <class T>
Node<T>* BinarySearchTree<T>::inorder_successor(Node<T>* node){
    Node<T>* successor;
    // if it has a right child, inorder successor is the right child's left most leaf
    if (node->right){
        successor = node->right;
        while(successor->left){                
            successor = successor->left;
        }
    } 

    // if only left child, inorder successor is its parent
    else if (node->left && !node->right){
        successor = node->parent;
    } 

    // if a leaf, keep going up the parent pointer until its value is larger
    else if (!node->left && !node->right){
        successor = node->parent;
        while(successor->value < node->value){
            successor = successor->parent;
        }
    }

    return successor;
}

template <class T>
void BinarySearchTree<T>::print_range(const T& min, const T& max){
    // search min, if found, print it
    // loop: find the inorder successor, print it if less than max
    // if more than max, we are done. 
    // search min, if not found, the spot's parent is the inorder successor
    Node<T>* min_node = search(min);
    if(min_node){
        std::cout << min_node->value << ' ';
        while(min_node->value < max){
            min_node = inorder_successor(min_node);
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