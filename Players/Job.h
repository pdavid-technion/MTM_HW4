class Job {
public:

    virtual ~Job() = default;
    virtual int calculateCombatPower(int force, int level) const {
        return force + level;
    }
};

class Warrior : public Job {
    public:
        int calculateCombatPower(int force, int level) const override{
            return force * 2 + level;
        }
};

class Archer : public Job {
};

class Magician : public Job {
};
