/*
Problem Statement:

Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.
*/

string encode(string s){  
    
    int n= s.length();
    if(n==0) return "";
    
    string res="";
    
    for(int i=0; i<n; i++){
        int cnt=1;
        
        while(i<n-1 && s[i] == s[i+1]){
            cnt++;
            i++;
        }
        res+= s[i] + to_string(cnt);
    }
    return res;
}  
