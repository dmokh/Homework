#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <vector>
#include <string>


class Trie {
private:
    struct node {
        char c;
        int mark;
        std::vector<node*> children;
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

    void add_string(std::string s) {
        node *cur = root;
        int ind = 0;
        while (ind < (int)s.size() && cur->children[s[ind]-'a']) {
            cur = cur->children[s[ind]-'a'];
            ind++;
        }
        while (ind < (int)s.size()) {
            cur->children[s[ind] - 'a'] = new node(s[ind]);
            cur = cur->children[s[ind]-'a'];
            ind++;
        }
        cur->mark++;
    }

    bool find_string(std::string s) {
        node *cur = root;
        int ind = 0;
        while (ind < (int)s.size() && cur->children[s[ind]-'a']) {
            cur = cur->children[s[ind]-'a'];
            ind++;
        }
        if (ind == (int)s.size() && cur->mark) {
            return true;
        }
        return false;   
    }


};

#endif