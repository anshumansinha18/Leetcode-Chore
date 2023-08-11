class UndergroundSystem {
    unordered_map<int, pair<string, int>> m1;
    map<string, map<string, pair<int, double>>> m2;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m1[id].first = stationName;
        m1[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
    
        double diff = t-m1[id].second;
       
        double prevAvg = m2[m1[id].first][stationName].second;
        int prevCount= m2[m1[id].first][stationName].first;
        m2[m1[id].first][stationName].first++;
        double newAvg = (prevAvg*prevCount + diff)/(m2[m1[id].first][stationName].first);
        m2[m1[id].first][stationName].second =newAvg;

    }
    
    double getAverageTime(string startStation, string endStation) {
        return m2[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */