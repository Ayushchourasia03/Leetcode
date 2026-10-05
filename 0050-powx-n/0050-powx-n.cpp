class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long copyn = n;

        if (copyn<0) copyn = -1*copyn;
        while(copyn){
            if(copyn%2){
                ans = ans*x;
                copyn = copyn-1;
            }
            else{
                x = x*x;
                copyn = copyn/2;
            }
        }
        if (n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};