/*
List

list<int> l = {1, 2, 3};

( dowsly Linked dit)

· push_back & push_front

· emplace_back & emplace_front

· pop_back & pop_front

//size, erase, clear, begin, end, rbegin,
rend, insert, front, back
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(5);

    l.pop_back();
    l.pop_front();
    for (int val : l) {
        cout << val << " ";
    }
    return 0;
}