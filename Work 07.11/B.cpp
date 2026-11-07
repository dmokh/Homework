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
    string name;
    int priority;
public:
    Node(string _name, int _priority) : name(_name), priority(_priority) {};
    ~Node() {}
    void execute() {
        cout << name << "\n";
    }
    int get_priority() {
        return priority;
    }
};

class TaskScheduler {
private:
    vector<Node*> heap;
public:
    TaskScheduler() {
        heap.push_back(nullptr);
    }

    ~TaskScheduler() {
        for (auto p : heap) delete p;
    }

    void add(string name, int priority) {
        Node* New = new Node(name, priority);
        heap.push_back(New);
        int x = heap.size()-1;
        while (x > 1 && heap[x / 2]->get_priority() < heap[x]->get_priority()) {
            swap(heap[x / 2], heap[x]);
            x /= 2;
        }
    }

    void execute() {
        swap(heap[1], heap.back());
        heap.back()->execute();
        heap.pop_back();
        int x = 1;
        while ((2 * x < heap.size() && heap[2 * x]->get_priority() > heap[x]->get_priority()) || (2 * x + 1 < heap.size() && heap[2 * x + 1]->get_priority() > heap[x]->get_priority())) {
            if ((2 * x < heap.size() && heap[2 * x]->get_priority() > heap[x]->get_priority()) && (2 * x + 1 < heap.size() && heap[2 * x + 1]->get_priority() > heap[x]->get_priority())) {
                if (heap[2 * x]->get_priority() > heap[2 * x + 1]->get_priority()) {
                    swap(heap[x], heap[2 * x]);
                    x = 2 * x;
                } else {
                    swap(heap[x], heap[2 * x + 1]);
                    x = 2 * x + 1;
                }
            } else if (2 * x < heap.size() && heap[2 * x]->get_priority() > heap[x]->get_priority()) {
                swap(heap[x], heap[2 * x]);
                x = 2 * x;
            } else {
                swap(heap[x], heap[2 * x + 1]);
                x = 2 * x + 1;
            }
        }
    }

    int size() {
        return heap.size();
    }

};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    TaskScheduler tsh;
    tsh.add("1", 1);
    tsh.add("2", 0);
    tsh.add("3", 2);
    tsh.add("4", 1);
    cout << tsh.size() << '\n';
    for (int i = 0; i < 4; i++) tsh.execute();

    // Я использовал кучу (heap), так как позволяет поддерживать максимальный элемент удаляя и добавляя за O(log n).
    // В альтернативу можно использовать vector, но тогда было бы добавление за O(n), что хуже, но при этом взятие за O(1), что лучше.
}