//
//  Car.hpp
//  cppp
//
//  Created by 中山翼 on 2017/10/06.
//  Copyright © 2017年 Tsubasa Nakayama. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include <string>

class Car
{
    std::string name;
    int speed;
public:
    Car(std::string input);
    Car(std::string input, int spd);
    void drive();
    void stop();
    int getSpeed() { return speed;}
};
#endif /* Car_hpp */
