/*
Problem Statement:

Given an integer array nums and two integers k and p, return the number of distinct subarrays, which have at most k elements that are divisible by p.
Two arrays nums1 and nums2 are said to be distinct if:
They are of different lengths, or
There exists at least one index i where nums1[i] != nums2[i].
A subarray is defined as a non-empty contiguous sequence of elements in an array.

Example 1:

Input: nums = [2,3,3,2,2], k = 2, p = 2
Output: 11

Explanation:
The elements at indices 0, 3, and 4 are divisible by p = 2.
The 11 distinct subarrays which have at most k = 2 elements divisible by 2 are:
[2], [2,3], [2,3,3], [2,3,3,2], [3], [3,3], [3,3,2], [3,3,2,2], [3,2], [3,2,2], and [2,2].
Note that the subarrays [2] and [3] occur more than once in nums, but they should each be counted only once.
The subarray [2,3,3,2,2] should not be counted because it has 3 elements that are divisible by 2.
*/

//code:

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size();

        vector<vector<int>>ans(n ,vector<int>(m,0));
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q; 

        for(int i = 0 ; i<n;i++){
            for(int j = 0; j<m;j++){
                if(mat[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({{i,j},0}); 
                }
            }
        }

        while(!q.empty()){

            pair<pair<int,int>, int>p = q.front();
            q.pop();

            int r = p.first.first, c = p.first.second; 
            int h = p.second;

            int x[] = {-1, 0 , 1, 0};
            int y[] = {0 , 1 , 0 ,-1};

            for(int i = 0; i<4;i++){
                int nx = r+x[i], ny = c+y[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0){
                    ans[nx][ny] = h+1; 
                    vis[nx][ny] = 1; 
                    q.push({{nx,ny},h+1}); 
                }
            }
        }
        return ans;
    }
};
