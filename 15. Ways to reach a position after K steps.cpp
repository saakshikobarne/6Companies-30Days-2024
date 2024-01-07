/*
Problem Statement:

You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. 
With one step, you can move either one position to the left, or one position to the right.
Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, 
such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.

Two ways are considered different if the order of the steps made is not exactly the same.

Note that the number line includes negative integers.
*/

//code:

int mod= 1e9+7;
int dp[1001][5000];

class Solution {
public:

    int helper(int s,int e,int k,int curr){
        if(k==0){
            if(curr==e)return 1;
            return 0;
        }

        if(dp[k][curr+1000]!=-1)return dp[k][curr+1000];
        
        int step = 0;
        step = (helper(s,e,k-1,curr+1)%mod) + (helper(s,e,k-1,curr-1)%mod);

        return  dp[k][curr+1000] =  step%mod;
    }

    int numberOfWays(int s, int e, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(s,e,k,s)%mod;
    }
};
