/*
Problem statement:

Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} 
is missing and one number 'B' occurs twice in array. Find these two numbers.
*/

// implementation:

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        vector<int>ans;
        unordered_map<int,int>mp;
        
        //pushing all elements from the array to a map 
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        //finding the number which occurs twice by finding the mapped value
        for(auto it:mp){
            if(it.second==2){
                ans.push_back(it.first);
                break;
            }
        }
        
        //if an element from 1 to n is not foud in the map, we will reach the end of the map
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
