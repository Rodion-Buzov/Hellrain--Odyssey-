#include "heading.hpp"

int Score = 0; // score

void AddScore() { // add score func
    string NewGameName;
    string line;

    cout << "Enter name of game (No spaces! This will cause a critical error!): " << endl;
    cin >> NewGameName;

    cout << "Attention! The file must be open, otherwise the record will not be written!" << endl;

    ofstream ScoreFile("score.txt", ios_base::app);

    if (ScoreFile.is_open()) {
        line = "Name of game: " + NewGameName + " Score: " + to_string(Score);
        ScoreFile << line;
        ScoreFile.close();
    }
    else {
        cout << "Unable to open the file for writing. Error code 1!" << endl;
    }
}

void ViewScore() { // view score func
    string line;

    ifstream readFile("score.txt");

    if (readFile.is_open()) {
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    } else {
        cout << "Unable to open the file for reading. Error code 1!" << endl;
    }
}

int main() {
    cout << "||    ||  ||====  ||     ||     ||====|   ||==||  &&  ||===    ||" << endl; // logo!
    cout << "||    ||  ||      ||     ||     ||    |   ||  ||      ||   =   ||" << endl;
    cout << "||====||  ||====  ||     ||     ||====|   ||==||  ||  ||   =   ||" << endl;
    cout << "||    ||  ||      ||     ||     ||- -     ||  ||  ||  ||   =     " << endl;
    cout << "||    ||  ||====  ||===  ||===  ||  - -   ||  ||  ||  ||   ==  @@" << endl;
    cout << endl;

    for(;;) {
        Player player; // objects of classes
        Sword sword;
        Crossbow crossbow;
        Skeleton skeleton;
        Goblin goblin;
        Mage mage;
        Dragon dragon;

        int MenuChoice; // variables for menu
        int GameChoice;
        int ItemChoice;

        cout << endl;
        cout << "(1) Start Game!" << endl;
        cout << "(2) Show Information for Game..." << endl;
        cout << "(3) Credits..." << endl;
        cout << "(4) View score" << endl;
        cout << "(5) Quit." << endl;
        cin >> MenuChoice;

        if (MenuChoice == 1) {
            system("cls");
            cout << "Start Game!" << endl;
            cout << "Good Luck!!" << endl;

            int Step = 0;

            while(player.health > 0) {
                Step++;
                cout << "Step " << Step << endl;

                srand(time(NULL)); // random generation seed
                int NumOfEnemy = 4;
                int RandNum = rand() % NumOfEnemy; // generate a number between 0 and NumOfEnemy-1

                if (RandNum == 0) {
                    cout << "Your enemy is Skeleton!"  << endl;
                    skeleton.IsEnemy = true;

                    if (skeleton.IsEnemy == true) {
                        Skeleton skeleton;

                        while(skeleton.health > 0) {
                            cout << "Enter you choice: " << endl;
                            cout << "(1) Attack with Sword" << endl;
                            cout << "(2) Attack with Crossbow" << endl;
                            cout << "(3) Use Items or go to shop" << endl;
                            cin >> GameChoice;

                            if (GameChoice == 1) {
                                sword.attack();
                                skeleton.health -= DefenseCout(sword.damage, skeleton.defense);
                                if (skeleton.health <= 0) {
                                    skeleton.death();
                                    player.gold += skeleton.gold;
                                }

                                #ifdef _WIN32
                                Sleep(3000);
                                #else
                                usleep(3000);
                                #endif
                                skeleton.attack(player);

                                cout << "Player heath: " << player.health << endl;
                                if (skeleton.health > 0) {
                                    cout << "Enemy heath: " << skeleton.health << endl;
                                }

                                if (player.health <= 0) {
                                    player.death();
                                    break;
                                }
                            }
                            else if (GameChoice == 2) {
                                crossbow.attack();
                                skeleton.health -= DefenseCout(crossbow.damage, skeleton.defense);
                                if (skeleton.health <= 0) {
                                    skeleton.death();
                                    player.gold += skeleton.gold;
                                }

                                #ifdef _WIN32
                                Sleep(3000);
                                #else
                                usleep(3000);
                                #endif
                                skeleton.attack(player);

                                cout << "Player heath: " << player.health << endl;
                                if (skeleton.health > 0) {
                                    cout << "Enemy heath: " << skeleton.health << endl;
                                }

                                if (player.health <= 0) {
                                    player.death();
                                    AddScore();
                                    break;
                                }
                            } else if (GameChoice == 3) {
                                cout << "Enter your choice: " << endl;
                                cout << "(1) Heal Potion" << endl;
                                cout << "(2) Hardcore Totem" << endl;
                                cout << "(3) Go to Shop" << endl;
                                cin >> ItemChoice;

                                if (ItemChoice == 1) {
                                    HealPotion(player);
                                } else if (ItemChoice == 2) {
                                    HardcoreTotem(player,sword,crossbow);
                                } else if (ItemChoice == 3) {
                                    srand(time(NULL)); // random generation seed
                                    int RandShopSpawn = rand() % 3;
                                    if (RandShopSpawn == 0) {
                                        cout << "You have entered the shop!" << endl;
                                        shop(player, crossbow);
                                    } else {
                                        cout << "You not need the shop!" << endl;
                                    }
                                } else {
                                    cout << "Wrong Input!" << endl;
                                }
                            } else {
                                cout << "Wrong Input!" << endl;
                            }
                        }
                    } else {
                        cout << "Error! Error code: 2" << endl;
                    }
                }
                else if (RandNum == 1) {
                    cout << "Your enemy is Goblin!" << endl;
                    goblin.IsEnemy = true;

                    if (goblin.IsEnemy == true) {
                        Goblin goblin;

                        while(goblin.health > 0) {
                            cout << "Enter you choice: " << endl;
                            cout << "(1) Attack with Sword" << endl;
                            cout << "(2) Attack with Crossbow" << endl;
                            cout << "(3) Use Items or go to shop" << endl;
                            cin >> GameChoice;

                            if (GameChoice == 1) {
                                sword.attack();
                                goblin.health -= DefenseCout(sword.damage, goblin.defense);
                                if (goblin.health <= 0) {
                                    goblin.death();
                                    player.gold += goblin.gold;
                                }

                                #ifdef _WIN32
                                Sleep(3000);
                                #else
                                usleep(3000);
                                #endif
                                goblin.attack(player);

                                cout << "Player heath: " << player.health << endl;
                                if (goblin.health > 0) {
                                    cout << "Enemy heath: " << goblin.health << endl;
                                }

                                if (player.health <= 0) {
                                    player.death();
                                    AddScore();
                                    break;
                                }
                            } else if (GameChoice == 2) {
                                crossbow.attack();
                                goblin.health -= DefenseCout(crossbow.damage, goblin.defense);
                                if (goblin.health <= 0) {
                                    goblin.death();
                                    player.gold += goblin.gold;
                                }

                                #ifdef _WIN32
                                Sleep(3000);
                                #else
                                usleep(3000);
                                #endif
                                goblin.attack(player);

                                cout << "Player heath: " << player.health << endl;
                                if (goblin.health > 0) {
                                    cout << "Enemy heath: " << goblin.health << endl;
                                }

                                if (player.health <= 0) {
                                    player.death();
                                    AddScore();
                                    break;
                                }
                            } else if (GameChoice == 3) {
                                cout << "Enter your choice: " << endl;
                                cout << "(1) Heal Potion" << endl;
                                cout << "(2) Hardcore Totem" << endl;
                                cout << "(3) Go to Shop" << endl;
                                cin >> ItemChoice;

                                if (ItemChoice == 1) {
                                    HealPotion(player);
                                } else if (ItemChoice == 2) {
                                    HardcoreTotem(player,sword,crossbow);
                                } else if (ItemChoice == 3) {
                                    srand(time(NULL)); // random generation seed
                                    int RandShopSpawn = rand() % 3;
                                    if (RandShopSpawn == 0) {
                                        cout << "You have entered the shop!" << endl;
                                        shop(player, crossbow);
                                    } else {
                                        cout << "You not need the shop!" << endl;
                                    }
                                } else {
                                    cout << "Wrong Input!" << endl;
                                }
                            } else {
                                cout << "Wrong Input!" << endl;
                            }
                        }
                    } else {
                        cout << "Error! Error code: 2" << endl;
                    }
                }
                else if (RandNum == 2) {
                    cout << "Your enemy is Mage!" << endl;
                    mage.IsEnemy = true; 

                    if (mage.IsEnemy == true) {
                        Mage mage;

                        while (mage.health > 0) {
                            cout << "Enter you choice: " << endl;
                            cout << "(1) Attack with Sword" << endl;
                            cout << "(2) Attack with Crossbow" << endl;
                            cout << "(3) Use Items or go to shop" << endl;
                            cin >> GameChoice;

                            if (GameChoice == 1) {
                                sword.attack();
                                mage.health -= DefenseCout(sword.damage, mage.defense);
                                if (mage.health <= 0) {
                                    mage.death();
                                    player.gold += mage.gold;
                                }

                                #ifdef _WIN32
                                Sleep(3000);
                                #else
                                usleep(3000);
                                #endif
                                mage.attack(player);

                                cout << "Player heath: " << player.health << endl;
                                if (mage.health > 0) {
                                    cout << "Enemy heath: " << goblin.health << endl;
                                }

                                if (player.health <= 0) {
                                    player.death();
                                    AddScore();
                                    break;
                                }
                            } else if (GameChoice == 2) {
                                crossbow.attack();
                                mage.health -= DefenseCout(crossbow.damage, mage.defense);
                                if (mage.health <= 0) {
                                    mage.death();
                                    player.gold += mage.gold;
                                }

                                #ifdef _WIN32
                                Sleep(3000);
                                #else
                                usleep(3000);
                                #endif
                                mage.attack(player);

                                cout << "Player heath: " << player.health << endl;
                                if (mage.health > 0) {
                                    cout << "Enemy heath: " << goblin.health << endl;
                                }

                                if (player.health <= 0) {
                                    player.death();
                                    AddScore();
                                    break;
                                }
                            } else if (GameChoice == 3) {
                                cout << "Enter your choice: " << endl;
                                cout << "(1) Heal Potion" << endl;
                                cout << "(2) Hardcore Totem" << endl;
                                cout << "(3) Go to Shop" << endl;
                                cin >> ItemChoice;

                                if (ItemChoice == 1) {
                                    HealPotion(player);
                                } else if (ItemChoice == 2) {
                                    HardcoreTotem(player,sword,crossbow);
                                } else if (ItemChoice == 3) {
                                    srand(time(NULL)); // random generation seed
                                    int RandShopSpawn = rand() % 3;
                                    if (RandShopSpawn == 0) {
                                        cout << "You have entered the shop!" << endl;
                                        shop(player, crossbow);
                                    } else {
                                        cout << "You not need the shop!" << endl;
                                    }
                                } else {
                                    cout << "Wrong Input!" << endl;
                                }
                            } else {
                                cout << "Wrong Input!" << endl;
                            }
                        }
                    } else {
                        cout << "Error! Error code: 2" << endl;
                    }
                }
                else if (RandNum == 3) {
                    cout << "Your enemy is Dragon! It's much stronger than other enemies." << endl;
                    dragon.IsEnemy = true;  

                    if (dragon.IsEnemy == true) {
                        Dragon dragon;

                        while (dragon.health > 0) {
                            cout << "Enter you choice: " << endl;
                            cout << "(1) Attack with Sword" << endl;
                            cout << "(2) Attack with Crossbow" << endl;
                            cout << "(3) Use Items or go to shop" << endl;
                            cin >> GameChoice;

                            if (GameChoice == 1) {
                                sword.attack();
                                dragon.health -= DefenseCout(sword.damage, dragon.defense);
                                if (dragon.health <= 0) {
                                    dragon.death();
                                    player.gold += dragon.gold;
                                }

                                #ifdef _WIN32
                                Sleep(3000);
                                #else
                                usleep(3000);
                                #endif
                                dragon.attack(player);

                                cout << "Player heath: " << player.health << endl;
                                if (dragon.health > 0) {
                                    cout << "Enemy heath: " << goblin.health << endl;
                                }

                                if (player.health <= 0) {
                                    player.death();
                                    AddScore();
                                    break;
                                }
                            } else if (GameChoice == 2) {
                                crossbow.attack();
                                dragon.health -= DefenseCout(crossbow.damage, dragon.defense);
                                if (dragon.health <= 0) {
                                    dragon.death();
                                    player.gold += dragon.gold;
                                }

                                #ifdef _WIN32
                                Sleep(3000);
                                #else
                                usleep(3000);
                                #endif
                                dragon.attack(player);

                                cout << "Player heath: " << player.health << endl;
                                if (dragon.health > 0) {
                                    cout << "Enemy heath: " << goblin.health << endl;
                                }

                                if (player.health <= 0) {
                                    player.death();
                                    AddScore();
                                    break;
                                }
                            } else if (GameChoice == 3) {
                                cout << "Enter your choice: " << endl;
                                cout << "(1) Heal Potion" << endl;
                                cout << "(2) Hardcore Totem" << endl;
                                cout << "(3) Go to Shop" << endl;
                                cin >> ItemChoice;

                                if (ItemChoice == 1) {
                                    HealPotion(player);
                                } else if (ItemChoice == 2) {
                                    HardcoreTotem(player,sword,crossbow);
                                } else if (ItemChoice == 3) {
                                    srand(time(NULL)); // random generation seed
                                    int RandShopSpawn = rand() % 3;
                                    if (RandShopSpawn == 0) {
                                        cout << "You have entered the shop!" << endl;
                                        shop(player, crossbow);
                                    } else {
                                        cout << "You not need the shop!" << endl;
                                    }
                                } else {
                                    cout << "Wrong Input!" << endl;
                                }
                            } else {
                                cout << "Wrong Input!" << endl;
                            }  
                        }
                    } else {
                        cout << "Error! Error code: 2" << endl;
                    }
                }
                else {
                    cout  << "Error! Error code: 1" << endl;   
                }
            }
        }
        else if (MenuChoice == 2) {
            cout << "Game Information:" << endl;
            cout << "Enemies: " << endl;
            cout << skeleton.name << endl;
            cout << goblin.name << endl;
            cout << mage.name << endl;
            cout << dragon.name << endl;
            cout << "Weapons: " << endl;
            cout << "Sword, " << sword.damage << " damage." << endl;
            cout << "Crossbow, " << crossbow.damage << " damage." << endl;
            system("pause");
        }
        else if (MenuChoice == 3) {
            cout << "created by Rodion Buzov (*_*)" << endl;
        } 
        else if (MenuChoice == 4) {
            ViewScore();
            system("pause");
        }
        else if (MenuChoice == 5) {
            cout << "Goodbye!" << endl;
            system("pause");
            break;
        }
        else {
            cout << "Wrong Input!" << endl;
        }
    }
    return 0;
}