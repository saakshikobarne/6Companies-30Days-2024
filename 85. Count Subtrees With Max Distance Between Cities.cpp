/*
There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.

A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.

For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.

Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.

Notice that the distance between the two cities is the number of edges in the path between them.
*/

//code:

vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    vector<vector<int>> d(n, vector<int>(n, n));
    for (auto &e : edges)
        d[e[0] - 1][e[1] - 1] = d[e[1] - 1][e[0] - 1] = 1;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    vector<int> res(n - 1, 0);
    for (int s = 0; s < 1 << n; ++s) {
        int max_depth = 0, nodes = 0, edges = 0;
        for (int i = 0; i < n; ++i)
            if (s & (1 << i)) {
                ++nodes;
                for (int j = i + 1; j < n; ++j)
                    if (s & (1 << j)) {
                        edges += d[i][j] == 1;
                        max_depth = max(max_depth, d[i][j]);
                    }
            }
        if (edges == nodes - 1 && max_depth > 0)
            ++res[max_depth - 1];
    }
    return res;
}

