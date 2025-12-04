class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0, l = 0;
        int count = 0;
        int sum = 0;
        
        while (r < n) {
            sum += nums[r];
            while (sum > k) { 
                sum -= nums[l];
                l++;
            }
            if (sum == k) {
                count++;
                int temp = l;
                while (nums[temp] == 0){
                    count++;
                    temp++;
                }
            }
            r++;
        }
        
        return count;
    }
};
