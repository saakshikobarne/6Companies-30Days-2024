/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.


Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
*/

//code:

class Solution {
public:

    int subarrays(vector<int>& nums, int k){
        int odd=0, ans=0, i=0, j=0;

        while(j<nums.size()){
            if(nums[j]%2!=0) odd++;

            while(odd>k){
                if(nums[i]%2!=0) odd--;
                i++;
            }
            ans+= j-i+1;
            j++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarrays(nums,k)- subarrays(nums,k-1);
    }
};
