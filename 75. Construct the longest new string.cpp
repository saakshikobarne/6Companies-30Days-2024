/*
You are given three integers x, y, and z.

You have x strings equal to "AA", y strings equal to "BB", and z strings equal to "AB". You want to choose some (possibly all or none) of these strings and concatenate them in some order to form a new string. This new string must not contain "AAA" or "BBB" as a substring.

Return the maximum possible length of the new string.

A substring is a contiguous non-empty sequence of characters within a string.
*/

class Solution {
public:
    int longestString(int x, int y, int z) {
        return (min(x, y + 1) + min(x + 1, y) + z) * 2;
    }
};
