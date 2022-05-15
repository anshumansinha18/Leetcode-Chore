class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        int low = 0;
        int high = n1-1;
        
        if(n1>n2) return false;
        
        unordered_map<int, int> m1, m2;
        
        for(int i=0;i<n1;i++)
        {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        
        while(high<n2)
        {
            if(m1!=m2)
            {
                if(m2[s2[low]]==1) m2.erase(s2[low]);
            else m2[s2[low]]--;
                low++;
                high++;
                m2[s2[high]]++;
            }
            else
                return true;
        }
        
        return false;
    }
};