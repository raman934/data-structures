/* Given n pairs of parentheses, write a function to generate all combinations
   of well-formed parentheses.

    For example, given n = 3, a solution set is:

    [
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
    ]
    
   LC 22. Generate Parentheses
   Author: Shruti
*/

class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        string solution;
        recursiveGenP(solution, 0, 0, n);
        return result;
    }

    // recursively generate each combination of parentheses and populate in result
    // open is the number of open brackets
    // close is the number of close brackets
    void recursiveGenP(string sol, int open, int close, int n) {
        if(open == n && close == n) {
            // all combinations formed
            result.push_back(sol);
            sol = "";
        }
        if(open < n) {
            // open one bracket
            recursiveGenP(sol + "(", open + 1, close, n);
        }
        // close should be always less than open brackets
        if(close < open) {
            // close one bracket
            recursiveGenP(sol + ")", open, close + 1, n);
        }
    }
};
