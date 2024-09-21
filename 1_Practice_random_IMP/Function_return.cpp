#include <iostream>
using namespace std;

int addNumbers(int a, int b) {
    int sum = a + b;
    cout << "Sum is: " << sum << endl;  
    return sum;  
}

int main() {
    int result = addNumbers(3, 4);
    cout << "Result is: " << result << endl;
    return 0;
}
