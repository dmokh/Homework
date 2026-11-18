#ifndef STACK_H
#define STACK_H

struct value {
    double data;
    value* next;
    value* prev;
    value(double _data, value* _next, value* _prev) : data(_data), next(_next), prev(_prev) {};
};

class Stack {
private:
    value* header;

public:

    Stack() : header(nullptr) {};

    ~Stack() {
        clear();
    }

    bool isEmpty() {
        return header == nullptr;
    }

    void add(double x) {
        value* new_el = new value(x, header, nullptr);
        if (header != nullptr) {
            header->prev = new_el;
        }
        header = new_el;
    }

    void pop() {
        value* it = header;
        if (header != nullptr) {
            header = header->next;
        }
        if (header != nullptr) {
            header->prev = nullptr;
        }
        if (it) {
            delete it;
        } else {
            throw std::out_of_range("List is empty");
        }
    }

    int size() {
        int x = 0;
        value* it = header;
        while (it != nullptr) {
            x++;
            it = it->next;
        }
        return x;
    }

    value* front() {
        return header;
    }

    void clear() {
        value* it = header;
        while (it != nullptr) {
            value *it2 = it;
            it = it->next;
            delete it2;
        }
        header = nullptr;
    }

};

#endif