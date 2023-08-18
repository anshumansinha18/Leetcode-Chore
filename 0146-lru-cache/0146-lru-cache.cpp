class LRUCache {
    unordered_map<int, pair<list<int>::iterator, int>> m;
    list<int> dll;
    int size;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->size=0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        
        int result = m[key].second;
        dll.erase(m[key].first);
        dll.push_front(key);
        m[key].first = dll.begin();
        return result;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end()){
            dll.erase(m[key].first);
            dll.push_front(key);
            m[key].first = dll.begin();
            m[key].second=value;
            return;
        }
        
        dll.push_front(key);
        m[key].first=dll.begin();
        m[key].second=value;
        size++;
        
        if(size>capacity){
            list<int>:: iterator it = dll.end();
            it--;
            m.erase(*it);
            dll.erase(it);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */