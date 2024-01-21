/*
Problem Statement:

You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.

Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.
*/

//code:

class Solution {
public:
  
  int solveEquation(pair<int,int>& p1,pair<int,int>& p2,pair<int,int> p3){
      int x1=p1.first;
      int x2=p2.first;
      int x3=p3.first;

      int y1=p1.second;
      int y2=p2.second;
      int y3=p3.second;

      return (y3-y2)*(x2-x1)-(y2-y1)*(x3-x2);
  }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());
        vector<vector<int>> ans;
        deque<pair<int,int>> lower,upper;

        for(auto& points:trees){

        int l=lower.size();
        int u=upper.size();
           
           while(l>=2 && solveEquation(lower[l-1],lower[l-2],{points[0],points[1]})<0){
               l--;
               lower.pop_back();
           }

           while(u>=2 && solveEquation(upper[u-1],upper[u-2],{points[0],points[1]})>0){
               u--;
               upper.pop_back();
           }
           lower.push_back({points[0],points[1]});
           upper.push_back({points[0],points[1]});
        }

        set<pair<int,int>> st;

        for(auto &it:lower) st.insert(it);
        for(auto &it:upper) st.insert(it);
        for(auto it:st) ans.push_back({it.first,it.second});
    
        return ans;
    }
};
