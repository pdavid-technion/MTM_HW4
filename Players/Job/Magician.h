#pragma once
#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>
#include <Utilities.h>

class Magician : public Job {
public:
    Magician();
    string printJobName() const override;
    string reactToSolarEclipse( Player& player) const override;
};