/* Implement a basic calculator to evaluate a simple expression string. The
   expression string may contain open ( and closing parentheses ), the plus +
   or minus sign -, non-negative integers and empty spaces .

    Example 1:

    Input: "1 + 1"
    Output: 2
    Example 2:

    Input: " 2-1 + 2 "
    Output: 3
    Example 3:

    Input: "(1+(4+5+2)-3)+(6+8)"
    Output: 23

   LC 224. Basic Calculator
   Author: Shruti
*/

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int result = 0;
        int sign = '+';
        stack<int> num_stack;
        stack<char> sign_stack;
        if(s[s.size() - 1] != ')') {
            s += '+';
        }
        for(int i = 0; i < s.size(); i++) {
            if(isblank(s[i])) {
                continue;
            } if(s[i] == '(') {
                // put previous result and sign in stacks
                // reset num, result, sign
                num_stack.push(result);
                sign_stack.push(sign);
                num = 0;
                result = 0;
                sign = '+';
            } if(s[i] == ')') {
                // update result with previous sign
                // pop num_stack and sign_stack, calculate cumulative result and push in num_stack
                // reset num, result, sign
                if(sign == '-') {
                    result += -1*num;
                } else {
                    result += num;
                }
                int temp_result = 0;
                int temp_sign = '+';
                if(!num_stack.empty() && !sign_stack.empty()) {
                    temp_result = num_stack.top();
                    temp_sign = sign_stack.top();
                    num_stack.pop();
                    sign_stack.pop();
                }
                if(temp_sign == '-') {
                    result = temp_result + (-1)*result;
                } else {
                    result = temp_result + result;
                }
                num = 0;
                //result = 0;
                //sign = '+';
            } if(s[i] == '+') {
                // update result with previous sign
                if(sign == '-') {
                    result += -1*num;
                } else {
                    result += num;
                }
                // update sign
                sign = '+';
                num = 0;
            } if(s[i] == '-') {
                // update result with previous sign
                if(sign == '-') {
                    result += -1*num;
                } else {
                    result += num;
                }
                // update sign
                sign = '-';
                num = 0;
            } if(isdigit(s[i])) {
                // update num with s[i]
                num = num*10 + (s[i] - '0');
            }
        }

        while(!num_stack.empty()) {
            result += num_stack.top();
            num_stack.pop();
        }
        return result;
    }
};
