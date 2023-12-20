class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        int n = emails.size();
        set<string> s;
        
        for(int i=0;i<n;i++){
            
            int j=0;
            string str="";
            int size=emails[i].size();
            
            while(j<size && emails[i][j]!='+' && emails[i][j]!='@'){
                if(emails[i][j]!='.') str+=emails[i][j];
                j++;
             }
            
            while(j<size && emails[i][j]!='@') j++;
            
            while(j<size){
                str+=emails[i][j];
                j++;
            }
            // cout<<str<<endl;
          s.insert(str);
        }
          return s.size();
    }
        
      
};