class UndergroundSystem {
    
    unordered_map<int, pair<string, int>> checkedIn;
    map<pair<string, string>, vector<double>> average;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
  
            checkedIn[id] = make_pair(stationName, t);
        
    }
    
    void checkOut(int id, string stationName, int t) {
        
        
        // string totalName= checkedIn[id].first + stationName;
        // if(checkedIn.find(id)==checkedIn.end()) return;
        pair<string, string> p = make_pair(checkedIn[id].first, stationName);
        if(average.find(p)==average.end()){
            vector<double> vec = {1.0, t-(double)checkedIn[id].second};
            average[p] = vec;
        }else{
            average[p][1] *= average[p][0];
            average[p][0]++;
            average[p][1] += (t-checkedIn[id].second);
            average[p][1] /= average[p][0];
        }
        // checkedIn.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> p = make_pair(startStation, endStation);
        return average[p][1];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */