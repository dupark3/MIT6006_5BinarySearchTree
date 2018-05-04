#include <iostream>
#include "BinarySearchTree.h"

int main(){
    BinarySearchTree<int> my_tree;
    my_tree.print();
    my_tree.insert(4);
    my_tree.insert(3);
    my_tree.insert(2);
    my_tree.print();
    return 0;
}