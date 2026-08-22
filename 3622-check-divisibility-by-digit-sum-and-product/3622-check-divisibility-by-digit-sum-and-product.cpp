class Solution {
public:
    bool checkDivisibility(int n) {
        int dsum = 0;
        long long prod = 1;
        int num = n;
        while(num > 0){
            int last = num % 10;
            num = num / 10;
            dsum = dsum + last;
            prod = prod * last;
        }
        long long total = dsum + prod;
        if(n % total == 0){
            return true;
        } else return false;
    }
};