class Solution {
public:
    int calculate(string s) {
        stack<int> val;    
        stack<char> opr;    

        int num = 0;
        bool hasNum = false;   // To check if a number is being formed
        char prevOp = '+';     // Assume an initial '+' operator for the first number

        for (int i = 0; i < s.size(); ++i) {
            char it = s[i];

            if (isdigit(it)) { // If the current character is a digit
                num = num * 10 + (it - '0');
                hasNum = true;
            }

            // If it's an operator or the end of the string, process the number
            if (!isdigit(it) && it != ' ' || i == s.size() - 1) {
                if (prevOp == '+') {
                    val.push(num);
                } else if (prevOp == '-') {
                    val.push(-num);
                } else if (prevOp == '*') {
                    int tmp = val.top() * num;
                    val.pop();
                    val.push(tmp);
                } else if (prevOp == '/') {
                    int tmp = val.top() / num;
                    val.pop();
                    val.push(tmp);
                }

                prevOp = it; // Update the previous operator
                num = 0;     // Reset num for the next number
                hasNum = false;
            }
        }

        // Sum up all the values in the stack to get the final result
        int ans = 0;
        while (!val.empty()) {
            ans += val.top();
            val.pop();
        }

        return ans;
    }
};
