class BrowserHistory {
public:
    list<string> li;
    list<string>::iterator it;
    BrowserHistory(string homepage) {
        li.push_back(homepage);
        it = li.begin();
    }
    
    void visit(string url) {
        auto nextIt = next(it);
        li.erase(nextIt,li.end());
        li.push_back(url);
        it = li.end();
        it--;
    }
    
    string back(int steps) {
        while(steps>0 && it!=li.begin()){
            steps--;
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
         while(steps>0 && next(it)!=li.end()){
            steps--;
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */