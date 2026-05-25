class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int zero = 0, non_zero = 0;
        while(non_zero < n){
                if(nums[non_zero] != 0){
                    swap(nums[zero], nums[non_zero]);
                    zero++;
                }
                non_zero++;
        }
    }
};
