/*
We have a wooden plank of the length n units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second. 
Some of the ants move to the left, the other move to the right.

When two ants moving in two different directions meet at some point, they change their directions and continue moving again. 
Assume changing directions does not take any additional time.

When an ant reaches one end of the plank at a time t, it falls out of the plank immediately.

Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right, 
return the moment when the last ant(s) fall out of the plank.
*/

//code:

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = left.empty()?0: *max_element(left.begin(), left.end());
        int minRight = right.empty()?n : *min_element(right.begin(), right.end());
        return max(maxLeft, n-minRight);
    }
};
