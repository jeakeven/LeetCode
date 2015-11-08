/*

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space. 

*/

class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int pos = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(i > pos) {
                    res = s.substr(pos, i - pos) + " " + res;
                }
                pos = i + 1;
            }
            else if(i == s.size() - 1) {
                res = s.substr(pos, s.size() - pos) + " " + res;
            }
        }
        s = res.substr(0, res.size() - 1);
    }
};