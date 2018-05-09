#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    cout << "Creating emtpy tree... " << endl;
    BinarySearchTree<int> my_tree;
    my_tree.print_sorted(); // printing an empty tree works

    cout << endl << "Inserting values into tree... " << endl;
    my_tree.insert(5);
    my_tree.insert(4);
    my_tree.insert(2);
    my_tree.insert(3);
    my_tree.insert(8);
    my_tree.insert(10);
    my_tree.insert(6);
    my_tree.insert(0);
    my_tree.insert(1);
    my_tree.print_sorted(); // 0 1 2 3 4 5 6 8 10

    /*
              5
          4      8
        2       6 10
      0  3
       1


    */
    int element = 1;
    cout << endl << "Searching for element " << element << "..." << endl;
    Node<int>* node = my_tree.search(element);
    if (node){
        cout << "Found element " << element << endl;
    } else {
        cout << "Element " << element << " not found. " << endl;
    }

    cout << endl << "Printing all elements within range of (3, 5)... " << endl;
    my_tree.print_range(3, 5);

    cout << endl << "Printing all elements within range of (7, 10)... " << endl;
    my_tree.print_range(7, 10);

    cout << endl << "Removing 1..." << endl;
    my_tree.remove(1);
    my_tree.print_sorted();
    cout << "Removing 4..." << endl;
    my_tree.remove(4);
    my_tree.print_sorted();
    cout << "Removing 5..." << endl;
    my_tree.remove(5);
    my_tree.print_sorted();
    cout << "Removing 8..." << endl;
    my_tree.remove(8);
    my_tree.print_sorted();
    cout << "Removing 3..." << endl;
    my_tree.remove(3);
    my_tree.print_sorted();
    cout << "Removing 6..." << endl;
    my_tree.remove(6);
    my_tree.print_sorted();
    cout << "Removing 2..." << endl;
    my_tree.remove(2);
    my_tree.print_sorted(); // 0 10

    return 0;
}
