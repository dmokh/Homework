#include <iostream>
#include "trie.h"
using namespace std;
int main() {
    Trie bor;
    bor.add_string("ss");
    cout << bor.find_string("ss") << '\n';

}