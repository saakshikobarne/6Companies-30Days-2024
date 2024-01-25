/*
You are given a positive integer p. Consider an array nums (1-indexed) that consists of the integers in the inclusive 
range [1, 2p - 1] in their binary representations. You are allowed to do the following operation any number of times:

Choose two elements x and y from nums.
Choose a bit in x and swap it with its corresponding bit in y. Corresponding bit refers to the bit that is in the same 
position in the other integer.
For example, if x = 1101 and y = 0011, after swapping the 2nd bit from the right, we have x = 1111 and y = 0001.

Find the minimum non-zero product of nums after performing the above operation any number of times. 
Return this product modulo 109 + 7.

Note: The answer should be the minimum product before the modulo operation is done.
*/

//code:

#define mod 1000000007
class Solution {
    private:
    long long power(long long x, long long y){
        if(y==0) return 1;
        
        long long ans = power(x,y/2);
        if(y%2 == 0) return (ans*ans)%mod;
        else return(((ans*ans)%mod)*(x%mod))%mod;
    }
    
public:
    int minNonZeroProduct(int p) {
        long long maxi = pow(2,p);
        long long max = maxi - 1;
        long long result = power((max-1), ((max-1)/2));
        return (result*(max%mod))%mod;
    }
};
