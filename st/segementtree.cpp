#include <iostream>
#include "segmenttree.h"
using namespace std;

int main() {
    vector<int> a = {1, 10};
    SegmentTree st(a);
    cout << st.get(1) << '\n';
}