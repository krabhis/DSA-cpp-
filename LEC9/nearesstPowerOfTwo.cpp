#include <iostream>
#include <cmath>
using namespace std;

// Function to find the nearest power of two
 int nearestPowerOfTwo( int num) {
    // Calculate the lower and higher powers of two
     int lowerPower = 1;
    while (lowerPower * 2 <= num) {
        lowerPower *= 2;
    }
     int higherPower = lowerPower * 2;

    // Calculate the distances
     int distanceToLower = num - lowerPower;
     int distanceToHigher = higherPower - num;

    // Return the appropriate power of two
    if (distanceToLower < distanceToHigher) {
        return lowerPower;
    } else {
        return higherPower;
    }
}

int main() {
     int num;
    cout << "Enter a number: ";
    cin >> num;

     int result = nearestPowerOfTwo(num);
    cout << "Nearest power of two: " << result << endl;

    return 0;
}
