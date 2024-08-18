#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>

//TODO - SHELLY - consts
void Magician::reactToSolarEclipse( Player& player ) const {
     player.applyDarknessMagic();
}

string Magician::printJobName() const{
     return "Magician";
}