/*
Problem Statement:

You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.
You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

Trim each number in nums to its rightmost trimi digits.
Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
Reset each number in nums to its original length.
Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

Note:
To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
Strings in nums may contain leading zeros.
*/

//Implementation:

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>res; 
       
        for(int i = 0; i < queries.size(); i++) {      
            priority_queue <pair<string, int>> pq;  

            for(int j = 0; j< nums.size(); j++){
                string s = nums[j].substr(nums[j].size() - queries[i][1], nums[j].size()); 
                pq.push({s, j}); 
            }
            int tmp = 0;
            
            for(int k = 0; k < nums.size() - queries[i][0] + 1; k++){
                tmp = pq.top().second;
                pq.pop();
            }
            res.push_back(tmp);
        }
        
        return res;
    }        
};
