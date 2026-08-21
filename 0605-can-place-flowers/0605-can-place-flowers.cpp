class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;
        int c0 = 0;
        int c1 = 0;

        if(size==1){
            if(flowerbed[0]==0) count++;
            return count >= n;
        }

        if(flowerbed[0]==0 && flowerbed[1]==0){
            count++;
            flowerbed[0]=1;
        }
        for(int i=1;i<=size-2;i++){
            if (flowerbed[i]==1){
                continue;
            } else if(flowerbed[i-1]==0 && flowerbed[i] == 0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                count++;
            }
        }
        if(flowerbed[size-1]==0 && flowerbed[size-2]==0){
            count ++;
        }
        if(count >= n){
            return true;
        }else {
            return false;
        }
    }
};