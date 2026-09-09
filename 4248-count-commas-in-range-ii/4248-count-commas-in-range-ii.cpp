class Solution {
public:
    long long countCommas(long long n) {
        long long prev=0;
        if(n<1000) return 0;
        if(n<1e6) return n-999;
        prev+=1e6-1e3;
        if(n<1e9) return prev+2*(n-1e6+1);
        prev+=2e9-2e6;
        if(n<1e12) return prev+3*(n-1e9+1);
        prev+=3e12-3e9;
        if(n<1e15) return prev+4*(n-1e12+1);
        prev+=4e15-4e12;
        return prev+5; 
    }
};