/*
Problem Statement:

You are given a 0-indexed array of positive integers nums.

A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. 
For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray 
changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.

Return the total number of incremovable subarrays of nums.

Note that an empty array is considered strictly increasing.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& a) {
        int n = a.size();

        for(int i=0;i<n-1;i++){
            if(a[i+1]<=a[i]) break;
        }

        int j=n-1;
        for(int i=0;j>0;j--){
            if(a[j-1]>=a[j]) break;
        }

        int ans=0;
        while(i>=0){
            int u = upper_bound(a.begin()+j, a.end(), a[i])-a.begin();
            ans += n-u+1;
            i--;
        }
        if(ans<(n*(n+1))/2)
            ans += n-j+1;
        
        return ans;
    }
};
