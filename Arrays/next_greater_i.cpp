class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        unordered_map<int,int> mpp;
        int n2 = nums2.size();
        vector<int>ans(n1,-1);

        for(int i=0;i<n2;i++)
        mpp[nums2[i]] = i;

        for(int i = 0;i < n1;i++){
            int j = mpp[nums1[i]];

            for(int k = j+1;k < n2;k++){
                if(nums2[k] > nums1[i]){
                    ans[i] = nums2[k];
                    break;
                }
            }
        }
       return ans; 
    }
};
