#include <iostream>
#include <vector>

using namespace std;

vector<int> ascBubbleSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

vector<int> descBubbleSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {3, 1, 10, 9, 2};
    int n = 5;

    vector<int> ascSorted = ascBubbleSort(arr, n);
    for (int x : ascSorted)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> dscSorted = descBubbleSort(arr, n);
    for (int x : dscSorted)
    {
        cout << x << " ";
    }

    return 0;
}