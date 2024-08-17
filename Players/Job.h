class Job {
public:

    virtual ~Job() = default;
    virtual string printJobName() const = 0;
    virtual int calculateCombatPower(int force, int level) const {
        return force + level;
    }
};

class Warrior : public Job {
    public:
        int calculateCombatPower(int force, int level) const override{
            return force * 2 + level;
        }
        string printJobName() const override{
        return "Warrior";
    }
};

class Archer : public Job {
    string printJobName() const override{
        return "Archer";
    }
};

class Magician : public Job {
    string printJobName() const override{
        return "Magician";
    }
};
