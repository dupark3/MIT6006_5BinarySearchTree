#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    BinarySearchTree<int> my_tree;
    my_tree.print_sorted(); // attempting to print an empty tree

    my_tree.insert(5);
    my_tree.insert(3);
    my_tree.insert(2);
    my_tree.insert(6);
    my_tree.insert(0);
    my_tree.insert(-10);

    my_tree.print_sorted(); // -10 0 2 3 5 6

    Node<int>* node = my_tree.search(-10);
    cout << node->get_value() << endl;;

    

    return 0;
}