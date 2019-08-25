/* Implement a basic calculator to evaluate a simple expression string. The
   expression string contains only non-negative integers, +, -, *, / operators
   and empty spaces . The integer division should truncate toward zero.

    Example 1:

    Input: "3+2*2"
    Output: 7
    Example 2:

    Input: " 3/2 "
    Output: 1
    Example 3:

    Input: " 3+5 / 2 "
    Output: 5

  LC 227. Basic Calculator II
  Author: Shruti
*/

class Solution {
    int result = 0;
public:
    int calculate(string s) {
        if(s.empty()) {
            return 0;
        }
        stack<int> nums;
        int num = 0;
        char sign = '+';
        pair<int,int> idx_num;
        // populate all digits in s in nums
        // if a '-' sign precedes a digit, multiply it with num and push
        // if '*' or '/' sign, pop the top digit and multiply or divide with curr digit, push result in stack
        s += '+';
        for(int i = 0; i < s.size(); i++) {
            if(isblank(s[i])) {
                continue;
            } else if(isdigit(s[i])) {
                num = num*10 + (s[i] - '0');
            } else {
                if(sign == '+') {
                    nums.push(num);
                } else if(sign == '-') {
                    nums.push(num*-1);
                } else if(sign == '*') {
                    int temp = nums.top();
                    nums.pop();
                    nums.push(temp*(num));
                } else {
                    int temp = nums.top();
                    nums.pop();
                    nums.push(temp/(num));
                }
                sign = s[i];
                num = 0;
            }
        }
        return getSum(nums);
    }

     // perform addition on all the digits in stack
    int getSum(stack<int> nums) {
        while(!nums.empty()) {
            int temp = nums.top();
            nums.pop();
            result += temp;
        }
        return result;
    }
};
