class Solution {
public:
    int minSwaps(string s) {
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='[')st.push('[');
        else{
            if(!st.empty() && st.top()=='[')st.pop();
            else st.push(']');
        }
    }
    if((st.size()/2)%2==1)
    return (st.size()/2)/2+1;  
    return (st.size()/2)/2;
    }
};