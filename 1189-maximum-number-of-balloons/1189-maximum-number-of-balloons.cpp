class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        int n = text.size();
        for(int i=0;i<n;i++){
            if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n'){
                m[text[i]]++;
            }
        }
        
        return min(m['b'], min(m['a'], min(m['n'], min(m['l']/2, m['o']/2))));
        
        
        
    }
};