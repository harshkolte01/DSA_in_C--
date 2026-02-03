#include <iostream>
using namespace std;

// Type casting (implicit and explicit)

int main() {

    // implicit small -> big
    char grade = 'a';
    int value = grade;
    cout << value << endl;

    // explicit big -> small
    double price = 110.93;
    int newp = int(price);
    cout << newp << endl;
    return 0;
}