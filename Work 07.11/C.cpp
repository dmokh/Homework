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

class Node {
public:
    bool mark;
    Node* par;
    Node* children[26];
    Node() {};
    ~Node() {
        for (Node * v : children) {
            if (v) {
                delete v;
            }
        }
    }
};

class Trie {
private:
    Node* root;
    bool dfs(Node* v, string s, int ind, bool broken) {
        if (ind == s.size()) {
            bool fl = (v->mark && broken) || (v->par->mark && !broken);
            for (Node* nd : v->children) {
                if (nd) {
                    fl = fl || (nd->mark && !broken);
                }
            }
            return fl;
        }
        bool fl = false;
        if (v->children[s[ind] - 'a']) {
            fl = fl || dfs(v->children[s[ind] - 'a'], s, ind+1, broken);
        }
        if (!broken) {
            for (int c = 0; c < 26; c++) {
                if (v->children[c] && c != s[ind] - 'a') {
                    fl = fl || dfs(v->children[c], s, ind+1, true);
                }
            }
        }
        return fl;
    }
public:
    Trie() : root(new Node()) {};
    ~Trie() {
        delete root;
    }
    void add(string s) {
        Node* cur = root;
        int ind = 0;
        while (ind < s.size() && cur->children[s[ind] - 'a']) {
            cur = cur->children[s[ind] - 'a'];
            ind++;
        }
        while (ind < s.size()) {
            cur->children[s[ind] - 'a'] = new Node();
            cur->children[s[ind] - 'a']->par = cur;
            cur = cur->children[s[ind] - 'a'];
            ind++;
        }
        cur->mark = true;
    }
    bool check(string s) {
        return dfs(root, s, 0, false);
    }
    
};  


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    Trie bor;
    while (n--) {
        string s; cin >> s;
        bor.add(s);
    }
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        if (bor.check(s)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
}