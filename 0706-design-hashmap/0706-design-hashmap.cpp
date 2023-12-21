class MyHashMap {
public:
    vector<list<pair<int, int>>> hash;
    MyHashMap() {
       hash = vector<list<pair<int, int>>>(11000);
       
    }
    
    int getHash(int key){
       return key%11000;  
    }
    void put(int key, int value) {
        int index = getHash(key);
        
         list<pair<int, int>>& bucket = hash[index];
         for(auto itr = bucket.begin();itr!=bucket.end();itr++){
            if(itr->first==key){
              bucket.erase(itr);
              break;
            }
        }
        bucket.push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int index = getHash(key);
        list<pair<int, int>>& bucket = hash[index];
        for(auto itr = bucket.begin();itr!=bucket.end();itr++){
            // cout<<itr->first<<" ";
            if(itr->first==key){
                return itr->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
          int index = getHash(key);
          list<pair<int, int>>& bucket = hash[index];
         auto itr=bucket.begin();
          for(itr = bucket.begin();itr!=bucket.end();itr++){
            if(itr->first==key){
               // bucket.erase(make_pair(itr->first, itr->second));
                break;
             }
          }
        if(itr!=bucket.end()) bucket.erase(itr);
          
        
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */