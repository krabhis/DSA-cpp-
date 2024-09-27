#include<bits/stdc++.h>
using namespace std;


    int numberOfSubarrays(int arr[], int k , int n) {
        int r = 0, l = 0, countodd = 0, res = 0, prefix = 0;
        
        
        while (r < n) {
            // If we find an odd number, increment count of odd numbers
            if (arr[r] % 2 != 0) {
                countodd++;
                prefix = 0; // Reset prefix count when a new odd number is encountered
            }
            
            // If there are exactly k odd numbers, count all valid subarrays
            while (countodd == k) {
                // Increment prefix if there are 0's after the left pointer
                if (arr[l] % 2 == 0) {
                    prefix++;
                } else {
                    countodd--;
                }
                l++;
            }
            
            // Add the valid subarrays for this configuration of the right pointer
            res += prefix;
            r++;
        }

        return res;
    }


int main(){
    int arr[5]={1,1,2,1,1};
    int k=3;
    int result=numberOfSubarrays(arr , k , 5);
    cout<<result;

}
