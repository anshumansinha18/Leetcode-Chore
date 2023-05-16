class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        unordered_map<int, int> m;
        
        stack<int> st;
        
        for(int i=0;i<n2;i++){
            
            while(!st.empty() && nums2[i]>st.top()){
                m[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        while(!st.empty()){
            m[st.top()]=-1;
            st.pop();
        }
        
        vector<int> res;
        
        for(int i=0;i<n1;i++){
           res.push_back(m[nums1[i]]);   
        }
        
        return res;
    }
};