#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    // Create an array of pointers (outer array)
    int** jaggedArray = new int*[rows];

    // Input number of columns for each row and allocate memory
    for (int i = 0; i < rows; ++i) {
        int cols;
        cout << "Enter number of columns for row " << i + 1 << ": ";
        cin >> cols;

        // Allocate memory for the inner array (row)
        jaggedArray[i] = new int[cols];

        // Input elements for each row
        cout << "Enter elements for row " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j) {
            cin >> jaggedArray[i][j];
        }
    }

    // Display the jagged array
    cout << "Jagged array:" << endl;
    for (int i = 0; i < rows; ++i) {
        int j = 0;
        while (jaggedArray[i][j] != '\0') {
            cout << jaggedArray[i][j] << " ";
            j++;
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}



