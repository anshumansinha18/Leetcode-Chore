class LRUCache {
public:
    map<int,  list<pair<int, int>>::iterator> m;
    list<pair<int,int>> dll;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end()){
            //if key doesnot exist
            return -1;
        }else{
            //if key exists
            int x = m[key]->second;
            auto it=m[key];
            dll.erase(it);
            dll.push_front(make_pair(key, x));
            m[key]=dll.begin();
            return x;
        }
        
    }
    
    void put(int key, int value) {
        //check if already exists in the map or not:
        if(m.find(key)==m.end()){
            //key doesnot exists
            
            if(m.size()==cap){
                //if cache is full already
                auto it = prev(dll.end());
                int k = it->first;
                dll.erase(it);
                m.erase(k);
                dll.push_front(make_pair(key, value));
                m[key]=dll.begin();
            }else{
                //cache is not full
                dll.push_front(make_pair(key, value));
                m[key]=dll.begin();
            }
        }else{
            //key exists
            auto it = m[key];
            dll.erase(it);
            dll.push_front(make_pair(key, value));
            m[key]=dll.begin();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */