/*

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sec = nums.size() - 1, zero = 0;
        for(int i = 0; i <= sec; i++) {
            while(nums[i] == 2 && i < sec) {
                swap(nums[i], nums[sec--]);
            }
            while(nums[i] == 0 && i > zero) {
                swap(nums[i], nums[zero++]);
            }
        }
    }
};