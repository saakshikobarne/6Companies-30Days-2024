/*
Problem statement:

Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for 
every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining 
elements in their original order.
*/


//code:

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int maxSum = nums[0];
        deque<int> que;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] += !que.empty() ? que.front() : 0;
            maxSum = max(maxSum, nums[i]);

            while (!que.empty() && nums[i] > que.back()) 
                que.pop_back();

            if (nums[i] > 0) 
                que.push_back(nums[i]);

            if (i >= k && !que.empty() && que.front() == nums[i - k]) 
                que.pop_front();
        }
        return maxSum;
    }
};
