/*
You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., 
the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost 
less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0. 
*/

//code:

class Solution {
public:
    int equalSubstring(string str, string tar, int maxCost) {

        int n = str.size();
        int left = 0, currCost = 0, maxi = 0;

        for(int right = 0; right < n; right++) {
            currCost += abs(str[right] - tar[right]);

            while(left <= right && currCost > maxCost){
                currCost -= abs(str[left] - tar[left]);
                left++;
            }
            maxi = max({maxi, right - left + 1});
        }
        return maxi;
    }
};
