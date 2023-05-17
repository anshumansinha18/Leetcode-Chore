class Solution {
public:
    
    bool isBalloon(char c)
    {
        if(c=='b' || c=='a' || c=='l' || c=='o' || c=='n')
            return true;
        return false;
    }   
    
    int maxNumberOfBalloons(string text) {
        
        int n = text.size();
        unordered_map<char, int> m;
        m['b']=0;
        m['a']=0;
        m['l']=0;
        m['o']=0;
        m['n']=0;
        for(int i=0;i<n;i++){
            if(isBalloon(text[i])){
                m[text[i]]++;
            }
        }
       
        int res=INT_MAX;
        
        m['l']/=2;
        m['o']/=2;
        
        for(auto& it: m){
            if(res>it.second)
                res = it.second;
        }
        
        return res;
        
    }
};