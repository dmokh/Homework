#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.erase(10);
    cout << bst.empty() << '\n';
}