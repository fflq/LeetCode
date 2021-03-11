/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
public:
    int ct[4] ;
    ParkingSystem(int big, int medium, int small) {
        ct[1] = big, ct[2] = medium, ct[3] = small ;
    }
    
    bool addCar(int carType) {
        if (!ct[carType])   return false ;
        -- ct[carType] ;
        return true ;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

