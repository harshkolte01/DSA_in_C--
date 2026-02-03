#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    /*
        *
        * *
        * * *
        * * * *

        1
        2 2
        3 3 3
        4 4 4 4
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

    /*
    1
    1 2
    1 2 3
    1 2 3 4
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }

    /*
    1
    2 1
    3 2 1
    4 3 2 1
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    /*
    Floyds triangle pattern
    1
    2 3
    4 5 6
    7 8 9 10

    A
    B C
    D E F
    G H I J
    */
    int num = 1;
    char ch = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }

    /*
    Inverted triangle pattern
    1 1 1 1
      2 2 2
        3 3
          4

    1 1 1 1
     2 2 2
      3 3
       4
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " "; // ADD ONE MORE SPACE << " " FOR NORMAL INVERTED
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << i + 1 << " ";
        }

        cout << endl;
    }



    return 0;
}
