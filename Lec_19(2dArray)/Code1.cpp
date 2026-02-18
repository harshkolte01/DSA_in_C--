/*
2D Array


*/

#include <iostream>
#include <vector>

using namespace std;


pair<int, int> LinearSearch(int matrix[][3], int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target) {
                    return make_pair(i, j);
                }  
            }
    }
    return make_pair(-1, -1);
}

// Maximum Row sum

int getMaxSumRow(int matrix[][3], int rows, int cols) {
    int maxSum = INT_MIN;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum = rowSum + matrix[i][j];
        }
        maxSum = max(maxSum, rowSum);
    }
    return maxSum;
}

// Maximum Column Sum
int getMaxSumCol(int matrix[][3], int rows, int cols) {
    int maxSum = INT_MIN;
    for (int i = 0; i < rows; i++) {
        int colSum = 0;
        for (int j = 0; j < cols; j++) {
            colSum = colSum + matrix[j][i];
        }
        maxSum = max(maxSum, colSum);
    }
    return maxSum;
}

// diagonal sum
int getDiagonalSum(int matrix[][4], int n) {
    int sum = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i == j) {
    //             sum += matrix[i][j];
    //         } else if (j == n - i - 1) {
    //             sum += matrix[i][j];
    //         }
    //     }
    // }

    // optimized
    for (int i = 0; i < n; i++) {
        sum+= matrix[i][i];
        if (i != n - i - 1) {
            sum+= matrix[i][n-i-1];
        }
    }
    return sum;
}

int main() {
//    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[4][4] = {{1,2,3,4}, {5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n = 4;

    cout << getDiagonalSum(matrix2, n) << endl;
//    int matrix[4][3];
    int rows = 4;
    int cols = 3;
    int target = 15;

    vector<vector<int>> vec;
    // for (int i =0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         cin >> matrix[i][j];
    //     }
    // }

    // for (int i =0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
//    pair<int, int> result = LinearSearch(matrix, rows, cols, target);
//    cout << "Row: " << result.first << " Col: " << result.second << endl;
    // cout << "Max SUM Row: " << getMaxSumRow(matrix, rows, cols) << endl; 
    // cout << "Max SUM Col: " << getMaxSumCol(matrix, rows, cols) << endl; 
    
    return 0;
}

