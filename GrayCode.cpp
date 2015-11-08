/*

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = res.size() - 1; j >= 0; j--) {
                int cur = res[j];
                cur += 1 << i;
                res.push_back(cur);
            }
        }
        return res;
    }
};