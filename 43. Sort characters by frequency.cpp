/*
Problem statement:

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/

//code:

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> mp(62);
        for (auto &ch : s) {
            if (isupper(ch)) mp[ch-'A'] = {++mp[ch-'A'].first, ch};
            else if (islower(ch)) mp[ch-'a'+26] = {++mp[ch-'a'+26].first, ch};
            else mp[ch-'0'+52] = {++mp[ch-'0'+52].first, ch};
        }

        sort(begin(mp), end(mp));
        reverse(begin(mp), end(mp));

        int i = 0;
        for (auto &[freq, ch] : mp) {
            if (!freq) break;
            while (freq--) s[i++] = ch;
        }

        return s;
    }
};
