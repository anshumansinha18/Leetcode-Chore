class ParkingSystem {
    int *parking;
public:
    ParkingSystem(int big, int medium, int small) {
        parking = new int[4];
        parking[1]=big;
        parking[2]=medium;
        parking[3]=small;
    }
    
    bool addCar(int carType) {
        if(parking[carType]==0)
            return false;
        else{
            parking[carType]--;
            return true;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */