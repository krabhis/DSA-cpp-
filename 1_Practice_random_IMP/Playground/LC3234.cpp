#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

 
        int r = 0, score = 0;
        int zero = 0, one = 0;
        int n = s.size();
        
        for (int l = 0; l < n; l++) {
            while (r < n) {
                string substr = s.substr(l, (r - l + 1));
                
                zero = 0;
                one = 0;
                
                for (int i = 0; i < substr.size(); i++) {
                    if (substr[i] == '0') {
                        zero++;
                    } else {
                        one++;
                    }
                }
                
                if (one >= (zero * zero)) {
                    score++;
                }
                
                r++;
            }
            r = l + 1;
        }


    cout << score << endl;
    cout << "Love you Zindagi" << endl;

    return 0;
}
