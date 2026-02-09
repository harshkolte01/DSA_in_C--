#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


// sum of elements
int sumOfElements(const vector<int>& vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return sum;
}

// find max and min
void min_and_max(const vector<int>& vec) {
    int max = vec[0];
    int min = vec[0];
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] > max) {
            max = vec[i];
        }
        if (vec[i] < min) {
            min = vec[i];
        }
    }
    cout << "Maximum: " << max << " Minimum: " << min << endl;
}

// count even numbers
int countEvenn(const vector<int>& vec) {
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// remove all occurances
void removeOcc(vector<int>& vec, int x) {
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it == x) {
            it = vec.erase(it); // erase returns the next iterator
        } else {
            ++it;
        }
    }
}



int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    
    // cout << countEvenn(vec);
    // min_and_max(vec);
    // cout << sumOfElements(vec) << endl;
    return 0;
}