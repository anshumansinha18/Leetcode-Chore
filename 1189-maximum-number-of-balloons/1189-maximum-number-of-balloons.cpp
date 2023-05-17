class Solution {
public:
    
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char, int> m;
        
        for(int i=0;i<text.size();i++)
            m[text[i]]++;
        
        return min(m['b'], min(m['a'], min(m['l']/2, min(m['o']/2, m['n']))));
        
        
    }
};