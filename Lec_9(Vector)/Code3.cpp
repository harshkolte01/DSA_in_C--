#include <iostream>
#include <vector>
using namespace std;


// input output in vectors

int main() {
    int n;
    cout << "Enter no of elements in vector: " << endl;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}