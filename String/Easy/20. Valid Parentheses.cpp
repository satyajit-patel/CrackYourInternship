class Solution {
public:
    bool isopen(char it) {
        return (it == '(') || (it == '{') || (it == '[');
    }

    bool isclose(char it) {
        return (it == ')') || (it == '}') || (it == ']');
    }

    bool isValid(string& s) {
        stack<char> st;
        for(auto& it: s) {
            if(isopen(it)) {
                st.push(it);
            } else if(isclose(it)) {
                if(st.empty()) {
                    return false;
                } else if(it == ')' &&  st.top() != '(') {
                    return false;
                } else if(it == '}' &&  st.top() != '{') {
                    return false;
                } else if(it == ']' &&  st.top() != '[') {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};