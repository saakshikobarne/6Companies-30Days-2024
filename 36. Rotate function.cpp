/*
Problem statement:

You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

*/

class Solution {
public:

    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int> rev=nums;
        reverse(rev.begin(),rev.end());

        int res=0, pre=0, sum=0;
        for(int i=0; i<n; i++){
            res+= (i*nums[i]);
            sum+= nums[i];
        }
        pre=res;
        
        int rotate=1,j=0;
        while(rotate<n){
            int temp=pre;
            temp = pre+sum-(n*rev[j]);
            j++;

            res=max(res,temp);
            pre=temp;
            rotate++;
        }
        return res;
    }
};
