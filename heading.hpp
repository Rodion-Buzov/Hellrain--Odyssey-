#pragma once

#include <iostream>
#include <string>
#include <random>
#include <time.h> 
#include <cstdlib>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

float DefenseCout(int dam, int def);

class Player {
public:
    int health = 1000;
    int defense = 15;

    int NumOfPoisons = 1;
    int NumOfTotems = 1;

    int gold = 0;

    void death() {
        cout << "You have died." << endl; // death func
        cout << "You won!" << endl;
    }
};

class Monster { // Abstract  class for all monsters
public:
    virtual void attack(Player& player) = 0; // attack player method
    virtual void death() = 0; // death 
};

class Skeleton : public Monster { // skeleton 
public:
    int health = 50; // heath, damage, name
    int damage = 20;
    int defense = 8;
    const string name = "Skeleton";
    bool IsEnemy = false;
    int gold = 20;

    void attack(Player &player) override { // attack
        cout << "Skeleton has been attacked hero!" << endl;
        player.health -= DefenseCout(damage, player.defense);
    }
    
    void death() override { // death method
        cout << "You killed the skeleton!" << endl; 
    }
};

class Goblin : public Monster { // goblin 
public:
    int health = 100; // health, damage, name
    int damage = 50;
    int defense = 12;
    const string name = "Goblin";
    bool IsEnemy = false;
    int gold = 40;

    void attack(Player &player) override { // attack
        cout << "Goblin has been attacked hero!" << endl;
        player.health -= DefenseCout(damage, player.defense);
    }
    
    void death() override { // death method
        cout << "You killed the Goblin!" << endl; 
    }
};

class Mage : public Monster { // mage
public:
    int health = 50; // health, damage, name
    int damage = 75;
    int defense = 2;
    const string name = "Mage";
    bool IsEnemy = false;
    int gold = 50;

    void attack(Player &player) override { // attack
        cout << "Mage has been attacked hero!" << endl;
        player.health -= DefenseCout(damage, player.defense);
    }
    
    void death() override { // death method
        cout << "You killed the Mage!" << endl; 
    }
};

class Dragon : public Monster { // Boss! 
public:
    int health = 800;  // dragon is very strong
    int damage = 120;
    int defense = 18;  
    const string name = "Dragon";
    bool IsEnemy = false;
    int gold = 200;

    void attack(Player &player) override { // attack
        cout << "Dragon has been attacked hero!" << endl;
        player.health -= DefenseCout(damage, player.defense);
    }
    
    void death() override { // death method
        cout << "You killed the Dragon!" << endl; 
    }
};

class Weapon {
public:
    virtual void attack() = 0; //  pure virtual function, must be implemented in derived class
};

class Sword : public Weapon {
public:
    int damage = 60;

    void attack() override {
        cout << "The sword deals " << damage << " points of damage." << endl;
    }
};

class Crossbow : public Weapon {
public:
    int damage = 100;
    int arrows = 20;
    
    void attack() override {
        if (arrows > 0) {
            cout << "Arrows: " << arrows << endl;
            cout << "The crossbow fires an arrow which deals " << damage << " points of damage." << endl;
            cout << "Arrows remaining: " << --arrows << endl;
        }
    }
};

void HealPotion(Player &player);
void HardcoreTotem(Player &player, Sword &sword , Crossbow &crossbow);
void shop(Player &player, Crossbow &crossbow);