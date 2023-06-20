class Solution {
public:
    
    bool check(vector<int> v1, vector<int> v2){
        for(int i=0;i<26;i++){
            if(v1[i]>v2[i])
                return false;
        }
        
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1>n2) return false;
        
        vector<int> v1(26);
        vector<int> v2(26);
        int j=0;
        for(int i=0;i<n1;i++){
            v1[s1[i]-'a']++;
        }
        
        bool res = false;
       for(int i=0;i<n2;i++){
           
           v2[s2[i]-'a']++;
           
           if(i-j+1>n1){
               v2[s2[j]-'a']--;
               j++;
           }
           
           if(check(v1, v2)) res=true;
       }
        
        return res;
    }
};