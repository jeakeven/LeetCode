/*

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len, 1), right(len, 1);
        
        for(int i = 1; i < len; i++) {
            left[i] = left[i-1] * nums[i-1];
            right[i] = right[i-1] * nums[len-i];
        }
        
        vector<int> ans(len);
        for(int i = 0; i < len; i++) {
            ans[i] = left[i] * right[len-i-1];
        }
        
        return ans;
        
    }
};