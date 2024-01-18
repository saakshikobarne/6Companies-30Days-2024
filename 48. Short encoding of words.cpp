/*
A valid encoding of an array of words is any reference string s and array of indices indices such that:

words.length == indices.length
The reference string s ends with the '#' character.
For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character
is equal to words[i].
Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.
*/

//code:

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        unordered_set<string> s(words.begin(), words.end());

        for (string w : s)
            for (int i = 1; i < w.size(); i++) s.erase(w.substr(i));

        int res = 0;
        for (string w : s) res += w.size() + 1;
        return res;
    }
};
