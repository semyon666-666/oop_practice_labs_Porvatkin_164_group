#include <iostream>
#include <string>
using namespace std;

class GameCharacter {
private:
    string name;
    int health;
    int maxHealth;
    int level;

public:
    GameCharacter(string n, int maxHp = 100)
        : name(n), health(maxHp), maxHealth(maxHp), level(1) {}


    string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getLevel() const { return level; }


    void takeDamage(int damage) {
        health = max(0, health - damage);
        cout << name << " poluchil uron " << damage << ". zdorovie: " << health << "/" << maxHealth << endl;

        if (health == 0) {
            cout << name << " ubit!" << endl;
        }
    }

    void heal(int amount) {
        health = min(maxHealth, health + amount);
        cout << name << " ozhil " << amount << " zdoroviya. zdorovie: " << health << "/" << maxHealth << endl;
    }

    void fullHeal() {
        health = maxHealth;
        cout << name << " polnostu iscelen!" << endl;
    }

    void levelUp() {
        level++;
        maxHealth += 20;
        health = maxHealth;
        cout << name << " povysil uroven do " << level << "! max. zdorovie: " << maxHealth << endl;
    }

    bool isAlive() const {
        return health > 0;
    }

    void displayStatus() const {
        cout << name << " ur." << level << " zdorovie: " << health << "/" << maxHealth;
        if (!isAlive()) cout << " [mertv]";
        cout << endl;
    }
};

int main() {
    GameCharacter hero("knight");

    hero.displayStatus();
    cout << endl;

    hero.takeDamage(30);
    hero.heal(10);
    hero.takeDamage(50);
    hero.fullHeal();
    cout << endl;

    hero.levelUp();
    hero.takeDamage(100);
    hero.displayStatus();

    return 0;
}
