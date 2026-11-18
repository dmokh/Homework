#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack st;
    st.add(10);
    st.add(100);
    st.add(50);
    st.pop();
    cout << st.front()->data << '\n';
    st.clear();
    cout << st.isEmpty() << '\n';
}