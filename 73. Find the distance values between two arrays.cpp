/*
Problem statement:

Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

 
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = arr1.size();
        for(auto num : arr1){
            for(auto i : arr2){
                if(abs(num - i) <= d){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};
