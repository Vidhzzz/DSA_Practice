class Solution {
public:
    vector<vector<int>> result;
    vector<int>ds;
    int n;

    void func(int ind, vector<int>& candidates, int target){
        //base case
        if(ind == n){
            if(target == 0)
            result.push_back(ds);
            return;
        }
        //pick
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            func(ind, candidates, target-candidates[ind]);
            ds.pop_back();
        }
        //unpick
        func(ind+1, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        func(0, candidates, target);
        return result;
    }
};
