class Solution {
public:
    bool doesAliceWin(string s) {
        for (int i = 0; i < s.length(); i++) {
            // If we find a vowel, Alice wins
            if (isVowel(s[i])) {
                return true;
            }
        }
        // If we've gone through the whole string and haven't found a vowel, Bob wins
        return false;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};