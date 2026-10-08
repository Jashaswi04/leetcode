class Solution {
public:
    string removeOuterParentheses(string s) {
        bool found=0;
        stack<int> my_stack;
        string res="";
        for(char c:s){
            if (c=='('){
                if(found==0) found=1;
                else{
                my_stack.push('(');
                res+="(";
                }
            }
            else{
                if(my_stack.empty()) found=0;
                else{
                    my_stack.pop();
                    res+=")";
                }
            }
        }
        return res;
    }
};