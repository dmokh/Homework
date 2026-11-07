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


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int & x : a) cin >> x;
    map<int, vector<int>> rem;
    for (int & x : a) {
        rem[x % k].push_back(x);
    }

    for (auto & [r, v] : rem) {
        cout << r << ": ";
        for (int x : v) cout << x << ' ';
        cout << "\n";
    }


}