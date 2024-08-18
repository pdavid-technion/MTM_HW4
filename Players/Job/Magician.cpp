#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>
#include <Utilities.h>

//TODO - SHELLY - consts
string Magician::reactToSolarEclipse( Player& player ) const {
     player.applyDarknessMagic();
     return getSolarEclipseMessage(player, 1);
}

string Magician::printJobName() const{
     return "Magician";
}