/*
Problem statement:

Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. 
The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing 
the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
*/

//code:

class Solution {
public:

    vector<vector<int>>vec;

    bool check(vector<int>&a,vector<int>&b){       
        for(int i=0;i<a.size();i++)
            for(int j=0;j<b.size();j++)
                if(a[i]==b[j]) return false;
        return true;
    }

    bool isPali(string &s,vector<int>&ans){
        int a=0,b=ans.size()-1;
        while(a<=b){
            if(s[ans[a]]!=s[ans[b]]) return false;
            a++; b--;
        }
        return true;    
    }

    void calc(string &s,vector<int>&ans,int i){
        if(isPali(s,ans)) vec.push_back(ans);
        
        if(i>=s.length()) return;

        ans.push_back(i);
        calc(s,ans,i+1);

        ans.pop_back();
        calc(s,ans,i+1);
    }

    int maxProduct(string s) {
        int ans=0;
        vector<int>a;

        calc(s,a,0);

        for(int i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){    

                int x=(int)vec[i].size()*vec[j].size();
                if(x>ans&&check(vec[i],vec[j])) ans=x;
            }
        }
        return ans;
    }
};
