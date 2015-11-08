/*

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:

"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function. 

*/

class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        int ans = 0, num = 0, sign = 1; 
        s += ')';
        signs.push(1);
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == ')') {
                ans += signs.top() * sign * num;
                if(s[i] == ')') {
                    signs.pop();
                }
                sign = (s[i] == '-') ? -1 : 1;
                num = 0;
            }
            else if(s[i] == '(') {
                signs.push(signs.top() * sign);
                sign = 1;
            }
        }
        return ans;
    }
};