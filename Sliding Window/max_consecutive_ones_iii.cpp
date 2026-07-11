//Approach 1
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, n = nums.size();
        int l = 0, r = 0, zeros = 0;

        while(r < nums.size()){
            if(nums[r] == 0)
            zeros++;

            //increment the left pointer only by 1 maintaining the window size to maxLen 
            if(zeros > k){
                if(nums[l] == 0) 
                zeros--;

                l++;
            }
            //update when zeros are inder conditon otherwise keep incrementing left n right and maintain maxLen
            if(zeros <= k)
            maxLen = max(maxLen, r-l+1);

            r++;
        }
        return maxLen;
    }
};

//Approach 2
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, n = nums.size();
        int l = 0, r = 0, zeros = 0;

        while(r < nums.size()){
            if(nums[r] == 0)
            zeros++;

            //till the count of zeros comes under condition keep shrinking the window size from left
            while(zeros > k){
                if(nums[l] == 0) 
                zeros--;

                l++;
            }
            if(zeros <= k)
            maxLen = max(maxLen, r-l+1);

            r++;
        }
        return maxLen;
    }
};
