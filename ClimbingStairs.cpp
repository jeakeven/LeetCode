/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

*/

class Solution {
public:
    int climbStairs(int n) {
        int stepOne = 1;
        int stepTwo = 0;
        int res = 0;
        for(int i = 0; i <= n; i++) {
            res = stepOne + stepTwo;
            stepOne = stepTwo;
            stepTwo = res;
        }
        return res;
    }
};