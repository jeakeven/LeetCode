/*

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4. 

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int maxLen = 0;
        vector<vector<int>> m(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[0].size(); c++) {
                m[r][c] = matrix[r][c] - '0';
                if(r > 0 && c > 0 && m[r][c] == 1) {
                    m[r][c] += min(m[r-1][c], min(m[r][c-1], m[r-1][c-1]));
                }
                maxLen = max(maxLen, m[r][c]);
            }
        }
        return maxLen * maxLen;
    }
};