class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        set<int> st;
        int n1=nums1.size();
        int n2 = nums2.size();
        for(int i=0;i<n1;i++){
            m1[nums1[i]]++;
        }
        
        for(int j=0;j<n2;j++){
            m2[nums2[j]]++;
        }
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0;i<n1;i++){
            if(!m2[nums1[i]]) st.insert(nums1[i]);
        }
        
        
        for(auto it: st) temp.push_back(it);
        res.push_back(temp);
        st.clear();
        temp.clear();
        for(int i=0;i<n2;i++){
            if(!m1[nums2[i]]) st.insert(nums2[i]);
        }
        for(auto it: st) temp.push_back(it);
        st.clear();
        res.push_back(temp);
        
       return res;
    }
};