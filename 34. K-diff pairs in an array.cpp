/*
Problem statement:

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k

Notice that |val| denotes the absolute value of val.
*/

//code:

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, i = 0, j = 1;

        for(i, j; i<nums.size() && j<nums.size(); ) {
            
            if(i==j || nums[j]-nums[i]<k) j++;
            else {
                if(nums[j]-nums[i]==k) {
                    ans++;
                    j++;
                    while(j<nums.size() && nums[j]==nums[j-1]) j++; 
                }
                i++;
                while(i<j && nums[i]==nums[i-1]) i++; 
            }
        }
        return ans;
    }
};
