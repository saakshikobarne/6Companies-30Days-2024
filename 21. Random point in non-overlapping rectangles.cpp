/*
Problem statement:

You are given an array of non-overlapping axis-aligned rectangles rects where rects[i] = [ai, bi, xi, yi] indicates that (ai, bi) 
is the bottom-left corner point of the ith rectangle and (xi, yi) is the top-right corner point of the ith rectangle. Design an 
algorithm to pick a random integer point inside the space covered by one of the given rectangles. A point on the perimeter of a 
rectangle is included in the space covered by the rectangle.

Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.

Note that an integer point is a point that has integer coordinates.

Implement the Solution class:

Solution(int[][] rects) Initializes the object with the given rectangles rects.
int[] pick() Returns a random integer point [u, v] inside the space covered by one of the given rectangles.
*/

//code:

class Solution {
public:
    vector<vector<int>> rects;

    Solution(vector<vector<int>>& rects) {
        this->rects= rects;
    }
    
    vector<int> pick() {
        int sum= 0;
        vector<int> selected;

        for(auto r: rects){
            int area= (r[2]- r[0]+ 1) * (r[3]- r[1]+ 1);
            sum += area;

            if(rand()% sum< area) selected= r;
        }
        int x= rand()% (selected[2]- selected[0]+1) + selected[0];
        int y= rand()% (selected[3]- selected[1]+1) + selected[1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
