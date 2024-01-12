/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.

Example 1:
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
*/

//code:

class Solution {
public:
    int partitionArray(vector<int>& arr,int low, int high,int pivot){
        int i=low,j=low;
        
        while(i<=high){
            if(arr[i]<=pivot){
                swap(arr[i],arr[j]);
                i++; j++;
            }else
                i++;
        }
        return j-1;
    }

    int quickSelect(vector<int>& arr,int low,int high,int k){
        int pivot=arr[high];
        int partInd=partitionArray(arr,low,high,pivot);
        
        if(partInd==k) return pivot;
        else if(partInd>k) return quickSelect(arr,low,partInd-1,k);
        else return quickSelect(arr,partInd+1,high,k);        
    }

    void wiggleSort(vector<int>& arr) {
        int n=arr.size();
        int mid=quickSelect(arr,0,n-1,n/2);
        vector<int> vec(arr.begin(), arr.end());
        
        for (int i=0, l=0, r=n-1; i<r; ){
            if (vec[i] == mid) i ++;
            else if (vec[i] > mid) swap(vec[i], vec[r--]);
            else swap(vec[l++], vec[i++]);
        }
        
        int m= (n+1)/2;
        
        for(int i=0,j=m-1; j>=0; i=i+2,j--) arr[i]=vec[j];
        for(int i=1,j=n-1; j>=m; i=i+2,j--) arr[i]=vec[j];
    }
};
