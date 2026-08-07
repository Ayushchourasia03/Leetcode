class Solution {
public:
    unordered_map<int, unordered_map<int, int>> kFactorCounts = {
        {0, {}},
        {1, {}},
        {2, {{2, 1}}},
        {3, {{3, 1}}},
        {4, {{2, 2}}},
        {5, {{5, 1}}},
        {6, {{2, 1}, {3, 1}}},
        {7, {{7, 1}}},
        {8, {{2, 3}}},
        {9, {{3, 2}}}
    };

    string smallestNumber(string num, long long t) {
        auto primeInfo = getPrimeCount(t);
        auto primeCount = primeInfo.first;

        if (!primeInfo.second)
            return "-1";

        auto factorCount = getFactorCount(primeCount);

        if (sumValues(factorCount) > (int)num.size())
            return construct(factorCount);

        auto primeCountPrefix = getPrimeCountFromString(num);

        int firstZeroIndex = num.find('0');
        if (firstZeroIndex == string::npos) {
            firstZeroIndex = num.size();
            if (isSubset(primeCount, primeCountPrefix))
                return num;
        }

        for (int i = (int)num.size() - 1; i >= 0; i--) {
            int d = num[i] - '0';

            primeCountPrefix = subtract(primeCountPrefix, kFactorCounts[d]);

            int spaceAfterThisDigit = num.size() - 1 - i;

            if (i > firstZeroIndex)
                continue;

            for (int biggerDigit = d + 1; biggerDigit <= 9; biggerDigit++) {
                auto temp = subtract(primeCount, primeCountPrefix);
                temp = subtract(temp, kFactorCounts[biggerDigit]);

                auto factorsAfterReplacement = getFactorCount(temp);

                if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {
                    int fillOnes =
                        spaceAfterThisDigit - sumValues(factorsAfterReplacement);

                    return num.substr(0, i) +
                           string(1, char('0' + biggerDigit)) +
                           string(fillOnes, '1') +
                           construct(factorsAfterReplacement);
                }
            }
        }

        auto factorsAfterExtension = getFactorCount(primeCount);

        return string(num.size() + 1 - sumValues(factorsAfterExtension), '1') +
               construct(factorsAfterExtension);
    }

private:
    pair<unordered_map<int, int>, bool> getPrimeCount(long long t) {
        unordered_map<int, int> count = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};

        for (int p : {2, 3, 5, 7}) {
            while (t % p == 0) {
                t /= p;
                count[p]++;
            }
        }

        return {count, t == 1};
    }

    unordered_map<int, int> getPrimeCountFromString(const string &num) {
        unordered_map<int, int> count = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};

        for (char c : num) {
            int d = c - '0';
            for (auto &x : kFactorCounts[d])
                count[x.first] += x.second;
        }

        return count;
    }

    unordered_map<int, int> getFactorCount(unordered_map<int, int> count) {
        unordered_map<int, int> res;

        int cnt8 = count[2] / 3;
        int rem2 = count[2] % 3;

        int cnt9 = count[3] / 2;
        int cnt3 = count[3] % 2;

        int cnt4 = rem2 / 2;
        int cnt2 = rem2 % 2;

        int cnt6 = 0;

        if (cnt2 && cnt3) {
            cnt2 = 0;
            cnt3 = 0;
            cnt6 = 1;
        }

        if (cnt3 && cnt4) {
            cnt2 = 1;
            cnt6 = 1;
            cnt3 = 0;
            cnt4 = 0;
        }

        res[2] = cnt2;
        res[3] = cnt3;
        res[4] = cnt4;
        res[5] = count[5];
        res[6] = cnt6;
        res[7] = count[7];
        res[8] = cnt8;
        res[9] = cnt9;

        return res;
    }

    string construct(unordered_map<int, int> &factors) {
        string res;
        for (int d = 2; d <= 9; d++)
            res.append(factors[d], char('0' + d));
        return res;
    }

    bool isSubset(unordered_map<int, int> &a,
                  unordered_map<int, int> &b) {
        for (auto &x : a)
            if (b[x.first] < x.second)
                return false;
        return true;
    }

    unordered_map<int, int> subtract(unordered_map<int, int> a,
                                     unordered_map<int, int> &b) {
        for (auto &x : b)
            a[x.first] = max(0, a[x.first] - x.second);
        return a;
    }

    int sumValues(unordered_map<int, int> &mp) {
        int s = 0;
        for (auto &x : mp)
            s += x.second;
        return s;
    }
};