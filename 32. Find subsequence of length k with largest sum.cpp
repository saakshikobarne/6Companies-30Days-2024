/*
Problem Statement:

You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the 
order of the remaining elements.
*/

//code:

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> result;
        result.reserve(k);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                pq.push({nums[i], i});
                continue;
            }

            if (nums[i] > pq.top().first) {
                pq.pop();     
                pq.push({nums[i], i});
            }
        }

        vector<pair<int,int>> v;
        v.reserve(k);
        
        while (!pq.empty()) {
            v.emplace_back(pq.top().second, pq.top().first);
            pq.pop();
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < k; i++) {
            result.emplace_back(v[i].second);
        }
        return result;
    }
};
