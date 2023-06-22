class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int, int> m;
        
        int i=0, j=0;
        int max_l = 0;
        int n = fruits.size();
        while(j<n){
            
            m[fruits[j]]++;
            
            if(m.size()>2){
                 
                m[fruits[i]]--;
                if(m[fruits[i]]==0)
                    m.erase(fruits[i]);
                i++;
                m[fruits[j]]--;
            }else
                j++;
             max_l = max(max_l, j-i);
          
        }
        
        return max_l;
    }
};