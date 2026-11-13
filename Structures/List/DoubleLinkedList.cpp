#include <iostream>
#include <limits>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct value {
    double data;
    value* next;
    value* prev;
};
class DoublyLinkedList {
private:
    value* header;
    value* last;

public:

    DoublyLinkedList() : header(nullptr), last(nullptr) {};

    ~DoublyLinkedList() {
        clear();
    }

    bool empty() {
        return header == nullptr;
    }

    void push_back(double x) {
        value* it = header;
        while (it != nullptr && it->next != nullptr) {
            it = it->next;
        }
        value *new_el = new value{0, nullptr, nullptr};
        new_el->data = x;
        new_el->prev = it;
        if (it != nullptr) {
            it->next = new_el;
            last = new_el;
        } else {
            header = new_el;
            last = new_el;
        }
    }


    void push_front(double x) {
        value *new_el = new value{0, nullptr, nullptr};
        new_el->data = x;
        new_el->next = header;
        header->prev = new_el;
        header = new_el;
    }

    void insert_before(double x, int i) {
        int j = 0;
        value* it = header;
        while (j != i && it != nullptr && it->next != nullptr) {
            it = it->next;
            j++;
        }
        if (j == i) {
            value* new_el = new value{0, nullptr, nullptr};
            new_el->data = x;
            new_el->prev = it->prev;
            new_el->next = it;
            it->prev->next = new_el;
            it->prev = new_el;
        }
    }

    int size() {
        int i = 0;
        value* it = header;
        while (it != nullptr) {
            it = it->next;
            i++;
        }
        return i;
    }

    void insert_after(double x, int i) {
        int j = 0;
        value* it = header;
        while (j != i && it != nullptr && it->next != nullptr) {
            it = it->next;
            j++;
        }
        if (j == i) {
            value *new_el = new value{0, nullptr, nullptr};
            new_el->data = x;
            new_el->next = it->next;
            new_el->prev = it;
            it->next->prev = new_el;
            it->next = new_el;
            if (i == size() - 1) {
                last = new_el;
            }
        }
    }

    
    void change(double x, int i) {
        int j = 0;
        value* it = header;
        while (j != i && it->next != nullptr) {
            it = it->next;
            j++;
        }
        if (i == j) {
            it->data = x;
            if (i == size() - 1) {
                last = it;
            }
        }
    }

    
    void pop_back() {
        value* it = header;
        while (it->next != nullptr) {
            it = it->next;
        }
        if (it != nullptr) {
            if (it->prev != nullptr) {
                it->prev->next = nullptr;
            } else {
                header = nullptr;
            }
            last = it->prev;
            delete it;
        }
    }

    void pop_front() {
        value *it = header;
        if (it != nullptr) {
            header = header->next;
        }
        if (header != nullptr) {
            header->prev = nullptr;
        }
        delete it;
    }

    void pop(int i) {
        int j = 0;
        value* it = header;
        while (j != i && it->next != nullptr) {
            it = it->next;
            j++;
        }
        if (i == j) {
            if (it != nullptr) {
                if (i == size() - 1) {
                    last = it->prev;
                }
                if (it->prev != nullptr) {
                    it->prev->next = it->next;
                }
                if (it->next != nullptr) {
                    it->next->prev = it->prev;
                }
                delete it;
            }
        }
    }

    void pop_by_value(double x) {
        value* it = header;
        while (it != nullptr && it->data != x) {
            it = it->next;
        }
        if (it != nullptr && it->data == x) {
            if (it->prev != nullptr) {
                it->prev->next = it->next;
            } else {
                header = header->next;
            }
            if (it->next != nullptr) {
                it->next->prev = it->prev;
                last = it->prev;
            }
            delete it;
        }
    }


    void pop_all_by_value(double x) {
        value* it = header;
        while (it != nullptr) {
            if (it->data == x) {
                value* it2 = it;
                if (it->prev != nullptr) {
                    it->prev->next = it->next;
                } else {
                    header = header->next;
                }
                if (it->next != nullptr) {
                    it->next->prev = it->prev;
                }
                if (it == last) {
                    last = it->prev;
                }
                it = it->next;
                delete it2;
            } else {
                it = it->next;
            }
        }
    }

    
    value* find(double x, bool from_begin = true) {
        value* it;
        if (from_begin) {
            it = header;
            while (it != nullptr && x != it->data) {
                it = it->next;
            }
        } else {
            it = last;
            while (it != nullptr && x != it->data) {
                it = it->prev;
            }
        }
        return it;
    }
    
    value* find_max() {
        value* mx = nullptr;
        value* it = header;
        while (it != nullptr) {
            if (mx == nullptr || it->data > mx->data) {
                mx = it;
            }
            it = it->next;
        }
        return it;
    }

    bool is_ordered() {
        value* it = header;
        while (it != nullptr) {
            if (it->prev != nullptr) {
                if (it->prev->data > it->data) {
                    return false;
                }
            }
            it = it->next;
        }
        return true;
    }

   void clear() {
        value* it = header;
        while (it != nullptr) {
            value* it2 = it->next;
            delete it;
            it = it2;
        }
    }

    void print() {
        value* it = header;
        while (it != nullptr) {
            cout << it->data << ' ';
            it = it->next;
        }
    }
    
    value* get(int i) {
        value* it = header;
        int j = 0;
        while (it->next != nullptr && j != i) {
            it = it->next;
            j++;
        }
        return it;
    }

    void add(DoublyLinkedList* list2) {
        value* it = last;
        value* it2 = list2->header;
        while (it2 != nullptr) {
            value *new_el = new value{0, nullptr, nullptr};
            new_el->data = it2->data;
            new_el->prev = it;
            it->next = new_el;
            it = it->next;
            it2 = it2->next;
        }
    }

};

