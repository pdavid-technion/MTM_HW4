#include "Event.h"
#include "../Players/Player.h"
#include "SolarEclipse.h"
#include <string> 
#include <iostream>
#include "../Players/PlayerConsts.h"
 
 
 string SolarEclipse::handleEvent(Player& player){
    return player.reactToSolarEclipse();
 }

string SolarEclipse::getDescription() const{
   return SOLAR_ECLIPSE;
}