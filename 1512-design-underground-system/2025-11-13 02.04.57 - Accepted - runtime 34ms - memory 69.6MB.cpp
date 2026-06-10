class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> custIn;
    unordered_map<string, pair<int,int>> storedTime;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        custIn[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto node = custIn[id];
        storedTime[node.first+"-"+stationName].first += (t-node.second);
        storedTime[node.first+"-"+stationName].second++;
        custIn.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto node = storedTime[startStation+"-"+endStation];
        return double(node.first)/node.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */