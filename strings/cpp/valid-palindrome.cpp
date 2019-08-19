/* Given a string, determine if it is a palindrome, considering only
   alphanumeric characters and ignoring cases.
   Note: For the purpose of this problem, we define empty string as valid
   palindrome.

    Example 1:

    Input: "A man, a plan, a canal: Panama"
    Output: true
    Example 2:

    Input: "race a car"
    Output: false

   LC 125. Valid Palindrome
   Author: Shruti
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.size()) {
            return true;
        }
        for(int i = 0, j = s.size() - 1; i < j;) {
            if(!isalnum(s[i]) && i < j) {
                i++; // if the val is not alpha numeric, go to next val
                continue;
            }
            if(!isalnum(s[j]) && i < j) {
                j--; // if the val is not alpha numeric, go to next val
                continue;
            }
            if(tolower(s[i]) == tolower(s[j])) {
                i++;
                j--; // if vals equal, check inner vals
            } else if(tolower(s[i]) != tolower(s[j])) {
                return false; // if vals unequal, not a palindrome
            }
        }
        return true;
    }
};
