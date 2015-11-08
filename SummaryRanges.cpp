/*

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int len = nums.size();
        
        if(len <= 0)
            return res;
        
        for(int i = 0; i < len;) {
            int beg = i, end = i;
            while(end + 1 < len && nums[end + 1] == nums[end] + 1) {
                end++;
            }
            if(beg < end) {
                res.push_back(to_string(nums[beg]) + "->" + to_string(nums[end]));
            }
            else {
                res.push_back(to_string(nums[beg]));
            }
            i = end + 1;
        }
        return res;
    }
};