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


using namespace std;
#define ll long long

class node {
private:
    ll value;
    node *l, *r;
    ll lazy;
public:
    node() : value(-1), l(nullptr), r(nullptr), lazy(0) {};
    node(pair<ll, ll> _value) : value(-1), l(nullptr), r(nullptr), lazy(0) {};
    node(pair<ll, ll> _value, node * _l, node * _r) : value(-1), l(_l), r(_r), lazy(0) {};

    ll get_value() {
        return value;
    }

    void set_value(ll x) {
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

    ll get_lazy() {
        return lazy;
    }

    void set_lazy(ll x) {
        lazy = x;
    }
};

class SegmentTree {
private:
    node *root;
    ll n;
    vector<ll> a;
    
    void build(node *nd, ll l, ll r, vector<ll> & a) {
        if (l + 1 == r) {
            nd->set_value(a[l]);
            nd->set_l(nullptr);
            nd->set_r(nullptr);
        } else {
            nd->set_l(new node());
            nd->set_r(new node());
            build(nd->get_l(), l, (l + r) / 2 , a);
            build(nd->get_r(), (l + r) / 2, r, a);
            nd->set_value(max(nd->get_l()->get_value(), nd->get_r()->get_value()));
        }
    }

    void push(node *nd, ll l, ll r) {
        if (l + 1 == r || !nd->get_lazy()) return;
        nd->get_l()->set_lazy(nd->get_l()->get_lazy() + nd->get_lazy());
        nd->get_r()->set_lazy(nd->get_r()->get_lazy() + nd->get_lazy());
        nd->get_l()->set_value(nd->get_l()->get_value() + nd->get_lazy()); 
        nd->get_r()->set_value(nd->get_r()->get_value() + nd->get_lazy()); 
        nd->set_lazy(0);
    }

    ll get(node *nd, ll l, ll r, ll i) {
        push(nd, l, r);
        if (i < l || i >= r) return -1;
        if (l+1 == r) {
            return nd->get_value();
        }
        return max(get(nd->get_l(), l, (l + r) / 2, i), get(nd->get_r(), (l + r) / 2, r, i)); 
    }

    void change(node *nd, ll l, ll r, ll lq, ll rq, ll x) {
        push(nd, l, r);
        if (l >= rq || r <= lq) return;
        if (l >= lq && r <= rq) {
            nd->set_value(nd->get_value()+x);
            nd->set_lazy(x);
            return;
        }
        change(nd->get_l(), l, (l + r) / 2, lq, rq, x);
        change(nd->get_r(), (l + r) / 2, r, lq, rq, x);
        nd->set_value(max(nd->get_l()->get_value(), nd->get_r()->get_value()));
    }

public:
    SegmentTree(vector<ll> & _a) {
        root = new node();
        n = _a.size();
        a = _a;
        build(root, 0, n, _a);
    }

    ll get(ll i) {
        return get(root, 0, n, i);
    }

    void change(ll lq, ll rq, ll x) {
        change(root, 0, n, lq, rq, x);
    }
};
