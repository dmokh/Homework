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

class Inventory {
private:
    map<string, int> counter;
public:
    Inventory() {};
    ~Inventory() {};
    void addItem(string name, int count) {
        counter[name] += count;
    }

    bool removeItem(string name, int count) {
        if (counter[name] >= count) {
            counter[name] -= count;
            return true;
        } else {
            return false;
        }
    }

    int getCount(string name) {
        return counter[name];
    }

    void print() {
        for (auto & [name, count] : counter) {
            if (count) {
                cout << name << ' ';
            }
        }
        cout << '\n';
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    Inventory inv;
    inv.addItem("potatos", 100);
    inv.addItem("Ogurchiki", 2);
    inv.removeItem("potatos", 50);
    inv.removeItem("Ogurchiki", 3);
    cout << inv.getCount("potatos") << ' ' << inv.getCount("Ogurchiki") << '\n';
    inv.removeItem("Ogurchiki", 2);
    inv.print();


}