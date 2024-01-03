/*
Problem Statement:

We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
No integer is present in both arr1 and arr2.
Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.
*/

//Implementation code:

//Approach : binary search

class Solution {
public:
    long gcd(long a, long b){
        return (a%b ==0)? b: gcd(b,a%b);
    }
    
    void binarySearch(long l, long h, int d1, int d2, long lcm, long * ans, int c1, int c2){
        if(l<=h){
            long m=(l+h)/2;
            
            long a=m-(m/d1);
            long b=m-(m/d2);
            long c=m-(m/d1)-(m/d2)+(m/lcm);
            
            if(a>=c1 && b>=c2 && a+b-c>=c1+c2){
                (*ans)=m;
                binarySearch(l, m-1, d1, d2, lcm, ans, c1, c2);
            }else
                binarySearch(m+1, h, d1, d2, lcm, ans, c1, c2);
        }
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long g= gcd ( max(divisor1, divisor2), min(divisor1, divisor2));
        long l= (long(divisor1)*long(divisor2))/g;
        
        long ans=1000000000;
        
        binarySearch(0, 10000000000, divisor1, divisor2, l, (&ans), uniqueCnt1, uniqueCnt2);
        
        return int(ans);
    }
};
