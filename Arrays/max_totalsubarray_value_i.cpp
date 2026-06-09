class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        vector<int> arr = nums;  

        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        long long bestValue = (long long)mx - (long long)mn;
        return bestValue * k;
    }
};
