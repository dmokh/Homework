#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>

class Heap {
private:
    std::vector<int> heap;

    void push(int x) {
        heap.push_back(x);
        int i = (int)heap.size()-1;
        while (i / 2 >= 1 && heap[i/2] < heap[i]) {
            std::swap(heap[i/2], heap[i]);
            i /= 2;
        }
    }

    int pop() {
        if (this->is_empty()) {
            throw std::out_of_range("Heap is empty");
        }
        int x = heap[1];
        std::swap(heap[1], heap.back());
        heap.pop_back();
        int i = 1;
        while ((2 * i < (int)heap.size() && heap[i] < heap[i*2]) || (2 * i + 1 < (int)heap.size() && heap[i] < heap[i*2+1])) {
            if (2 * i + 1 < (int)heap.size() && heap[i] < heap[2 * i] && heap[i] < heap[2 * i + 1]) {
                if (heap[2 * i + 1] > heap[2 * i]) {
                    std::swap(heap[i], heap[2 * i + 1]);
                    i = 2 * i + 1;
                } else {
                    std::swap(heap[i], heap[2 * i]);
                    i = 2 * i;
                }
            } else if (2 * i + 1 < (int)heap.size() && heap[i] < heap[2 * i + 1]) {
                std::swap(heap[i], heap[2 * i + 1]);
                i = 2 * i + 1;
            } else {
                std::swap(heap[i], heap[2 * i]);
                i = 2 * i;
            }
        }
        return x;
    }

    

    void print(int i, int cnt = 0) {
        for (int i = 0; i < cnt; i++) std::cout << ' ';
        std::cout << heap[i] << '\n';
        
        if (2 * i < (int)heap.size()) {
            for (int i = 0; i < cnt; i++) std::cout << ' ';
            std::cout << "L:\n";
            print(2 * i, cnt+1);
        }
        
        if (2 * i + 1 < (int)heap.size()) {
            for (int i = 0; i < cnt; i++) std::cout << ' ';
            std::cout << "R:\n";
            print(2 * i + 1, cnt+1);
        }
    }

public:
    Heap() : heap({-1}) {};

    Heap(std::vector<int> & a) : heap({-1}) {
        for (int & x : a) Push(x);
    }

    void Push(int x) {
        push(x);
    }

    int Pop() {
        if (heap.size() >= 2) {
            return pop();
        } else {
            std::cout << "Error: attempt to pop in empty heap\n";
            return (1 << 31);
        }
    }

    int top() {
        if (heap.size() >= 2) {
            return heap[1];
        } else {
            std::cout << "Error: attempt to get top in empty heap\n";
            return (1 << 31);
        }
    }

    int size() {
        return (int)heap.size()-1;
    }

    bool is_empty() {
        return heap.size() == 1;
    }

    void Print() {
        if (heap.size() >= 2) {
            print(1);
        }
    }

};

#endif