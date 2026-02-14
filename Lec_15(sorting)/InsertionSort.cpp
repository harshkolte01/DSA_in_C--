#include <iostream>
#include <vector>

using namespace std;

vector<int> ascInsertionSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }
    return arr;
}

vector<int> descInsertionSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] < current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }
    return arr;
}

int main()
{
    vector<int> arr = {3, 1, 10, 9, 2};
    int n = 5;

    vector<int> ascSorted = ascInsertionSort(arr, n);
    for (int x : ascSorted)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> dscSorted = descInsertionSort(arr, n);
    for (int x : dscSorted)
    {
        cout << x << " ";
    }

    return 0;
}