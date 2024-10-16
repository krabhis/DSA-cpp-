#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;

        int m = matrix.size();
        int n = matrix[0].size();
        bool rowZero = false; // Flag to indicate if the first row should be zeroed
        bool colZero = false; // Flag to indicate if the first column should be zeroed

        // Check if the first row has any zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                rowZero = true;
                break;
            }
        }

        // Check if the first column has any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                colZero = true;
                break;
            }
        }

        // Use the first row and first column to mark zeroes for other rows and columns
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the first column
                    matrix[0][j] = 0; // Mark the first row
                }
            }
        }

        // Set the cells to zero based on the marks in the first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Finally, set the first row and first column to zero if needed
        if (rowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if (colZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution solution;
    solution.setZeroes(matrix);

    // Print the modified matrix
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
