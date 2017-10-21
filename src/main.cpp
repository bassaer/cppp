//
//  main.cpp
//  cppp
//
//  Created by 中山翼 on 2017/10/05.
//  Copyright © 2017年 Tsubasa Nakayama. All rights reserved.
//

#include <iostream>
#include "Car.hpp"

using namespace std;

void callCar()
{
  char name[100];
  cout << "name? \n";
  cout << "> ";
  cin >> name;
    
  Car car1(name);
  Car car2(name, 100);
  
  car1.drive();
  car2.drive();
  car1.stop();
  car2.stop();
}

int main() {
  callCar();    
}
