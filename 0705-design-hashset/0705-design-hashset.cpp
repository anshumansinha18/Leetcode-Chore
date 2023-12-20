class MyHashSet {
    
    public:
    vector<int> arr;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key)) arr.push_back(key);
    }
    
    void remove(int key) {
        if(contains(key)){
            for(int i=0;i<arr.size();i++){
                if(key==arr[i]){
                    swap(arr[i], arr[arr.size()-1]);
                    break;
                }
            }
            arr.pop_back();
        }
    }
    
    bool contains(int key) {
        for(int i=0;i<arr.size();i++){
            if(key==arr[i]) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */