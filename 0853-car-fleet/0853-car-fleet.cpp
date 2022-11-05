class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        
        unordered_map<int, int> m;
        
        for(int i=0;i<n;i++)
            m[position[i]] = speed[i];
        sort(position.begin(), position.end());
        
        stack<int> st;
        
        double time;
        
        for(int i=n-1;i>=0;i--)   
        {
            st.push(position[i]);
            double t = (target - position[i])/(double)m[position[i]];
           
                if(time>=t)
                    st.pop();
                else
                    time = t;        
        }
        
        return st.size();
    }
};