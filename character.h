//
// Created by zoade on 24.09.2026.
//

#ifndef LE_MINI_COMBAT_CHARACTER_H
#define LE_MINI_COMBAT_CHARACTER_H
#include <string>

class Character {
public:
    // Constructor
    Character();

    Character(std::string nom, int pv, int attaque, int defense);

    // Methods
    void ReceiveAttack(int opp_attaque, std::string opp_name);

    // Setter and Getter functions
    std::string Nom();

    int Pv();

    int Attaque();

    bool IsDead();

private:
    // Helper Methods
    int CalculateDamageTaken(int opp_attaque);

    void TakeDamage(int damage);

    int LancerDe(int nombre);

    std::string AttackAction();

    // Members variables
    std::string nom_;
    int pv_;
    int attaque_;
    int defense_;

};


#endif // LE_MINI_COMBAT_CHARACTER_H
