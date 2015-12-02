/*
 Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it. 

solution£º
	input: 0 1 2 3 4 ...
	output: 0 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 ....

*/ 
	
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};