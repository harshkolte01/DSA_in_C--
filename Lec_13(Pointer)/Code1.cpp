#include <iostream>
#include <vector>
using namespace std;

void pointers() {
    int *ptr1 = NULL;
    cout << &ptr1 << endl;
}

int main() {
    int a = 10;
    int* ptr =  &a;
    int** parptr = &ptr;

    cout << &ptr << endl;
    cout << &parptr << endl;
    cout << **(parptr) << endl;

    pointers();
    return 0;
}

/*
pointers pass by reference (detail explain)

array pointers 

pointer arithematic
increment decrement
add subtract

pointer pointer value substraction allowed if type same


*/