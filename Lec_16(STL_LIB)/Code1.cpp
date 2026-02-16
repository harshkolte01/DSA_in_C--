/*
C++ STL

. Containers

*

· Iterators

· Algorithms

· Functors


*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Basic vector creation
	vector<int> vec1; // empty vector
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	cout << "vec1: ";
	for (int x : vec1) cout << x << " ";
	cout << endl;

	// Vector with initializer list
	vector<int> vec2 = {1, 2, 3};
	cout << "vec2: ";
	for (int x : vec2) cout << x << " ";
	cout << endl;

	// Vector with size and value
	vector<int> vec3(3, 5); // 3 elements, all 5
	cout << "vec3: ";
	for (int x : vec3) cout << x << " ";
	cout << endl;

	// Copy vector
	vector<int> vec4(vec2);
	cout << "vec4 (copy of vec2): ";
	for (int x : vec4) cout << x << " ";
	cout << endl;

	// size, capacity, empty
	cout << "vec1 size: " << vec1.size() << ", capacity: " << vec1.capacity() << endl;
	cout << "vec1 is empty? " << (vec1.empty() ? "Yes" : "No") << endl;

	// at(), front(), back()
	cout << "vec1 at(1): " << vec1.at(1) << endl;
	cout << "vec1 front: " << vec1.front() << endl;
	cout << "vec1 back: " << vec1.back() << endl;

	// pop_back, emplace_back
	vec1.pop_back();
	cout << "vec1 after pop_back: ";
	for (int x : vec1) cout << x << " ";
	cout << endl;
	vec1.emplace_back(99);
	cout << "vec1 after emplace_back(99): ";
	for (int x : vec1) cout << x << " ";
	cout << endl;

	// insert, erase
	vec2.insert(vec2.begin() + 1, 100);
	cout << "vec2 after insert 100 at pos 1: ";
	for (int x : vec2) cout << x << " ";
	cout << endl;
	vec2.erase(vec2.begin() + 2);
	cout << "vec2 after erase at pos 2: ";
	for (int x : vec2) cout << x << " ";
	cout << endl;

	// clear
	vec3.clear();
	cout << "vec3 after clear, size: " << vec3.size() << endl;

	// Forward iterator
	cout << "vec4 forward: ";
	for (auto it = vec4.begin(); it != vec4.end(); ++it) cout << *it << " ";
	cout << endl;

	// Reverse iterator
	cout << "vec4 backward: ";
	for (auto it = vec4.rbegin(); it != vec4.rend(); ++it) cout << *it << " ";
	cout << endl;

	return 0;
}
/*

Vector > Aynamic /reslze

vector<int> vec;

vector<int> vec = {1, 2};

vector<int> vec(3, 10);

vector<int> vec2(vec1);

Vector O(1) fncs

· size & capacity

· push_back & pop_back

· emplace_back

· at() or [ ]

· front & back

Vector O(n) fncs

· erase

· insert

· clear

· empty

Vector

Iterators

· vec.begin

· vec.end

Vector

Iterators

vector<int> :: iterator it;

itr
forward
for(it = vec.begin(); it != vec.end(); it++) {
cout << *(it) << endl;



backward

for(auto it = vec. rbegin() ; it != vec. rend(); it++) {
cout << *(it) << endl;
*/

