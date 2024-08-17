#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>

void Magician::reactToSolarEclipse( Player& player ) const {
     player.applyDarknessMagic();
}