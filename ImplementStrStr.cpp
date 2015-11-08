/*

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int res;
        res = haystack.find(needle);
        if(res != haystack.npos) {
            return res;
        }
        return -1;
    }
};