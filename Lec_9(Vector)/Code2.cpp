#include <iostream>
#include <vector>
using namespace std;

// Linear search
int linearSearch(const vector<int> &vec, int key)
{
    int index = 0;
    for (int val : vec)
    {
        if (val == key)
        {
            return index;
        }
        index++;
    }
    return -1;
}
// Reverse Number
vector<int> revNumber(const vector<int> &vec)
{
    vector<int> reversed;
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        reversed.push_back(vec[i]);
    }
    return reversed;
}

int main()
{
    vector<int> vec = {
        1,
        2,
        10,
        14,
        3,
    };
    vector<int> reversed = revNumber(vec);
    cout << "Reversed vector: ";
    for (int val : reversed)
    {
        cout << val << " ";
    }
    cout << endl;
    int index = linearSearch(vec, 10);

    if (index != -1)
    {
        cout << "Key found at index: " << index << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
}