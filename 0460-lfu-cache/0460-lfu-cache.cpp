class LFUCache {
    map<int,  list<pair<int, int>>> m;
    unordered_map<int, pair<int, int>> mp;
    //first = freq,
    //second = value,
    int capacity;
    int curr_size;
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        this->curr_size=0;
    }

    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }

        int result;
        for(auto it= m[mp[key].first].begin();it!=m[mp[key].first].end();it++){
            if((*it).first==key)
                result=(*it).second;
        }

        makeMostFrequent(key, result, result);
        return result;



    }



    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){
            int result;
            for(auto it= m[mp[key].first].begin();it!=m[mp[key].first].end();it++){
                if((*it).first==key)
                    result=(*it).second;
            }

            makeMostFrequent(key, result, value);
        }else curr_size++;

        if(curr_size>capacity && !m.empty()){
            auto it = m.begin();
            int key_tobe_deleted = it->second.back().first;
            it->second.pop_back();
            if(it->second.size()==0)
                m.erase(it->first);
            mp.erase(key_tobe_deleted);
            curr_size--;
        }
        if(mp.find(key)==mp.end()) {
            m[1].push_front(make_pair(key, value));
            mp[key].first = 1;
        }

    }
    void makeMostFrequent(int key, int value, int updatedValue){
        m[mp[key].first].remove(make_pair(key, value));
        if(m[mp[key].first].size()==0) m.erase(mp[key].first);
        mp[key].first++;
        m[mp[key].first].push_front(make_pair(key, updatedValue));
    }
};
