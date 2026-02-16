#include <iostream>
#include <string>

using namespace std;

/*
why string are better than charArray

runtime change
comparison btwn arrays


loops
normal iterator loop
for each loop

*/
int main() {
    string str = "harsh";
    reverse(str.begin(), str.end());
    cout << str << endl; 
}

// character array
#include <vector>
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        while(start <= end) {
            swap(s[start++], s[end--]);
        }
    }
};