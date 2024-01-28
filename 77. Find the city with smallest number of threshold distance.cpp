/*
Problem Statement:

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge
between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, 
If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> v(n, vector<int> (n, 1e9));
        int ans=1, maxi=n;

        for(auto it: edges){
            v[it[0]][it[1]] = it[2];
            v[it[1]][it[0]] = it[2];
        }

        for(int i=0; i<n; i++) v[i][i]=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(v[j][i]== 1e9 || v[i][k]== 1e9) continue;
                    v[j][k]= min(v[j][k], v[j][i]+v[i][k]);
                }
            }
        }
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(v[i][j] <= distanceThreshold) count++;
            }
            if(maxi >= count) {
                maxi= count;
                ans=i;
            }
        }
        return ans;
    }
};
