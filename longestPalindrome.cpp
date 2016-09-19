/*
Given a string S, find the longest palindromic substring in S. 

You may assume that the maximum length of S is 1000, 

and there exists one unique longest palindromic substring.

eg:
abbbbbbbbba, left=1时,right一直走到最后一个b, 然后往两边判断是否相等.

*/


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;
        
        int start = 0;
        int maxLen = 1;
        
        for(int i = 0; i < n; i++) {
            int left = i; 
            int right = i;
            
            while(right + 1 < n && s[right+1] == s[left]) {
                 ++right;               
            }
            
            i = right;
            while(left - 1 >= 0 && right + 1 < n && s[left-1] == s[right+1]) {
                --left;
                ++right;
            }
            
            int len = right - left + 1;
            if(len > maxLen) {
                start = left;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
};