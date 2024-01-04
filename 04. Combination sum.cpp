/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

//Approach : backtracking

//Implementation

class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int>& op, int start, int k, int n, int& sum, int arr[]){
        if(k==0){
            if(sum==n){
                sort(op.begin(), op.end());
                ans.push_back(op);
            }
            return;
        }

        for(int i=start; i<9; i++){
            sum+= arr[i];
            op.push_back(arr[i]);
            solve(ans, op, i+1, k-1, n, sum, arr);
            
            //backtracking
            sum-= arr[i];
            op.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int arr[9]= {1,2,3,4,5,6,7,8,9};
        vector<int> op;
        int start=0, sum=0;

        solve(ans, op, start, k, n, sum, arr);
        return ans;
    }
};
