class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        
        int n = asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top())
                    st.pop();
                if(!st.empty() && st.top()>0 && abs(asteroids[i])==st.top()){
                    st.pop();
                    continue;
                }
                if(st.empty() || st.top()<0) st.push(asteroids[i]);
            }
        }
        vector<int> res(st.size());
        int i=res.size()-1;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            res[i--]=x;
        }
        return res;
    }
};