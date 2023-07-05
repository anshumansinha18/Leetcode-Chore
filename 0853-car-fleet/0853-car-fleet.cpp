class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        map<int, double> m;
        int n = position.size();
        for(int i=0;i<n;i++){
            m[position[i]] = (target-position[i])/(double)speed[i];
        }
        stack<double> st;
        for(auto it: m){
            cout<<it.second<<endl;
            while(!st.empty() && it.second>=st.top())
                st.pop();
            
            st.push(it.second);
        }
        
        return st.size();
        
    }
};