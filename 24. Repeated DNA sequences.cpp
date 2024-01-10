/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) 
that occur more than once in a DNA molecule. You may return the answer in any order.

Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
*/

//code:


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        int i=0,j=0;
        int n=s.size();
        map<string,int>mp;
        string str="";
        while(i<n){
            if(str.length()<10 && j<n){
                str+=s[j];
                j++;
            }
            else if(str.length()>=10){
               ans.push_back(str);
               str.erase(str.begin());
               i++;
            }
            else{
                break;
            }
        }
        for(int i=0;i<ans.size();i++){
            mp[ans[i]]++;
        }
        vector<string>res;
        for(auto it:mp){
            if(it.second>1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
