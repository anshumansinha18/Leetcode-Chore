class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        
        stack<int> s1;
        stack<int> s2;
        s1.push(temperatures[0]);
        s2.push(0);
        
        vector<int> ans(n, 0);
        
        for(int i=1;i<n;i++)
        {
           while(!s1.empty() && temperatures[i]>s1.top())
            {
                s1.pop();
                int x = s2.top();
                s2.pop();
                ans[x] = i-x;
            }
            
            s1.push(temperatures[i]);
            s2.push(i);
        }
        
//         while(!s1.empty())
//         {
//             int x = s2.top();
//             ans[x] =0;
//             s1.pop();
//             s2.pop();
//         }
        
        return ans;
    }
};