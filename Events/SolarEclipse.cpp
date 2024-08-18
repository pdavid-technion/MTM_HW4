#include "Event.h"
#include "../Players/Player.h"
#include "SolarEclipse.h"
#include <string> 
 
 
 string SolarEclipse::handleEvent(Player& player){
    return player.reactToSolarEclipse();
 }

string SolarEclipse::getDescription() const{
   return "Solar Eclipse";
}