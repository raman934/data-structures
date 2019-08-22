/* Given a string containing digits from 2-9 inclusive, return all possible
   letter combinations that the number could represent.
   A mapping of digit to letters (just like on the telephone buttons) is given
   below. Note that 1 does not map to any letters.

    Example:

    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

   LC 17. Letter Combinations of a Phone Number
   Author: Shruti
*/

class Solution {
    vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) {
            return result;
        }
        // call a recursive function that generates all combination
        combine(digits, 0, "");
        return result;
    }

    void combine(string& digits, int dig_idx, string cmbntn) {
        if(cmbntn.size() == digits.size()) {
            result.push_back(cmbntn); // if the cmbntn size is equal to digits size, we
            return;
        }
        string s = letters[digits[dig_idx] - '0']; // get the letters corresponding to digit
        // e.g. '2' - '0' = 2
        // s now equals "abc"
        // for each character in s, combine it with every character in subsequent digits
        for(int i = 0; i < s.size(); i++) {
            combine(digits, dig_idx + 1, cmbntn + s[i]);
        }
    }
};
