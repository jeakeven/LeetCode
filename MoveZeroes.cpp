/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. 
*/
	
	
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
    }
};

#if 0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int last = 0, cur = 0;

        while(cur < nums.size()) {
            if(nums[cur] != 0) {
                swap(nums[last], nums[cur]);
                last++;
            }
    
            cur++;
        }
    }
};
#endif