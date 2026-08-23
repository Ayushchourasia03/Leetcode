class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' ||
               ch == 'O' || ch == 'U';
    }

    string reverseVowels(string s) {

        int left = 0;
        int right = s.length() - 1;

        while(left < right) {

            // Move left until we find a vowel
            while(left < right && !isVowel(s[left])) {
                left++;
            }

            // Move right until we find a vowel
            while(left < right && !isVowel(s[right])) {
                right--;
            }

            // Swap the vowels
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};