#include <iostream>
#include "list.h"
using namespace std;


int main() {
    DoublyLinkedList ls;
    ls.push_back(5);
    ls.push_back(100);
    ls.push_back(10);
    cout << ls.get(0)->data << ' ' << ls.get(1)->data << ' ' << ls.get(2)->data << '\n';
}