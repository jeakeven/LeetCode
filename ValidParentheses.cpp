/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char tmp;
        unordered_map<char, char> bracDict;
        bracDict[')'] = '(';
        bracDict[']'] = '[';
        bracDict['}'] = '{';
        
        for(int i = 0; i < s.size(); i++) {
            tmp = s[i];
            if(tmp == '(' || tmp == '[' || tmp == '{') {
                stk.push(tmp);
            }
            else if(stk.empty() || stk.top() != bracDict[tmp]) {
                return false;
            }
            else {
                    stk.pop();
            }
        }
        if(stk.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};