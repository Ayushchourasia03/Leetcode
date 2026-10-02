class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = isPrime[1] = false;

        // 2 is prime
        int count = 1;

        // Only consider odd numbers
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;

                // No need to mark if i*i >= n
                if (1LL * i * i < n) {
                    for (int j = i * i; j < n; j += 2 * i) {
                        isPrime[j] = false;
                    }
                }
            }
        }

        return count;
    }
};