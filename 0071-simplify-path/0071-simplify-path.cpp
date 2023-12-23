class Solution {
public:
    string simplifyPath(string path) {
        path+='/';
        int n = path.size();
        
        vector<string> result;
        string temp="";
        vector<string> vec;
        
        for(int i=0;i<n;i++){
            
            if(path[i]=='/'){
                if(temp!=""){
                    if(temp==".."){
                        if(vec.size()!=0) vec.pop_back();
                     }else if(temp=="."){
                        temp="";
                        continue;
                    }else vec.push_back(temp);
                    temp="";
                }
            }else{
                temp+=path[i];
            }
        }
        
        string res="/";
        for(int i=0;i<vec.size();i++){
            res+=(vec[i]);
            if(i!=vec.size()-1) res+='/';
        }
       
        return res;
    }
};