/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        int closest = INT_MAX;
        
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int begin = i + 1;
            int end = n - 1;
            while(begin < end) {
                int sum = nums[i] + nums[begin] + nums[end];
                if(closest > abs(sum - target)) {
                    result = sum;
                    closest = abs(sum - target);
                }
                if(sum > target) {
                    --end;
                }
                else if(sum < target) {
                    ++begin;
                }
                else {
                    return sum;
                }
            }
        }
        return move(result);
    }
};