class Solution {
public:
   int longestConsecutive(vector<int>& nums) {
    int n = nums.size();

    unordered_map<int, int> m;
    for(int i=0;i<n;i++)
        m[nums[i]]++;

    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        if(m[nums[i]-1]==0)
            temp.push_back(nums[i]);
    }
     int res=0;
    for(int i=0;i<temp.size();i++)
    {
        int count=0;
        while(m[temp[i]])
        {
            count++;
            temp[i]++;
        }
        res = max(count, res);
    }

   return res;
}
};