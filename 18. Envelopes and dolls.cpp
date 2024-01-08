/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

class Solution {
public:

    static bool comp(const pair<int, int>& a, const pair<int, int>& b){
        return (a.first != b.first)? (a.first < b.first): (a.second > b.second);
    }

    int solve(vector<pair<int, int>>& nums){
        if(nums.size()==0) return 0;

        vector<int> ans;
        ans.push_back(nums[0].second);

        for(int i=1; i<nums.size(); i++){
            if(nums[i].second > ans.back())
                ans.push_back(nums[i].second);
            else{
                int idx= lower_bound(ans.begin(), ans.end(), nums[i].second) - ans.begin();
                ans[idx]= nums[i].second;
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int, int>> vec;

        for(int i=0; i< envelopes.size(); i++)
            vec.push_back({envelopes[i][0], envelopes[i][1]});
    
        sort(vec.begin(), vec.end(), comp);

        return solve(vec);
    }
};


// TC : O(N logN)
// SC: O(N)

/*
First, sorting the pairs in given 2D array primarily in ascending order of their first elements, in case the first elements are equal, in descending order by their second elements. Then the problem is standard LIS and using BS on second elements of the pair ignoring the first elements.
*/
