/*
Problem statement:

There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.
A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:

age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
Otherwise, x will send a friend request to y.

Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.
Return the total number of friend requests made.
*/

//code:

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
       sort(ages.begin(),ages.end());
        int count =0;

        for(int i=0;i<ages.size();i++){
            int val=ages[i]/2+7;
            
            if(ages[i]<=val) continue;
            
            int ind1=upper_bound(ages.begin(),ages.end(),val)-ages.begin();
            int ind2=upper_bound(ages.begin(),ages.end(),ages[i])-ages.begin();
            
            ind2--;         
            if(ind2>=ind1) count+=ind2-ind1;
         }
        
        return count;
    }
};
