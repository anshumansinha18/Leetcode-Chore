class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    for(int i=0;i<l.size();i++) {
        int maxElem = INT_MIN, minElem = INT_MAX;

        for (int j = l[i]; j <= r[i]; j++) {
            maxElem = max(nums[j], maxElem);
            minElem = min(nums[j], minElem);
        }

        int n = r[i] - l[i] + 1;
        if (maxElem == minElem) res.push_back(true);
        else if ((maxElem - minElem) % (n - 1)) res.push_back(false);
        else {
            int d = (maxElem-minElem)/(n-1);

            unordered_map<int,int> m;

            for(int j=l[i];j<=r[i];j++)
                m[nums[j]]++;

            int x = minElem;
            while(n--)
            {
                if(m[x]==0) {
                    res.push_back(false);
                    break;
                }
                x = x + d;
            }

            if(n==-1) res.push_back(true);
        }
    }

    return res;
}
};