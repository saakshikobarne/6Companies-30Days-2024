/*
Prblem statement:

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. 
Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a 
y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and 
rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; 
the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]
*/

//code:

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n=buildings.size();
        vector<vector<int>>ans;
        multiset<int>pq;
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            int x1=buildings[i][0],x2=buildings[i][1],
            h=buildings[i][2];
            arr.push_back({x1,-h});
            arr.push_back({x2,h});
        }
        sort(arr.begin(),arr.end());
        int sz=arr.size();
        pq.insert(0);
        int currHeight=0;
        for(int i=0;i<sz;i++){
            int x=arr[i].first;
            int h=arr[i].second;
        
            if(h<0){
                pq.insert(-h);
                if(*pq.rbegin()!=currHeight){
                    currHeight=*pq.rbegin();
                    ans.push_back({x,currHeight});
                }
            }else{
                pq.erase(pq.find(h));
                if(currHeight!=*pq.rbegin()){
                    currHeight=*pq.rbegin();
                    ans.push_back({x,currHeight});
                }
            }
        }
        return ans;
    }
};
