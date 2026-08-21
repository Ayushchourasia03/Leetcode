class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int size = arr.size();
        int count = 0;
        for(int i = 0; i < size && count < n; i++){
            if(arr[i] == 0 &&
               (i == 0 || arr[i-1] == 0) &&
               (i == size-1 || arr[i+1] == 0)){
                arr[i] = 1;
                count++;
            }
        }
        return count >= n;
    }
};