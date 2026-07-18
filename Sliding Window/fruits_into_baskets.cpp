//approach 1
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        unordered_map<int, int> mpp;   // (num, freq)
        int maxLen = 0, l = 0, r = 0;
        while(r < n){
            mpp[fruits[r]]++;
            //if more than two types
            if(mpp.size() > 2){
                //shrink from left
                mpp[fruits[l]]--;
                //if a type freq = 0 remove that type from map
                if(mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]);

                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

//approach 2
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        unordered_map<int, int> mpp;   // (num, freq)
        int maxLen = 0, l = 0, r = 0;
        while(r < n){
            mpp[fruits[r]]++;
            //if more than two types
            while(mpp.size() > 2){
                //shrink from left
                mpp[fruits[l]]--;
                //if a type freq = 0 remove that type from map
                if(mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]);

                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

//approach 3
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //generate all subarrays and check condition
        int n = fruits.size();
        int maxLen = 0;
        for(int i = 0;i < n;i++){
            set<int> st;
            for(int j = i;j < n;j++){
                st.insert(fruits[j]);
                if(st.size() <= 2)
                maxLen = max(maxLen, j-i+1);
                else
                break;
            }
        }
        return maxLen;
    }
};
