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
        vector<int> vec(5);
        
        m['b']=0;
        m['a']=1;
        m['l']=2;
        m['o']=3;
        m['n']=4;
        
        for(int i=0;i<n;i++){
            if(isBalloon(text[i])){
                vec[m[text[i]]]++;
            }
        }
       
        int res=INT_MAX;
         vec[2]/=2;
        vec[3]/=2;
        
        for(int i=0;i<5;i++){
            if(res>vec[i])
                res=vec[i];
        }
        
        return res;
        
    }
};