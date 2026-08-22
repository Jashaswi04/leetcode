class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int x=n;
        while (x!=0){
            int rem=x%10;
            x=x/10;
            sum+=rem;
            prod*=rem;
        }
        cout<<sum+prod;
        return n%(sum+prod)==0;
    }
};