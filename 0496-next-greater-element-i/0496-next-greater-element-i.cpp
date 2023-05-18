class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> m;
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        
        
        for(int i=0;i<n2;i++){
            
            while(!st.empty() && nums2[i]>st.top())
            {
                m[st.top()] = nums2[i];
                st.pop();
            }
            
            st.push(nums2[i]);
        }
        
        vector<int> res;
        for(int i=0;i<n1;i++){
            if(m[nums1[i]])
                res.push_back(m[nums1[i]]);
            else
                res.push_back(-1);
        }
                           
        return res;
        
    }
};