/*
Problem statement:

You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:

For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.
*/

//code:

class Solution {
public:
    int mod = 1e9+7;
    int dp[14][1<<14];

    int solve(vector<int>& nums,  int prev, int mask){
        int n = nums.size();
        if(mask == (1<<n)-1){
            return 1;
        }

        if(dp[prev][mask]!=-1)return dp[prev][mask];

        int res =0;
        for(int j=0; j<n; j++){
               if(mask&(1<<j)) continue;
               if( mask == 0 || (nums[j] % nums[prev]) == 0 || (nums[prev] % nums[j]) == 0)
                   res = (res +solve(nums,j,mask|1<<j))%mod;
        }
        return dp[prev][mask] = res;
    }

    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));

        return solve(nums,0,0);
    }
};
