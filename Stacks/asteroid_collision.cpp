class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        if(n == 1) return asteroids;
        stack<int>st;

        for(int i = 0;i < n;i++){
            //+ve value
            if(asteroids[i] >= 0 || st.empty())
            st.push(asteroids[i]);

            else{
                //greater magnitude && -ve value
                while(!st.empty() && st.top() < abs(asteroids[i]) && st.top() > 0)
                st.pop();
                //equal and -ve
                if(!st.empty() && st.top() == abs(asteroids[i])) 
                st.pop();
                //stack is empty or tos is -ve
                else {
                    if(st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int>result(st.size());
        for(int i = st.size()-1;i >= 0;i--){
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
