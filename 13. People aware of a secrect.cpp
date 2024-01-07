/*
On day 1, one person discovers a secret.
You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay
days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret 
forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
*/

//code:

class Solution {
int dp[1001];
#define mod 1000000007

public:
    int solve(int idx,int d,int f,int n){

        if(idx+d > n) return 1;
        if(dp[idx]!=-1)return dp[idx];

        int ans=1;
        for(int i=idx+d;i <= min(n,idx+f);i++){
            if(i==idx+f){
                ans-=1;
                break;
            }
            ans= (ans %mod + solve(i,d,f,n) %mod) %mod;
        }
        return dp[idx]=ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
      
        memset(dp,-1,sizeof(dp));
        return solve(1,delay,forget,n); 
    }
};
