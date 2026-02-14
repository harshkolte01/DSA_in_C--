#include <iostream>
#include <vector>

using namespace std;

vector<int> ascSelectionSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int smallestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
    return arr;
}

vector<int> descSelectionSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int largestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[largestIdx])
            {
                largestIdx = j;
            }
        }
        swap(arr[i], arr[largestIdx]);
    }
    return arr;
}

int main()
{
    vector<int> arr = {3, 1, 10, 9, 2};
    int n = 5;

    vector<int> ascSorted = ascSelectionSort(arr, n);
    for (int x : ascSorted)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> dscSorted = descSelectionSort(arr, n);
    for (int x : dscSorted)
    {
        cout << x << " ";
    }

    return 0;
}