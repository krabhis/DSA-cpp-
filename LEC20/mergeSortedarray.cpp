#include <iostream>
#include<vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            k++;
            i++;
        } else {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n) {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while (j < m) {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

void print(int arrs[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arrs[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[6] = {3, 5, 6, 7, 8, 9};
    int arr2[4] = {4, 6, 8, 10};
    int arr3[10] = {0};

    merge(arr1, 6, arr2, 4, arr3);
    print(arr3, 10);

    return 0;
}




class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n,vector<int>& nums3,int k) {
       
              int i = 0, j = 0, k = 0;
              while (i < n && j < m)
               {
                if(nums1[i]<nums2[j]){
                    nums3[k]=nums1[i];
                    k++;
                    i++;
                }
                else{
                    nums3[k]=nums2[j];
                    k++;
                    j++;
                }
            }
               while (i < n) {
               nums3[k] = nums1[i];
                  k++;
                  i++;
                  }
                while (j < m) {
               nums3[k] = nums2[j];
                 k++;
                 j++;
                 }
            
            
            
        }
        
       } ;






       // class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int i=0;
//         int n=nums.size();
//         vector<int>count(n);
//         int cnt=0;

//         while(i<n){
//             int j=i+1;
//             while(j<n){
//                 if(nums[i]>nums[j]){
//                     cnt++;
//                 }
//             j++;
//             }
//         count[i]=cnt;
//         }
//     return count;
//     }
// };

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n);
        int cnt = 0; // Move cnt outside the outer loop

        for (int i = 0; i < n; i++) {
            cnt = 0; // Reset cnt for each element
            for (int j = i + 1; j < n; j++) {
                if (nums[i]> nums[j]) {
                    cnt++;
                }
                else if(nums[i]==nums[j]){
                    cnt=1;
                }
            }
            count[i] = cnt;
        }

        return count;
    }
};
