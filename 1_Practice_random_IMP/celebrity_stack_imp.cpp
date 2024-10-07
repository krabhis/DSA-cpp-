#include <iostream>
#include <vector>

using namespace std;

// Function to check if person 'a' knows person 'b'
bool knows(const vector<vector<int>>& M, int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(int n, const vector<vector<int>>& M) {
    for (int i = 0; i < n; i++) {
        bool isCelebrity = true;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                // Celebrity should not know anyone, and everyone should know celebrity
                if (knows(M, i, j) || !knows(M, j, i)) {
                    isCelebrity = false;
                    break;
                }
            }
        }
        if (isCelebrity) {
            return i;  // Return the index of the celebrity
        }
    }
    return -1;  // No celebrity found
}

int main() {
    // Example matrix where person 1 is the celebrity
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}
    };

    int n = M.size();
    int celebrity = findCelebrity(n, M);
    
    if (celebrity == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is person " << celebrity << "." << endl;
    }

    return 0;
}
