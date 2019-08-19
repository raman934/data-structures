/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D
  and M.

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    Given a roman numeral, convert it to an integer. Input is guaranteed to be
    within the range from 1 to 3999.

    Example 1:

    Input: "III"
    Output: 3
    Example 2:

    Input: "IV"
    Output: 4
    Example 3:

    Input: "IX"
    Output: 9
    Example 4:

    Input: "LVIII"
    Output: 58
    Explanation: L = 50, V= 5, III = 3.
    Example 5:

    Input: "MCMXCIV"
    Output: 1994
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

   LC 13. Roman to Integer
   Author: Shruti
*/

class Solution {
public:
    int romanToInt(string s) {
        if(!s.size()) {
            return 0;
        }
        int result;
        unordered_map<char,int> roman_to_int_map;
        roman_to_int_map['I'] = 1;
        roman_to_int_map['V'] = 5;
        roman_to_int_map['X'] = 10;
        roman_to_int_map['L'] = 50;
        roman_to_int_map['C'] = 100;
        roman_to_int_map['D'] = 500;
        roman_to_int_map['M'] = 1000;
        int len = s.size();
        result =  roman_to_int_map[s[len - 1]]; // start from right, and get the int corresponding val
        // if curr val is less than next val when going from leftward, decrement val from result
        // else add val to result
        for(int i = len - 2; i >= 0; i--) {
            if(roman_to_int_map[s[i]] < roman_to_int_map[s[i+1]]) {
                result -= roman_to_int_map[s[i]];
            } else {
                result += roman_to_int_map[s[i]];
            }
        }
        return result;
    }
};
