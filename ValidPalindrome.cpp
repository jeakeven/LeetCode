/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome. 

*/

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while(isalnum(s[i]) == false && i < j) {
                i++;
            }
            while(isalnum(s[j]) == false && i < j) {
                j--;
            }
            if(toupper(s[i]) != toupper(s[j])) {
                return false;
            }
        }
        return true;
    }
};