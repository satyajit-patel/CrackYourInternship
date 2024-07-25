class Solution {
public:
    void check(string& s) {
        while(1) {
            int index = s.find('#');
            if(index == -1) {
                break;
            } else {
                if(index == 0) {
                    s.erase(index, 1); // startIdex, size => 1 ele gets deleted
                } else {
                    s.erase(index-1, 2); // 2 ele gets deleted
                }
            }
        }
    }

    string solveUsingStack(string& s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(!st.empty() && s[i] == '#') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string ans = "";
        while(!st.empty()) {
            char ch = st.top();
            st.pop();
            ans = ch + ans;
        }
        return ans;
    }

    bool backspaceCompare(string s, string t) {
        // check(s);
        // check(t);
        // return s == t;

            // or
        
        string ns = solveUsingStack(s);
        string nt = solveUsingStack(t);
        // cout<<ns<<"->"<<nt<<endl;
        return ns == nt;
    }
};