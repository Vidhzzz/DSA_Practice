//Approach 1 - two loops
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = 0;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                maxProduct = max(maxProduct, (nums[i]-1)*(nums[j]-1));
            }
        }
        return maxProduct;
    }
};

//Approach 2 - sort n return last two
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};

//Approach 3 - one track pass
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;

        for(int i = 0;i < nums.size();i++){
            if(max1 <= nums[i]){
                max2 = max1;
                max1 = nums[i];
            }
            else if(max2 <= nums[i])
            max2 = nums[i];
        }
        return (max1-1)*(max2-1);
    }
};

//Approach 4 - priority queue of size 2(min heap)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0;i < nums.size();i++){
            if(pq.size() < 2)
            pq.push(nums[i]);
            else if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int i = pq.top()-1;
        pq.pop();

        return i*(pq.top()-1);
    }
};
