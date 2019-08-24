/* Given a string s, find the longest palindromic substring in s. You may assume
   that the maximum length of s is 1000.

    Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
    Example 2:

    Input: "cbbd"
    Output: "bb"

   LC 5. Longest Palindromic Substring
   Author: Shruti
*/

class Solution {
public:
    string longestPalindrome(string s) {
        // use a 2D bool matrix where every index (i,j) respresents is string from index i to j is palidrome or not
        // initialize the matrix at all (i,j) and (i, j+1) to true or false if palindrome or not
        // populate the matrix bottom up starting from (n-3,n-1) index if nXn matrix, as last two rows filled
        // matrix[i][j] = matrix[i+1][j-1] && (s[i] == s[j])
        // matrix[i+1][j-1] represents the inner string if it is palindrome or not
        // outer characters of the string s[i] and s[j] must be equal for it be a palindrome
        // traverse the matrix to find max string length
        if(s.empty()) {
            return s;
        }
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        int max_len = INT_MIN;
        string result;
        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = true; // each character is a palindrome
            if(i+1 < s.size()) {
                if(s[i] == s[i+1]) {
                    dp[i][i+1] = true;
                } else {
                    dp[i][i+1] = false;
                }
            }
        }
        for(int i = s.size() - 3; i >= 0; i--) {
            for(int j = s.size() - 1; j >= i+2; j--) { // as dp[i][i] && dp[i][i+1] already initialized
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = s.size() - 1; j >= i; j--) {
                if(dp[i][j] == true) {
                    if(j-i+1 > max_len) {
                        max_len = j-i+1;
                        result = s.substr(i,max_len);
                    }
                }
            }
        }
        return result;
    }
};
