class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int i=0;
        int j=0;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> res;
        
        while(i<n1 && j<n2)
            if(nums1[i]<=nums2[j])
                res.push_back(nums1[i++]);
            else
                res.push_back(nums2[j++]);
        
        while(i<n1)
            res.push_back(nums1[i++]);
        
        while(j<n2)
            res.push_back(nums2[j++]);
        
        if(res.size()%2==0)
            return ((res[res.size()/2]+res[res.size()/2 - 1])/(double)2);
        else
            return res[res.size()/2];
    }
};