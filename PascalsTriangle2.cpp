/*

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1, 0);
        v[0] = 1;
        for(int i = 1; i < rowIndex+1; i++) {
            for(int j = i; j > 0; j--) {
                v[j] += v[j-1];
            }
        }
        return v;
    }
};

#if 0
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vec(rowIndex+1);
        for (int i = 0; i <= rowIndex; i++) {
            vec[i].resize(i + 1);
            vec[i][0] = vec[i][i] = 1;

            for (int j = 1; j < i; j++)
                vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
        }
        return vec[rowIndex];
    }
};
#endif