class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/")
            {
                string ch=tokens[i];
                int op2=(st.top());
                st.pop();
                int op1=(st.top());
                st.pop();
                int val=ch=="+"?op1+op2:ch=="-"?op1-op2:ch=="*"?op1*op2:op1/op2;
                st.push(val);
            }
            else
            st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};