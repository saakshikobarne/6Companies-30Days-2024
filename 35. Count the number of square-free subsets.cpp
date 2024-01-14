/*
Problem statement:

You are given a positive integer 0-indexed array nums.

A subset of the array nums is square-free if the product of its elements is a square-free integer.

A square-free integer is an integer that is divisible by no square number other than 1.

Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.

A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. 
Two subsets are different if and only if the chosen indices to delete are different.

 
*/

class Solution {
public:
    int primelist[10] = {2,3,5,7,11,13,17,19,23,29};
    int checkprime(int n){
        int ret = 0;
        for(int i = 0 ;  i < 10 ; i++){
            if(n%primelist[i] == 0){
                n/=primelist[i];
                ret |= 1<<i;
            }
            if(n%primelist[i] == 0) return -1;
        }
        return ret;
    }
    int squareFreeSubsets(vector<int>& nums) {
        int MOD = 1e9+7, cnt = 0;
        vector<int> bitmap(nums.size());

        for(auto &v:nums){
            auto ret = checkprime(v);
            if(ret != -1)   bitmap[cnt++] = ret;
        }
        
        int m[1024] = {0};
        int ans = 0;
        while(cnt > 0){
            cnt--;
            for(int k = 0 ; k < 1024 ; k++){    
                if(m[k] != 0 && (k&bitmap[cnt]) == 0)
                    m[(k|bitmap[cnt])] = (m[(k|bitmap[cnt])] + m[k])%MOD;
            }
            m[bitmap[cnt]]++;
        }

        for(int i = 0 ; i < 1024 ; i++)
            ans = (ans + m[i])%MOD;
        
        return ans;
    }
};
