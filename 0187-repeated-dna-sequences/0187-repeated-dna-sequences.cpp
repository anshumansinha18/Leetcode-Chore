class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {

    unordered_map<string, int> m;

    int j=-1, n=s.size();
    string res="";
    while(j<n){
        if(res.size()<10){
            j++;
            res+=s[j];
        }else{
            m[res]++;
            string newRes="";
            for(int k=1;k<res.size();k++){
                newRes+=res[k];
            }
            res=newRes;
        }
    }

    vector<string> result;
    for(auto it: m){
        if(it.second>1)
            result.push_back(it.first);
    }
    return result;
}
};