#include <bits/stdc++.h>
using namespace std;

vector<int> extractBoundary(vector<vector<int>>& arr, int layer) {
    vector<int> chain;
    int rows = arr.size();
    int cols = arr[0].size();

    int startRow = layer;
    int endRow = rows - layer - 1;
    int startCol = layer;
    int endCol = cols - layer - 1;

    for (int j = startCol; j <= endCol; j++) {
        chain.push_back(arr[startRow][j]);
    }

    for (int i = startRow + 1; i <= endRow; i++) {
        chain.push_back(arr[i][endCol]);
    }

    if (startRow < endRow) {
        for (int j = endCol - 1; j >= startCol; j--) {
            chain.push_back(arr[endRow][j]);
        }
    }

    if (startCol < endCol) {
        for (int i = endRow - 1; i > startRow; i--) {
            chain.push_back(arr[i][startCol]);
        }
    }

    return chain;
}

vector<int> kRotate(vector<int>& chain, int k) {
    int n = chain.size();
    k = k % n;

    vector<int> rotatedChain(n);
    for (int i = 0; i < n; i++) {
        rotatedChain[i] = chain[(i + k) % n];
    }

    return rotatedChain;
}
//placing roteated values again int o the matrix;
void placeBoundary(vector<vector<int>>& arr, vector<int>& rotatedChain, int layer) {
    int rows = arr.size();
    int cols = arr[0].size();

    int startRow = layer;
    int endRow = rows - layer - 1;
    int startCol = layer;
    int endCol = cols - layer - 1;

    int idx = 0;

    for (int j = startCol; j <= endCol; j++) {
        arr[startRow][j] = rotatedChain[idx++];
    }

    for (int i = startRow + 1; i <= endRow; i++) {
        arr[i][endCol] = rotatedChain[idx++];
    }

    if (startRow < endRow) {
        for (int j = endCol - 1; j >= startCol; j--) {
            arr[endRow][j] = rotatedChain[idx++];
        }
    }

    if (startCol < endCol) {
        for (int i = endRow - 1; i > startRow; i--) {
            arr[i][startCol] = rotatedChain[idx++];
        }
    }
}

int main() {
    cout << "Enter the values of row and col (both should be even):" << endl;
    int row, col;
    cin >> row >> col;

    vector<vector<int>> mat(row, vector<int>(col));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter the number of rotations (k):" << endl;
    int k;
    cin >> k;

    int layers = min(row, col) / 2;

    for (int layer = 0; layer < layers; layer++) {
        vector<int> boundary = extractBoundary(mat, layer);

        vector<int> rotatedBoundary = kRotate(boundary, k);

        placeBoundary(mat, rotatedBoundary, layer);
    }

    cout << "Matrix after " << k << " rotations of each layer:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
