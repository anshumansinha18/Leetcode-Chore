class Solution {
public:
    
    bool check(vector<int>& v, int k){
        int max=0;
        int sum=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>max)
                max=v[i];
            sum+=v[i];
        }
        return (sum-max)<=k;
    }
    int characterReplacement(string s, int k) {
        
        vector<int> v(26, 0);
        int max_len=0;
        int j=0;
        int n= s.size();
        for(int i=0;i<n;i++){
            v[s[i]-'A']++;
            
            if(check(v, k))
                max_len=max(max_len, i-j+1);
            else{
                v[s[j]-'A']--;
                j++;
            }
        }
        
        return max_len;
    }
};