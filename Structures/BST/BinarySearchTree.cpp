#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <map>

using namespace std;
#define ll long long

class Node {
public:
    int value;
    Node *l, *r, *par;
    Node() : value(0), l(nullptr), r(nullptr), par(nullptr) {};
    Node(int _value) : l(nullptr), r(nullptr), par(nullptr), value(_value) {}; 

    Node* insert(int data) {
        if (value == data) return nullptr;
        if (value > data) {
            if (l) {
                return l->insert(data);
            } else {
                l = new Node(data);
                l->par = this;
                return l;
            }
        } else {
            if (r) {
                return r->insert(data);
            } else {
                r = new Node(data);
                r->par = this;
                return r;
            }
        }
    }

    Node* find(int data) {
        if (value == data) {
            return this;
        }
        if (value > data) {
            if (!l) return nullptr;
            return l->find(data);
        } else {
            if (!r) return nullptr;
            return r->find(data);
        }
    }

    void print() {
        if (l) l->print();
        cout << value << ' ';
        if (r) r->print();
    }

    
};

class BinarySearchTree {
private:
    int sz = 0;
public:
    Node* root;
    BinarySearchTree() : root(nullptr) {};
    
    void insert(int data) {
        if (!root) {
            root = new Node(data);
            sz++;
            return;
        }
        sz += (bool)root->insert(data);
    }

    void erase(int data) {
        if (!root) {
            cout << "Error: attempt to erase from empty tree\n";
            return;
        }
        Node* node = root->find(data);
        if (!node) {
            cout << "Error: attempt to erase non-exsist element\n";
            return;
        }
        if (node->l) {
            if (node != root) {
                if (node->par->l == node) {
                    node->par->l = node->l;
                    node->l->par = node->par;
                } else {
                    node->par->r = node->l;
                    node->l->par = node->par;
                }
            } else {
                root = node->l;
                node->l->par = nullptr;
            }
            if (node->r) {
                if (node->l->r) {
                    Node* New = node->r->insert(node->l->r->value);
                    New->l = node->l->r->l;
                    if (node->l->r->l) node->l->r->l->par = New;
                    New->r = node->l->r->r;
                    if (node->l->r->r) node->l->r->r->par = New;
                    delete node->l->r;
                }
                node->l->r = node->r;
                if (node->r) {
                    node->r->par = node->l;
                }
            } 
        } else if (node->r) {
            if (node != root) {
                 if (node->par->l == node) {
                    node->par->l = node->r;
                    node->r->par = node->par;
                } else {
                    node->par->r = node->r;
                    node->r->par = node->par;
                }
            } else {
                root = node->r;
                node->r->par = nullptr;
            }
        } else {
            if (node != root) {
                if (node->par->l == node) {
                    node->par->l = nullptr;
                } else {
                    node->par->r = nullptr;
                }
            } else {
                root = nullptr;
            }
        }
        delete node;
    }

    bool contains(int data) {
        if (!root) {
            return false;
        }
        return root->find(data);
    }
    
    void print() {
        if (root) root->print();
    }

    bool empty() {
        return !root;
    }

    int size() {
        return sz;
    }
};
