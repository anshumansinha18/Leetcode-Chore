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
            if(st.empty())
            {
                st.push(position[i]);
                double t = (target - position[i])/(double)m[position[i]];
                time = t;
                cout<<"first"<<endl;
            }
            else
            {
                st.push(position[i]);
                double t = (target - position[i])/(double)m[position[i]];
                cout<<"second"<<endl;
                if(time>=t){
                    st.pop();
                     cout<<"second"<<endl;
                }
                
                else
                    time = t;
                // cout<<"yes";
            }
        }
        
   
        
        
        return st.size();
    }
};