#include <bits/stdc++.h>

using namespace std;

// Function to convert a binary string to a decimal number
int binaryToDecimal(const string& binary) {
    int sum = 0;
    int n = binary.size();
    for (int i = 0; i < n; i++) {
        int des = binary[i] - '0';
        sum += des * pow(2, n - i - 1);
    }
    return sum;
}

// Function to convert a decimal number to a binary string
string decimalToBinary(int n) {
    if (n == 0) return "0";
    string binary = "";
    while (n > 0) {
        int rem = n % 2;
        binary = to_string(rem) + binary;
        n /= 2;
    }
    return binary;
}


/*
// Function to find the maximum good number

int maxGoodNumber(int arr[], int len) {
    // Convert numbers to binary
    string n1 = decimalToBinary(arr[0]);
    string n2 = decimalToBinary(arr[1]);
    string n3 = decimalToBinary(arr[2]);

    // Calculate the six possible combinationsww
    int val1 = binaryToDecimal(n1 + n2 + n3);
    int val2 = binaryToDecimal(n1 + n3 + n2);
    int val3 = binaryToDecimal(n2 + n1 + n3);
    int val4 = binaryToDecimal(n2 + n3 + n1);
    int val5 = binaryToDecimal(n3 + n1 + n2);
    int val6 = binaryToDecimal(n3 + n2 + n1);

    // Find the maximum value among the calculated values
    return max({val1, val2, val3, val4, val5, val6});
}





*/

int main() {
    // Example input array
    int arr[3] = {2, 8, 16};
    
    // Calculate the maximum good number
    int result = maxGoodNumber(arr, 3);
    
    // Output the result
    cout << "Maximum Good Number: " << result << endl;
    return 0;
}
