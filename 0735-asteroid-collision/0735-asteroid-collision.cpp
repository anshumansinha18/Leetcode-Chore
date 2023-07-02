class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        int n = asteroids.size();
        stack<int> st;
        int i=0;
        while(i<n){
            if(!st.empty() && asteroids[i]<0 && st.top()>0){
                if(abs(asteroids[i])>st.top()){
                    st.pop();
                    continue;
                }
                else if(abs(asteroids[i])==st.top()){
                    st.pop();
                }
            }
            else {
                st.push(asteroids[i]);
            }
            i++;
        }
        
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        
        int start=0;
        int end = result.size()-1;
        while(start<end){
            swap(result[start], result[end]);
            start++;
            end--;
        }
        return result;
    }
};