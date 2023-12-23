class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> m;
        for(int i=0;i<position.size();i++){
            m[position[i]]=speed[i];
        }
        stack<float> st;
        
        for(auto it: m){
            float time = (target-it.first)/(float)it.second;
            while(!st.empty() && time>=st.top()){
                st.pop();
            }
            st.push(time);
        }
        
        return st.size();
    }
};