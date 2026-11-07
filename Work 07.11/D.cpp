#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <map>
#include <stack>


using namespace std;
#define ll long long


struct SegmentTree {
private:
    int n;
    vector<int> tree;
    void build(int v, int l, int r, vector<int> & a) {
        if (l + 1 == r) {
            tree[v] = a[l];
        } else {
            build(2 * v + 1, l, (l + r) / 2, a);
            build(2 * v + 2, (l + r) / 2, r, a);
            tree[v] = tree[2 * v + 1] + tree[2* v + 2];
        }
    }
    int sum(int v, int l, int r, int ql, int qr) {
        if (l >= qr || r <= ql) {
            return 0;
        }
        if (l >= ql && r <= qr) {
            return tree[v];
        }
        return sum(2 * v + 1, l, (l + r) / 2, ql, qr) + sum(2 * v + 2, (l + r) / 2, r, ql, qr);
    }
public:
    SegmentTree(vector<int> & a) : n(a.size()) {
        tree.assign(n * 4 + 1, 0);
        build(0, 0, n, a);
    }

    ~SegmentTree() {};

    int sum(int l, int r) {
        return sum(0, 0, n, l, r);
    }
};  

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k, q; cin >> n >> k >> q;

    vector<int> a(n);
    for (int & x : a) {
        cin >> x;
        x = (x % k == 0);
    }
    SegmentTree st(a);

    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.sum(l, r+1) << '\n';
    }


}