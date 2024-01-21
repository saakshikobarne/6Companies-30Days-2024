/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.
*/

//code:

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int losses[100001];
        for(int i = 1; i <= 100000; i++){
            losses[i] = -1;
        }

        int biggestPlayerNum = 0;
        for(int i = 0; i < matches.size(); i++){
            if(losses[matches[i][0]] == -1) losses[matches[i][0]] = 0;
            if(losses[matches[i][1]] == -1) losses[matches[i][1]] = 0;

            losses[matches[i][1]]++;

            biggestPlayerNum = max(biggestPlayerNum, matches[i][0]);
            biggestPlayerNum = max(biggestPlayerNum, matches[i][1]);
        }
        
        vector<vector<int>> ans(2);
        for(int i = 1; i <= biggestPlayerNum; i++){
            if(losses[i] == 0) ans[0].push_back(i);
            else if(losses[i] == 1) ans[1].push_back(i);
        }

        return ans;
    }
};
