class Solution {
public:
    string f(string& a, string& b) {
        string ans = "";

        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int carry = 0;
        int n = std::min(a.size(), b.size());
        int i = 0;
        int j = 0;

        while(i < n && j < n) {
            int x = (a[i] - '0') + (b[j] - '0') + carry;
            if(x == 0) {
                ans += '0';
                carry = 0;
            } else if(x == 1) {
                ans += '1';
                carry = 0;
            } else if(x == 2) {
                ans += '0';
                carry = 1;
            } else if(x == 3) {
                ans += '1';
                carry = 1;
            }
            i++;
            j++;
        }
        while(i < a.size()) {
            int x = (a[i] - '0') + carry;
            if(x == 0) {
                ans += '0';
                carry = 0;
            } else if(x == 1) {
                ans += '1';
                carry = 0;
            } else if(x == 2) {
                ans += '0';
                carry = 1;
            } else if(x == 3) {
                ans += '1';
                carry = 1;
            }
            i++;
        }
        while(j < b.size()) {
            int x = (b[j] - '0') + carry;
            if(x == 0) {
                ans += '0';
                carry = 0;
            } else if(x == 1) {
                ans += '1';
                carry = 0;
            } else if(x == 2) {
                ans += '0';
                carry = 1;
            } else if(x == 3) {
                ans += '1';
                carry = 1;
            }
            j++;
        }
        if(carry) {
            ans += '1';
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }

    string addBinary(string& a, string& b) {
        // n <= 10^4 i.e. f(n) = O(n^2)

        if(a == "0" && b == "0") {
            return "0";
        }
        if(a == "0" && b != "0") {
            return b;
        }
        if(a != "0" && b == "0") {
            return a;
        }

        // // overflow
        // bitset<64> b1(a), b2(b);
        // long long n1 = b1.to_ullong();
        // long long n2 = b2.to_ullong();
        // long long calc = n1 + n2;
        // bitset<64> b3(calc);
        // string s = b3.to_string();
        // int index = s.find_first_not_of('0');
        // s = s.substr(index);
        // return s;

        return f(a, b);
    }
};