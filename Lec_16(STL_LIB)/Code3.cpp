/*

same as list 

Deque : Double Ended Queue

deque<int> d = {1, 2, 3};

· push_back & push_front

· emplace_back & emplace_front

· pop_back & pop_front

//size, erase, clear, begin, end, rbegin,
rend, insert, front, back
*/

/*
Pair

pair<int, int> p = { 3, 5 };

pair<char, int> p = { 'a', 1 };
*/

#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main() {
pair<int, pair<char, int>> p = {1, {'a', 3}};

cout << p.first << endl; //1
cout << p.second. first << endl; //a
cout << p.second. second << endl; //3

return 0;
}

int Function1() {
vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};

vec.push_back({4, 5}); //insert
vec.emplace_back(4, 5); //in-place objects create

for(auto p : vec) {
cout << p.first << " " << p.second << endl;
    }

return 0;

}