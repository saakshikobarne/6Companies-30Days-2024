/*
Problem statement:

One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as '#'.

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid.

For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.
*/

class Solution {
public:
    bool isValidSerialization(string a) {
        int i,j,k,c=1,s=0;
        if(a.size()==0) return 1;

        if(a[0]=='#' and a.size()!=1)
        return 0;

        for(i=0;i<a.size();i+=1){
            c-=1;

            if(c<0) return 0;
            if(a[i]!='#') c+=2;
        
            i++;
            while(i<a.size() and a[i]!=',') i++; 
        }
        cout<<c;
        if(c==0)return 1;

        return 0;  
    }
};
