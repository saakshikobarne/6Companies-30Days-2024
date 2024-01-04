/*
Problem Statement:

Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm 
to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.
*/   

//Implementation

class Solution{   
public:
    string printMinNumberForPattern(string S){
        
        string ans="";
        for(int i=1;i<=S.size()+1;i++) ans+= '0'+ i;
        
        while(true){
            int j=1,k=0;
            bool f=true;
            
            while(j<ans.size()){
               if(S[k]=='D'&& ans[j] > ans[j-1]){
                swap(ans[j],ans[j-1]);
                f=false;
              } 
              
              if(S[k]=='I' && ans[j] < ans[j-1]){
                  swap(ans[j],ans[j-1]);
                  f=false;
              }
    
              j++; k++;
            }
            
            if(f==true) break;
        }
        return ans;
    }
};
