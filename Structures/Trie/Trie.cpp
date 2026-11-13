#include <bits/stdc++.h>


using namespace std;
#define ll long long


class Trie {
private:
    struct node {
        char c;
        int mark;
        vector<node*> children;
        node* par;
        node(char _c) : c(_c), mark(false), par(nullptr) {
            children.assign(26, nullptr);
        };
        node(char _c, bool _mark) : c(_c), mark(_mark), par(nullptr) {
            children.assign(26, nullptr);
        };
    };

    node *root;
    

    
public:

    Trie() {
        root = new node('.');
    }

    void add_string(string s) {
        node *cur = root;
        int ind = 0;
        while (ind < s.size() && cur->children[s[ind]-'a']) {
            cur = cur->children[s[ind]-'a'];
            ind++;
        }
        while (ind < s.size()) {
            cur->children[s[ind] - 'a'] = new node(s[ind]);
            cur = cur->children[s[ind]-'a'];
            ind++;
        }
        cur->mark++;
    }

    bool find_string(string s) {
        node *cur = root;
        int ind = 0;
        while (ind < s.size() && cur->children[s[ind]-'a']) {
            cur = cur->children[s[ind]-'a'];
            ind++;
        }
        if (ind == s.size() && cur->mark) {
            return true;
        }
        return false;   
    }


};