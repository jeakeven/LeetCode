/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

*/

class Solution {
public:
    bool isMoreThanThird(int num, vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == num)
                ++count;
        }
        if(count > n/3)
            return true;
        else
            return false;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        if(len == 0)
            return res;
        
        int cnt1 = 0, cnt2 = 0, num1, num2;
        for(int i = 0; i < len; i++) {
            if(cnt1 == 0)
                num1 = nums[i];
            if(cnt2 == 0 && nums[i] != num1) 
                num2 = nums[i];
            if(nums[i] == num1)
                ++cnt1;
            if(nums[i] == num2)
                ++cnt2;
            if(cnt1 != 0 && cnt2 != 0 && nums[i] != num1 && nums[i] != num2) {
                --cnt1;
                --cnt2;
            }
        }
        if(isMoreThanThird(num1, nums))
            res.push_back(num1);
        if(isMoreThanThird(num2, nums) && num1 != num2) 
            res.push_back(num2);
   
        return res;  
    }
};