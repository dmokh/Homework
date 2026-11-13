#include <bits/stdc++.h>


using namespace std;
#define ll long long

class Heap {
private:
    vector<int> heap;

    void push(int x) {
        heap.push_back(x);
        int i = heap.size()-1;
        while (i / 2 >= 1 && heap[i/2] < heap[i]) {
            swap(heap[i/2], heap[i]);
            i /= 2;
        }
    }

    int pop() {
        int x = heap[1];
        swap(heap[1], heap.back());
        heap.pop_back();
        int i = 1;
        while ((2 * i < heap.size() && heap[i] < heap[i*2]) || (2 * i + 1 < heap.size() && heap[i] < heap[i*2+1])) {
            if (2 * i + 1 < heap.size() && heap[i] < heap[2 * i] && heap[i] < heap[2 * i + 1]) {
                if (heap[2 * i + 1] > heap[2 * i]) {
                    swap(heap[i], heap[2 * i + 1]);
                    i = 2 * i + 1;
                } else {
                    swap(heap[i], heap[2 * i]);
                    i = 2 * i;
                }
            } else if (2 * i + 1 < heap.size() && heap[i] < heap[2 * i + 1]) {
                swap(heap[i], heap[2 * i + 1]);
                i = 2 * i + 1;
            } else {
                swap(heap[i], heap[2 * i]);
                i = 2 * i;
            }
        }
        return x;
    }

    

    void print(int i, int cnt = 0) {
        for (int i = 0; i < cnt; i++) cout << ' ';
        cout << heap[i] << '\n';
        
        if (2 * i < heap.size()) {
            for (int i = 0; i < cnt; i++) cout << ' ';
            cout << "L:\n";
            print(2 * i, cnt+1);
        }
        
        if (2 * i + 1 < heap.size()) {
            for (int i = 0; i < cnt; i++) cout << ' ';
            cout << "R:\n";
            print(2 * i + 1, cnt+1);
        }
    }

public:
    Heap() : heap({-1}) {};

    Heap(vector<int> & a) : heap({-1}) {
        for (int & x : a) Push(x);
    }

    void Push(int x) {
        push(x);
    }

    int Pop() {
        if (heap.size() >= 2) {
            return pop();
        } else {
            cout << "Error: attempt to pop in empty heap\n";
            return (1 << 31);
        }
    }

    int top() {
        if (heap.size() >= 2) {
            return heap[1];
        } else {
            cout << "Error: attempt to get top in empty heap\n";
            return (1 << 31);
        }
    }

    int size() {
        return heap.size()-1;
    }

    bool is_empty() {
        return heap.empty();
    }

    void Print() {
        if (heap.size() >= 2) {
            print(1);
        }
    }

};

