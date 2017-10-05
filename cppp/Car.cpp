//
//  Car.cpp
//  cppp
//
//  Created by 中山翼 on 2017/10/06.
//  Copyright © 2017年 Tsubasa Nakayama. All rights reserved.
//

#include "Car.hpp"
#include <iostream>

using namespace std;

Car::Car(char *input)
{
    speed = 0;
    strcpy(name, input);
}

Car::Car(char *input, int spd)
{
    speed = spd;
    strcpy(name, input);
}

void Car::drive()
{

    if (speed == 0)
    {
        speed = 10;
    }
    
    cout << name << "[running] speed ->" << speed <<"\n" << endl;
    
}

void Car::stop()
{
    cout << name << "[stopping]" << endl;
    speed = 0;
}


