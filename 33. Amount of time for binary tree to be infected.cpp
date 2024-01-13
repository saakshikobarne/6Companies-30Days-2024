/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.
*/

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        dfs(root, graph);

        return bfs(graph, start);
    }
private:
    void dfs(TreeNode* curr, unordered_map<int, vector<int>>& graph) {
        if (curr == NULL) return;

        if (curr->left != NULL) {
            graph[curr->val].push_back(curr->left->val);
            graph[curr->left->val].push_back(curr->val);
        }
        if (curr->right != NULL) {
            graph[curr->val].push_back(curr->right->val);
            graph[curr->right->val].push_back(curr->val);
        }

        dfs(curr->left, graph);
        dfs(curr->right, graph);
    }
    int bfs(unordered_map<int, vector<int>>& graph, int start) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);

        int time = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                for (auto& next : graph[curr]) {
                    if (visited.count(next) != 0) continue;
                    q.push(next);
                    visited.insert(next);
                }
            }
            time++;
        }
        return time;
    }
};
