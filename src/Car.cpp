/**
*  @file Car.cpp
*  @brief practice for cpp
*  @author 中山翼
*  @date 2017/10/06.
*  Copyright © 2017年 Tsubasa Nakayama. All rights reserved.
*/

#include "Car.hpp"
#include <iostream>

using namespace std;

Car::Car(std::string input):name(input)
{
    this->speed = 0;
}

Car::Car(std::string input, int spd): speed(spd), name(input){}

/**
 * @fn
 * drive func
 * @brief print status of car
 * @detail detail doc
 */
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


