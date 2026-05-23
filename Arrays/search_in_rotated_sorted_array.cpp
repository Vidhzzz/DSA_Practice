class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n = nums.size();
        int lo = 0;
        int hi = n-1;

        while(lo <= hi){
            int mid = (hi-lo)/2+lo;
            if(nums[mid] == target)
            return mid;
            //check id left half sorted
            else if(nums[lo] <= nums[mid]){
                //if target lies here
                if(nums[lo] <= target && target <= nums[mid])
                hi = mid-1;
                else
                lo = mid+1;
            }
            //right half is sorted
            else{
                if(nums[mid] <= target && target <= nums[hi])
                lo = mid+1;
                else
                hi = mid-1;
            }
        }
        return -1;
    }
};
