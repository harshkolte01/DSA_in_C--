#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for (int i =0; i < n; i++) {
        //space
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        // left side num
        for (int j = 1; j <= i + 1; j++) {
            cout << j;
        }

        // right side num
        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }

    /*
         1
        121
       12321
      1234321
    
    */
    
}