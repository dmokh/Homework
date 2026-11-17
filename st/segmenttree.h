#ifndef ST_H
#define ST_H
#include <iostream>
#include <vector>

class node {
private:
    int value;
    node *l, *r;
    int lazy;
public:
    node() : value(-1), l(nullptr), r(nullptr), lazy(0) {};
    node(std::pair<int, int> _value) : value(-1), l(nullptr), r(nullptr), lazy(0) {};
    node(std::pair<int, int> _value, node * _l, node * _r) : value(-1), l(_l), r(_r), lazy(0) {};

    int get_value() {
        return value;
    }

    void set_value(int x) {
        value = x;
    }

    node* get_l() {
        return l;
    }
    
    void set_l(node* x) {
        l = x;
    }

    node* get_r() {
        return r;
    }
    
    void set_r(node* x) {
        r = x;
    }

    int get_lazy() {
        return lazy;
    }

    void set_lazy(int x) {
        lazy = x;
    }
};

class SegmentTree {
private:
    node *root;
    int n;
    std::vector<int> a;
    
    void build(node *nd, int l, int r, std::vector<int> & a) {
        if (l + 1 == r) {
            nd->set_value(a[l]);
            nd->set_l(nullptr);
            nd->set_r(nullptr);
        } else {
            nd->set_l(new node());
            nd->set_r(new node());
            build(nd->get_l(), l, (l + r) / 2 , a);
            build(nd->get_r(), (l + r) / 2, r, a);
            nd->set_value(std::max(nd->get_l()->get_value(), nd->get_r()->get_value()));
        }
    }

    void push(node *nd, int l, int r) {
        if (l + 1 == r || !nd->get_lazy()) return;
        nd->get_l()->set_lazy(nd->get_l()->get_lazy() + nd->get_lazy());
        nd->get_r()->set_lazy(nd->get_r()->get_lazy() + nd->get_lazy());
        nd->get_l()->set_value(nd->get_l()->get_value() + nd->get_lazy()); 
        nd->get_r()->set_value(nd->get_r()->get_value() + nd->get_lazy()); 
        nd->set_lazy(0);
    }

    int get(node *nd, int l, int r, int i) {
        push(nd, l, r);
        if (i < l || i >= r) return -1;
        if (l+1 == r) {
            return nd->get_value();
        }
        return std::max(get(nd->get_l(), l, (l + r) / 2, i), get(nd->get_r(), (l + r) / 2, r, i)); 
    }

    void change(node *nd, int l, int r, int lq, int rq, int x) {
        push(nd, l, r);
        if (l >= rq || r <= lq) return;
        if (l >= lq && r <= rq) {
            nd->set_value(nd->get_value()+x);
            nd->set_lazy(x);
            return;
        }
        change(nd->get_l(), l, (l + r) / 2, lq, rq, x);
        change(nd->get_r(), (l + r) / 2, r, lq, rq, x);
        nd->set_value(std::max(nd->get_l()->get_value(), nd->get_r()->get_value()));
    }

public:
    SegmentTree(std::vector<int> & _a) {
        root = new node();
        n = _a.size();
        a = _a;
        build(root, 0, n, _a);
    }

    int get(int i) {
        if (i >= n || i < 0) {
            throw std::out_of_range("Index is invalid");
        }
        return get(root, 0, n, i);
    }

    void change(int lq, int rq, int x) {
        if (lq < 0 || rq < 0 || lq >= n || rq >= n) {
            throw std::out_of_range("Index is invalid");
        }
        change(root, 0, n, lq, rq, x);
    }
};

#endif