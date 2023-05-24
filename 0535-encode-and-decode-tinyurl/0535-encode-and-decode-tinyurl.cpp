class Solution {

    private:
       unordered_map<char, string> m;
       string fixedUrl = "http://tinyurl.com/";
public:
     int randomIndex(){
         int randIndex = rand() % 3;
         return randIndex;
     }
     string randomString(){
         vector<pair<int, int>> v;

         v.push_back(make_pair(48, 57));
         v.push_back(make_pair(65, 90));
         v.push_back(make_pair(97, 122));


         set<char> s;

         while(s.size()<6){
             int x = randomIndex();
             int lb = v[x].first;
             int ub = v[x].second;
             char randChar = (char)(rand()%(ub-lb+1) + lb);
             s.insert(randChar);
         }
         string randString = "";
         for(auto it: s)
             randString+=it;
         return randString;
     }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

         int n = longUrl.size();
         string res="";
         string shortUrl = randomString();
         int j=0;

         for(int i=0;i<n;i++){
             res+=longUrl[i];

             if(i%6==5 && j<shortUrl.size()) {
                 m[shortUrl[j++]] = res;
                 res = "";
             }
         }
         m[shortUrl[--j]]+=res;

        return fixedUrl+shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

        int n = shortUrl.size();
        string res = "";
        for(int i=fixedUrl.size();i<n;i++){
            res+=m[shortUrl[i]];
        }

        return res;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));