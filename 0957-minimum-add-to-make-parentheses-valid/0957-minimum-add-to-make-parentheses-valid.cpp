class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0,rev=0;
        for(char c:s){
            if(c=='(') {
                count++;
            }
            else{
                count--;
                if (count<0) {
                    rev++;
                    count=0;
                }
            }
        }
        return count+rev;
    }
};