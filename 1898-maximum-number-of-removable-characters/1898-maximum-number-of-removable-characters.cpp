class Solution {
public:
    int x;
    
    bool checkSubseq(string s, string p){
        if(s.size()<p.size()) return false;
        int i=0;
        int j=0;
        
        while(i<p.size() && j<s.size()){
            if(p[i]==s[j])
                i++;
            j++;
        }
        
        return i==p.size();
    }
    
    bool check(string s, string p, vector<int>& removable, int k){
    
        for(int i=0;i<k;i++)
            s[removable[i]]='.';
        
        //generate string:
        string newStr="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='.')
                newStr+=s[i];
        }
        return checkSubseq(newStr, p);
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        
        int low=0;
        int high=removable.size();
        
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(s, p, removable, mid)){
                low=mid+1;
            }else
                high=mid;
        }
        return check(s, p, removable, low)?low:low-1;
    }
};