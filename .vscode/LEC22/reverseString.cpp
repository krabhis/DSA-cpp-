#include <iostream>
using namespace std;

void reverse(char str[], int n) {
    int s = 0, e = n - 1;

    // Handle empty or single-character strings efficiently
    if (n <= 1) {
        return;
    }

    while (s < e) {
        char temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s++;
        e--;
    }
}

int length(char arr[]) {
    int count = 0;
    while (arr[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    char str[50];
    cout << "Enter the string: ";  // Improved prompt clarity
    cin >> str;

    int strLength = length(str);

    reverse(str, strLength);

    cout << "Reversed string: " << str << endl;
    return 0;
}
