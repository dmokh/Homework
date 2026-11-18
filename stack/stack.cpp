#include <iostream>
#include "stack.h"

using namespace std;

void my_sort(Stack & stack) {
    Stack stack2;
    while (!stack.isEmpty()) {
        int x = stack.front()->data;
        stack.pop();
        int cnt = 0;
        while (!stack2.isEmpty() && stack2.front()->data > x) {
            cnt++;
            stack.add(stack2.front()->data);
            stack2.pop();
        }
        stack2.add(x);
        for (int i = 0; i < cnt; i++) {
            stack2.add(stack.front()->data);
            stack.pop();
        }
    }
    while (!stack2.isEmpty()) {
        stack.add(stack2.front()->data);
        stack2.pop();
    }
}


int main() {
    Stack st;
    for (int x : {10, 10, 5, 15, 15, 4, 8, 10}) {
        st.add(x);
    }
    my_sort(st);
    while (!st.isEmpty()) {
        cout << st.front()->data << ' ';
        st.pop();
    }
}