class Solution {
public:
    int minInsertions(string s) {
        stack<int> my_stack;
        int ins=0;
        int open=0;
        for(char c:s){
            if(c=='('){
                if(open%2!=0){
                    ins++;
                    open--;
                }
                open+=2;
            }
            else{
                if(open==0) {
                    ins++; 
                    open++;
                }
                else{
                    open--;
                }
            }
        }
        ins+=open;
        return ins;
    }
};