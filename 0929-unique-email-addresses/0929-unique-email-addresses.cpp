class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        
        int n = emails.size();
        
        set<string> s;
        for(int i=0;i<n;i++){
            string res="";
           int j=0;
            
           //before +
            while(emails[i][j]!='+' && emails[i][j]!='@'){
                if(emails[i][j]!='.')
                    res+= emails[i][j];
                j++;
            }
            
            //from + to @
            while(emails[i][j]!='@')
                j++;
            
            //from @ to end
            while(j<emails[i].size())
               res+=emails[i][j++];
            
            s.insert(res);
        }
        
        
        
        return s.size();
    }
};