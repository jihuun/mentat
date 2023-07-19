class ParkingSystem {
public:
    int nr_park[4];
    ParkingSystem(int big, int medium, int small) {
        nr_park[1] = big;
        nr_park[2] = medium;
        nr_park[3] = small;
    }
    
    bool addCar(int carType) {
        if (nr_park[carType] > 0) {
            nr_park[carType]--;
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