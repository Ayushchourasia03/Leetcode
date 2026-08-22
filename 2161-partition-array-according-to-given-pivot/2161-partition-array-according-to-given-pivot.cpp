class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        int index = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                result[index] = nums[i];
                index++;
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] == pivot){
                result[index] = nums[i];
                index++;
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > pivot){
                result[index] = nums[i];
                index++;
            }
        }

        return result;
    }
};