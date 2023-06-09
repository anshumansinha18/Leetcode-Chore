class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
        }
        
        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]++;
        }
        
        vector<vector<int>> res;
        unordered_set<int> x,y;
        for(int i=0;i<nums1.size();i++){
            if(m2.find(nums1[i])==m2.end())
                x.insert(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++){
            if(m1.find(nums2[i])==m1.end())
                y.insert(nums2[i]);
        }
        vector<int> a,b;
        for(auto it: x){
           a.push_back(it);
        }
         for(auto it: y){
           b.push_back(it);
        }
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};