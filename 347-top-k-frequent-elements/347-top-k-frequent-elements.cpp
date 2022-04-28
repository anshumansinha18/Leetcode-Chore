class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


    map<int, int> m;
   for(int i=0;i<nums.size();i++)
       m[nums[i]]++;

   vector<vector<int>> v(nums.size()+1);
   for(auto it = m.begin();it!=m.end();it++)
   {
       v[it->second].push_back(it->first);
   }

   vector<int> res;
   for(int i=nums.size();i>=0;i--)
   {
       if(!v[i].empty() && k>0)
       {
           for(int j=0;j<v[i].size();j++) {
               res.push_back(v[i][j]);
               k--;
           }
       }
   }
   return res;
}

};