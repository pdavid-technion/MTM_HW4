#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>
#include <Archer.h>

//TODO - SHELLY - consts

Archer::Archer(int coins = 20) : Job(coins) {}

string Archer::printJobName() const{
    return "Archer";
}