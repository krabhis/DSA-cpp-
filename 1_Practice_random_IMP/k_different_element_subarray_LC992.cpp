#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


    int atMostKDistinct(const vector<int>& nums, int k) {   //function for leass than equal to k distnct integer 
        int n = nums.size();
        int left = 0, right = 0, count = 0;
        unordered_map<int, int> mapi;
        
        for (right = 0; right < n; ++right) {
            if (mapi[nums[right]] == 0) k--;
            mapi[nums[right]]++;

            while (k < 0) {
                mapi[nums[left]]--;
                if (mapi[nums[left]] == 0) k++;
                left++;
            }
            
            
            count += right - left + 1;
        }
        
        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

int main(){
    vector<int>arr={1,2,1,2,3};
    int k=2;
    int ans=subarraysWithKDistinct(arr,k);
    cout<<ans;
}

