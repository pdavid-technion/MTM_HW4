#pragma once

// Default values
constexpr int DEFAULT_HEALTH_POINTS = 100;
constexpr int DEFAULT_COINS = 10;
constexpr int DEFAULT_LEVEL = 1;
constexpr int DEFAULT_FORCE = 5;

// Monster values
constexpr int SNAIL_COMBAT_POWER = 5;
constexpr int SNAIL_LOOT = 2;
constexpr int SNAIL_DAMAGE = 10;

constexpr int SLIME_COMBAT_POWER = 12;
constexpr int SLIME_LOOT = 5;
constexpr int SLIME_DAMAGE = 25;

constexpr int BALROG_COMBAT_POWER = 15;
constexpr int BALROG_LOOT = 100;
constexpr int BALROG_DAMAGE = 9001;
constexpr int BALROG_COMBAT_REACTION = 2;

// Potion Merchant costs, thresholds, etc.
constexpr int POTION_COST = 5;
constexpr int POTION_HEALTHPOINTS = 10;
constexpr int LOW_HEALTH_THRESHOLD = 50;

//Solar eclipse values
constexpr int SOLAR_ECLIPSE_EXPOSURE = 1;

//Job Values
constexpr int CLOSE_ENCOUNTER_DAMAGE = 10;
constexpr int WARRIOR_MAX_HEALTHPOINTS = 150;
constexpr int WARRIOR_FORCE_FACTOR = 2;
constexpr int RISK_TAKING_POTION = 1;
constexpr int ARCHER_COINS = 20;

constexpr const char* WARRIOR = "Warrior";
constexpr const char* ARCHER = "Archer";
constexpr const char* MAGICIAN = "Magician";
constexpr const char* RESPONSIBLE = "Responsible";
constexpr const char* RISK_TAKING = "RiskTaking";

//Victory values
constexpr int WINNER_LEVEL = 10;

//Events
constexpr const char* SNAIL = "Snail";
constexpr const char* SLIME = "Slime";
constexpr const char* BALROG = "Balrog";
constexpr const char* PACK = "Pack";
constexpr const char* SOLAR_ECLIPSE = "SolarEclipse";
constexpr const char* POTIONS_MERCHANT = "PotionsMerchant";

constexpr const char* PLAYER_FILE_ERROR = "Invalid Players File";
constexpr const char* EVENT_FILE_ERROR = "Invalid Event File";
