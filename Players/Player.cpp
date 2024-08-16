#include<Player.h>

string Player::getDescription() const{return NULL;} //DAVID

    /**
     * Gets the name of the player
     *
     * @return - name of the player
     */
    string Player::getName() const{
        return name;
    } 

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
     */
    int Player::getLevel() const{
        return level;
    }

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
     */
    int Player::getForce() const{
        return force;
    }

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
     */
    int Player::getHealthPoints() const{
        return healthPoints;
    }

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
     */
    int Player::getCoins() const{
        return coins;
    }