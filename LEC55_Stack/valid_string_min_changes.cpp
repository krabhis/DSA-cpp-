#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
    // If the length of the string is odd, it is impossible to balance it
        if (str.size() % 2 != 0) {
                return -1;
                    }
                        
        stack<char> stc;
        int count = 0;

        for (int i = 0; i < str.size(); i++) {
            char a = str[i];

             if (a == '{') {
              stc.push(a);
             } 
                                                                                       
             else if (a == '}' && !stc.empty()) {
               stc.pop();  
               } 
                                                                                                                           
                else if (a == '}' && stc.empty()) {
                 count++;
                 stc.push('{');
               }
        }
        count += stc.size() / 2;
         return count;
}