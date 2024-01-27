/*
You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& v, int k) {
        int n = v.size();
        int cnt = 0, ans = 0, start = 0, end = 0;
      
        unordered_map<int, int> mp;
        while(end < n) {
            mp[v[end++]] += 1;
            while(mp[v[end - 1]] > k) {
                mp[v[start++]] -= 1;
            }
            ans = max(ans, end - start);
        }
        return ans;   
    }
};
