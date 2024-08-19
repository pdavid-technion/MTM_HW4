#include "Event.h"
#include "../Players/Player.h"
#include "SolarEclipse.h"
#include <string> 
#include <iostream>
 
 
 string SolarEclipse::handleEvent(Player& player){
    return player.reactToSolarEclipse();
 }

string SolarEclipse::getDescription() const{
   std::cout << " SolarEclipse::getDescription()" << std::endl;
   return "Solar Eclipse";
}