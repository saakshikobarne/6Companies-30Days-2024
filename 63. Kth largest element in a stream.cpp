/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, 
not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

*/


//code:

class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0; i<nums.size();i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>size){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
