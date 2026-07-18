class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0;i < n;i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        return gcd(mn, mx);
    }
};
