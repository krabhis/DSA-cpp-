#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> mat(row, vector<int>(col, 0));
    vector<vector<int>> direction = {
        {0, 1}, {1, 0}, {1, 1}, {-1, -1}, 
        {-1, 0}, {0, -1}, {1, -1}, {-1, 1}
    };

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> temp = mat;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int livecount = 0;

            for (auto dir : direction) {
                int r = i + dir[0];
                int c = j + dir[1];
                if (r >= 0 && r < row && c >= 0 && c < col && abs(mat[r][c]) == 1) {
                    livecount++;
                }
            }

            if (mat[i][j] == 1 && (livecount < 2 || livecount > 3)) {
                temp[i][j] = 0; 
            } else if (mat[i][j] == 0 && livecount == 3) {
                temp[i][j] = 1; 
            }
        }
    }

    mat = temp;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Love you Zindagi" << endl;
    return 0;
}
