class Solution {
public:
    int digitFrequencyScore(int n) {

        // freq[i] = number of times digit i appears
        int freq[10] = {0};

        // Count frequency of every digit
        while (n > 0) {
            int last_digit = n % 10;

            freq[last_digit]++;

            n = n / 10;
        }

        // Calculate the score
        int score = 0;

        for (int digit = 0; digit <= 9; digit++) {
            score += digit * freq[digit];
        }

        return score;
    }
};