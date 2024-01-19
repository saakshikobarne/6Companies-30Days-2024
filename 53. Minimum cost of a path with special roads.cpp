/*
Problem statement:

You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. 
You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).

The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] 
indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each 
special road any number of times.

Return the minimum cost required to go from (startX, startY) to (targetX, targetY).
*/

//code:

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int n= specialRoads.size();
        vector<int> dist(n, INT_MAX);

        for(int i=0; i<specialRoads.size(); i++){
            int m= abs(start[0]- specialRoads[i][0])+ abs(start[1]- specialRoads[i][1])+ specialRoads[i][4];
            q.push({m,i});
        }

        int ans= abs(start[0]- target[0])+ abs(start[1]- target[1]);

        while(!q.empty()){
            int r= specialRoads[q.top().second][2];
            int c= specialRoads[q.top().second][3];
            int id= q.top().second;
            int d= q.top().first;
            q.pop();

            ans= min(ans,d+ abs(r- target[0])+ abs(c- target[1]));

            for(int i=0; i<n; i++){
                int m= abs(r- specialRoads[i][0])+ abs(c- specialRoads[i][1])+ specialRoads[i][4];

                if(d+m <dist[i]){
                    dist[i]=d+ m;
                    q.push({dist[i],i});
                }
            }
        }
        return ans;
    }
};
