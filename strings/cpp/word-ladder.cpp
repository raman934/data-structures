/* Given two words (beginWord and endWord), and a dictionary's word list, find
   the length of shortest transformation sequence from beginWord to endWord,
   such that:
   Only one letter can be changed at a time.
   Each transformed word must exist in the word list. Note that beginWord is
   not a transformed word.

   Note:
    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
    Example 1:

    Input:
    beginWord = "hit",
    endWord = "cog",
    wordList = ["hot","dot","dog","lot","log","cog"]

    Output: 5

    Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
    "dog" -> "cog",
    return its length 5.
    Example 2:

    Input:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log"]

    Output: 0

    Explanation: The endWord "cog" is not in wordList, therefore no possible
    transformation.

   LC 127. Word Ladder
   Author: Shruti
*/

class Solution {
    queue<string> q; // q to store current word being transformed and its adjacent words found
    int result = 0;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto s : wordList) {
            words.insert(s);
        }
        if(words.find(endWord) == words.end()) {
            return 0; // end word is not in wordList
        }
        q.push(endWord); //start with the last word
        result++;
        words.insert(beginWord); //need to search till we hit begin word
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                string temp = q.front();
                q.pop();
                if(temp == beginWord) {
                    return result;
                }
                getTransformedWords(temp, words);
            }
            result++;
        }
        return 0;
    }

    void getTransformedWords(string temp, unordered_set<string>& words) {
        for(int i = 0; i < temp.size(); i++) {
            char letter = temp[i];
            for(int j = 0; j < 26; j++) {
                temp[i] = 'a' + j; // replace the curr letter with a letter from 'a' to 'z'
                if(words.find(temp) != words.end()) {
                    words.erase(temp); // if word found in set, remove it and push in queue
                    q.push(temp);
                    cout << temp << endl;
                }
            }
            temp[i] = letter; // put the letter back in place
        }
    }
};
