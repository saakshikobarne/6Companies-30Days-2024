/*
Problem Statement:

You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. 
You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents
the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y 
at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. 
If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
*/

//code:

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size(), size = changed.size();
        vector<vector<int>> adjMat(26, vector<int>(26, 1e9));

        for(int i = 0 ; i < size ; i++){
            int x = original[i] - 'a', y = changed[i] - 'a';
            adjMat[x][y] = min(cost[i], adjMat[x][y]);
        }

        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < 26 ; j++){
                for(int k = 0 ; k < 26 ; k++)
                    adjMat[j][k] = min(adjMat[j][k], adjMat[j][i] + adjMat[i][k]);
            }
        }

        long minCost = 0;
        for(int i = 0 ; i < n ; i++){
            if(source[i] != target[i]){
                int x = source[i] - 'a', y = target[i] - 'a';
                
                if(adjMat[x][y] == 1e9) return -1;
                minCost += adjMat[x][y];
            }
        }
        return minCost;
    }
};
