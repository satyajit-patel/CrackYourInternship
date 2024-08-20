class Solution {
public:
    string reverseWords(string s) {
        std::stringstream ss(s);
        string ans = "";
        while(ss.good()) {
            string word;
            std::getline(ss, word, ' ');
            if(!word.empty()) {
                // cout<<word<<endl;
                ans = word + ' ' + ans;
            }
        }
        ans.pop_back();
        
        return ans;
    }
};