#include <iostream>
#include "BinarySearchTree.h"

int main(){
    BinarySearchTree<int> my_tree;
    my_tree.insert(5);
    my_tree.insert(3);
    my_tree.insert(2);
    my_tree.insert(6);
    my_tree.insert(0);
    my_tree.insert(-10);
    my_tree.insert(-10);

    my_tree.print_sorted();
    return 0;
}