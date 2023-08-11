class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        vector<map<string, int>> vec(26);
        
        for(int i=0;i<ideas.size();i++){
            string s="";
            for(int j=1;j<ideas[i].size();j++)
                s+=ideas[i][j];
            
            vec[ideas[i][0]-'a'][s]++;
        }
        
        // for(int i=0;i<26;i++){
        //     cout<<char(i+'a')<<" ";
        //     for(auto it: vec[i])
        //         cout<<it.first<<" ";
        //     cout<<endl;
        // }
        long long answer=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                if(vec[i].size() && vec[j].size()){
                  int count=0;
                 for(auto it: vec[i]){
                    if(vec[j].find(it.first)!=vec[j].end()) count++;
                 }
                answer += 2*(vec[i].size()-count)*(vec[j].size()-count);
                }
            }
        }
        return answer;
    }
};