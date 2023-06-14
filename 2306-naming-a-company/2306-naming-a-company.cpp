class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        vector<unordered_map<string, int>> vec(26);
        
        
        for(int i=0;i<ideas.size();i++)
            vec[ideas[i][0]-97][ideas[i].substr(1)]++;

        long long count=0;
        
        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
               long long x=0;
                
                for(auto &it: vec[i]){
                    if(vec[j].find(it.first)!=vec[j].end())
                       x++;
                }
                count+=2*(vec[i].size()-x)*(vec[j].size()-x);
            }
            
            
        }
        
        return count;
    }
};