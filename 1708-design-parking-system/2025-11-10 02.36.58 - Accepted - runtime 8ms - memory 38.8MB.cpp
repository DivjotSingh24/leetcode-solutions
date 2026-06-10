class ParkingSystem {
public:
    int one;
    int two;
    int three;
    ParkingSystem(int big, int medium, int small) {
        one = big;
        two = medium;
        three = small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && one>0){
            one--;
            return true;
        }
        else if(carType==2 && two>0){
            two--;
            return true;
        }
        else if(carType==3 && three>0){
            three--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */