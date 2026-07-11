class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int lsum = 0;
        for(int i = 0;i < k;i++) 
        lsum += cardPoints[i];

        int maxSum = lsum, r = n-1, rsum = 0;
        for(int i = k-1;i >= 0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[r];
            r--;
            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};
