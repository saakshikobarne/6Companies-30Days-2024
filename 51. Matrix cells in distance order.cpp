/*
Problem statement:

You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell 
with the coordinates (rCenter, cCenter).

Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest 
distance to the largest distance. You may return the answer in any order that satisfies this condition.

The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|. 
*/

//code:

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r0, int c0) {
        vector<vector<int>> ans;
        queue<pair<int, int>> q;
        q.push({r0, c0});

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[r0][c0] = true;

        int dr[4] = {-1, 0, +1, 0};
        int dc[4] = {0, +1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            ans.push_back({r, c});

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        return ans;
    }
};
