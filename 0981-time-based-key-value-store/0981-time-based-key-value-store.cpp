class TimeMap {
     unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
       
        if(m.find(key)==m.end()) return "";
        int low=0;
        int high=m[key].size()-1;
        while(low<high){
            int mid = low+(high-low)/2;
            
            if(timestamp>m[key][mid].first)
                low=mid+1;
            else
                high=mid;
        }
       
        cout<<low<<endl;
        if(m[key][low].first<=timestamp){
            return m[key][low].second;
        }
        else if(low>0)
            return m[key][low-1].second;
        else
            return "";
            
       
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */