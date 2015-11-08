/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 

*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int i = len - 1;
        if(len == 0) {
            return 0;
        }
        while(s[i] == ' ') {
            i--;
        }
        int j;
        for(j = i; j >=0; j--) {
            if(s[j] == ' ') {
                break;
            }
        }
        return i - j;
    }
};