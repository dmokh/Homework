#include "heap.h"
#include <iostream>
using namespace std;
int main() {
    Heap heap;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        heap.Push(x);
    }
    while (heap.size() > 1) {
        int x = heap.top(); 
        heap.Pop();
        int y = heap.top();
        heap.Pop();
        if (y != x) {
            heap.Push(x - y);
        }
    } 
    if (heap.is_empty()) {
        cout << 0;
    } else {
        cout << heap.top();
    }
}