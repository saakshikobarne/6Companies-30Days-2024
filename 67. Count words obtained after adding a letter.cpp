/*
You are given two 0-indexed arrays of strings startWords and targetWords. Each string consists of lowercase English letters only.

For each string in targetWords, check if it is possible to choose a string from startWords and perform a conversion operation on it to be equal to that from targetWords.

The conversion operation is described in the following two steps:

Append any lowercase letter that is not present in the string to its end.
For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it, but not 'a'. If 'd' is added, the resulting string will be "abcd".
Rearrange the letters of the new string in any arbitrary order.
For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on. Note that it can also be rearranged to "abcd" itself.
Return the number of strings in targetWords that can be obtained by performing the operations on any string of startWords.

Note that you will only be verifying if the string in targetWords can be obtained from a string in startWords by performing the operations. The strings in startWords do 
not actually change during this process.
*/

//code:

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> vis;
        for (string s : startWords) {
            int hash = 0;
            for (int i = 0; i < s.size(); i++) 
                hash += (1 << (s[i] - 'a'));
            vis.insert(hash);
        }
        
        int res = 0;
        for (string s : targetWords) {
            int hash = 0;
            for (int k = 0; k < s.size(); k++) {
                hash = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (i == k) continue;
                    hash += (1 << (s[i] - 'a'));
                }
                if (vis.count(hash)) {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};
