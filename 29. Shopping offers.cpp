/*
Problem statement:

In LeetCode Store, there are n items to sell. Each item has a price. However, there are some special offers, 
and a special offer consists of one or more different kinds of items with a sale price.
You are given an integer array price where price[i] is the price of the ith item, and an integer array needs where needs[i] 
is the number of pieces of the ith item you want to buy.
You are also given an array special where special[i] is of size n + 1 where special[i][j] is the number of pieces of the jth 
item in the ith offer and special[i][n] (i.e., the last integer in the array) is the price of the ith offer.

Return the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers. 
You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special 
offers as many times as you want.

Example 1:
Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
Output: 14
Explanation: There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
*/

//code:

class Solution {
public:
    
    void helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int n, int k, int& ans){ 
        if(!n) ans=min(ans, k);
        if(k>ans) return;
        
        for(int i=0; i<special.size(); i++){
            bool suff=true;
            int s=0;
            
            for(int j=0; j<needs.size(); j++){
                if(needs[j]<special[i][j]) suff=false;
            }
            
            if(suff){
                for(int j=0; j<needs.size(); j++){
                    needs[j]-=special[i][j];
                    s+=special[i][j];
                }
                helper(price, special, needs, n-s, k+special[i].back(), ans);
                
                for(int j=0; j<needs.size(); j++)
                    needs[j]+=special[i][j];
            }
        }
        
        for(int i=0; i<needs.size(); i++) k+=needs[i]*price[i];
        
        ans=min(ans, k);
        return;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=0, ans= INT_MAX;

        for(auto a:needs) n+=a;
        
        helper(price, special, needs, n, 0, ans);
        return ans;
    }
};
