/*

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the word list

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> s1 = {beginWord}; // Front end
        unordered_set<string> s2 = {endWord}; // Back end
        wordDict.erase(beginWord);
        wordDict.erase(endWord);

        return ladderLength(s1, s2, wordDict, 1);
    }

private:
    int ladderLength(unordered_set<string>& s1, unordered_set<string>& s2, unordered_set<string>& wordDict, int level) {
        if (s1.empty()) // We can't find one.
            return 0;

        unordered_set<string> s3; // s3 stores all words 1 step from s1.
        for (auto word : s1) {
            for (auto& ch : word) {
                auto originalCh = ch;
                for (ch = 'a'; ch <= 'z'; ++ ch) {
                    if (ch != originalCh) {
                        if (s2.count(word))  // We found one.
                            return level + 1;

                        if (wordDict.count(word)) {
                            wordDict.erase(word); // Avoid duplicates.
                            s3.insert(word);
                        }
                    }
                }
                ch = originalCh;
            }
        }
        // Continue with the one with smaller size.    
        return (s2.size() <= s3.size()) ? ladderLength(s2, s3, wordDict, level + 1) : ladderLength(s3, s2, wordDict, level + 1);
    } 
};