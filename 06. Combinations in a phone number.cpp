/*
Problem statement:

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

//Implementation

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string phone_map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        backtrack("", digits, phone_map, output);
        return output;
    }

private:
    void backtrack(string combination, string next_digits, string phone_map[], vector<string>& output) {
        if (next_digits.empty()) {
            output.push_back(combination);
        } else {
            string letters = phone_map[next_digits[0] - '2'];
            for (char letter : letters) {
                backtrack(combination + letter, next_digits.substr(1), phone_map, output);
            }
        }
    }
};
