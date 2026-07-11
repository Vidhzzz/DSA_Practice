class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int l = 0, r = 0, maxLen = 0;
        unordered_set<char> st;

        for(int i = 0;i < len;i++){
            //if element is present
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }

            //if set is empty 
            st.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
