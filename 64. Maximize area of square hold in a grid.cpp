/*
There is a grid with n + 2 horizontal bars and m + 2 vertical bars, and initially containing 1 x 1 unit cells.

The bars are 1-indexed.

You are given the two integers, n and m.

You are also given two integer arrays: hBars and vBars.

hBars contains distinct horizontal bars in the range [2, n + 1].
vBars contains distinct vertical bars in the range [2, m + 1].
You are allowed to remove bars that satisfy any of the following conditions:

If it is a horizontal bar, it must correspond to a value in hBars.
If it is a vertical bar, it must correspond to a value in vBars.
Return an integer denoting the maximum area of a square-shaped hole in the grid after removing some bars (possibly none).
*/

//code:

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = hBars.size();
        int v = vBars.size();
        
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        
        int mxh = 1, mxv = 1,curr = 1;
        
        for(int i=1; i<h; i++){
            if(hBars[i] == hBars[i-1] + 1)curr++;
            else curr = 1;
            mxh = max(mxh,curr);
        }

        curr = 1;
        for(int i=1; i<v; i++){
            if(vBars[i] == vBars[i-1] + 1) curr++;
            else curr = 1;
            mxv = max(mxv,curr);
        }

        return min(mxh+1,mxv+1) * min(mxh+1,mxv+1);
    }
};
