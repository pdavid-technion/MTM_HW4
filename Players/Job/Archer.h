#pragma once
#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>
#include <Utilities.h>

class Archer : public Job {
public:
    Archer(int coins = 20);
    string printJobName() const override;
};