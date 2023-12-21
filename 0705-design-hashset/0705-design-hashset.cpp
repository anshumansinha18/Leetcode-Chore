class MyHashSet {
public:
    vector<list<int>> vec;
    
    
    MyHashSet() {
        vector<list<int>> x(11000);
        vec=x;
        
    }
    
    int getHash(int key){
        return key%10000;
    }
    void add(int key) {
        int index = getHash(key);
        
        if(!contains(key)){
            vec[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getHash(key);
        
        auto itr = find(vec[index].begin(), vec[index].end(), key);
        
        if(itr!=vec[index].end()) vec[index].erase(itr);
        
    }
    
    bool contains(int key) {
        int index = getHash(key);
        auto itr = find(vec[index].begin(), vec[index].end(), key);
        return itr!=vec[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */