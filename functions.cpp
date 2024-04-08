#include "heading.hpp"

float DefenseCout(int dam, int def) { // defense function
    float percent = dam - ((dam / 100) * def);
    return percent;
}

void HealPotion(Player &player) {
    if (player.NumOfPoisons > 0) {
        int Healing = 70;
        cout << "You feel a surge of health!" << endl;
        cout << "Treatment: " << Healing << endl;
        player.health += Healing;
    }
    else {
        cout << "Error! Player is death!" << endl;
    }
}

void HardcoreTotem(Player &player, Sword &sword , Crossbow &crossbow) {
    if (player.NumOfTotems > 0) {
        cout << "Hardcore totem activated" << endl;

        cout << "Health -300" << endl;
        player.health -= 300;
        cout << "Defense -5" << endl;
        player.defense -= 5;
        cout << "Crossbow arrows -all" << endl;
        crossbow.arrows = 0;
        cout << "The sword is blunted -30 damage" << endl;
        sword.damage -= 30;
        cout << "Your reward has become better!" << endl;
        player.gold += 500;
    }
    else {
        cout << "You've run out of totems!"  << endl;
    }
}