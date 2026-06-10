class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> vec;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.count(val)){
            vec.push_back(val);
            mp[val] = vec.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            mp[vec[vec.size()-1]] = mp[val];
            swap(vec[mp[val]],vec[vec.size()-1]);
            vec.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */