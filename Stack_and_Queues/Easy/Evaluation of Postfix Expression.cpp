// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
class Solution {
public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S) {
        stack<int> st;
        
        for(auto& it: S) {
            if(std::isalnum(it)) {
                st.push(it - '0');
            } else {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                
                if(it == '+') {
                    st.push(x + y);
                } else if(it == '-') {
                    st.push(x - y);
                } else if(it == '*') {
                    st.push(x * y);
                } else if(it == '/') {
                    st.push(x / y);
                }
            }
        }
        
        return st.top();
    }
};
