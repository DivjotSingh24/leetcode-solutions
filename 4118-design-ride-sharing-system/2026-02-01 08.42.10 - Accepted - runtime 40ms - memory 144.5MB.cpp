class RideSharingSystem {
    queue<int> driverq;
    queue<int> riderq;
    unordered_set<int> activer;
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riderq.push(riderId);
        activer.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driverq.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!riderq.empty() && activer.find(riderq.front()) == activer.end()){
            riderq.pop();
        }
        if(driverq.empty() || riderq.empty()){
            return {-1,-1};
        }
        int driverId=driverq.front();
        int riderId=riderq.front();
        driverq.pop();
        riderq.pop();
        activer.erase(riderId);
        return {driverId, riderId};
    }
    
    void cancelRider(int riderId) {
        activer.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */