//using recursion  -- TLE
class Solution {
public:     
    int n;
    unordered_map<int, int> mpp;
    bool solve(vector<int>& stones, int csi, int prev_jump){
        if(csi == n-1) return true;

        bool result = false;

        //try all three possible k's (k+1), (k), (k-1)
        for(int next_jump = prev_jump-1;next_jump <= prev_jump+1;next_jump++){
            if(next_jump > 0){
                int next_stone = stones[csi] + next_jump;

                if(mpp.find(next_stone) != mpp.end())
                result = result || solve(stones, mpp[next_stone], next_jump);
            }
        }
        return result;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
        return false;

        n = stones.size();
        for(int i = 0;i < n;i++)
        mpp[stones[i]] = i;

        return solve(stones, mpp[0], 0);
    }
};

//using 2D dp
class Solution {
public:     
    int n;
    unordered_map<int, int> mpp;
    int t[2001][2001];
    bool solve(vector<int>& stones, int csi, int prev_jump){
        if(csi == n-1) return true;

        if(t[csi][prev_jump] != -1)
        return t[csi][prev_jump];
        bool result = false;

        //try all three possible k's (k+1), (k), (k-1)
        for(int next_jump = prev_jump-1;next_jump <= prev_jump+1;next_jump++){
            if(next_jump > 0){
                int next_stone = stones[csi] + next_jump;

                if(mpp.find(next_stone) != mpp.end())
                result = result || solve(stones, mpp[next_stone], next_jump);
            }
        }
        return t[csi][prev_jump] = result;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)
        return false;


        n = stones.size();
        for(int i = 0;i < n;i++)
        mpp[stones[i]] = i;

        if()

        memset(t, -1, sizeof(t));i
        return solve(stones, mpp[0], 0);
    }
};
