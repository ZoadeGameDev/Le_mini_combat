//
// Created by zoade on 24.09.2026.
//
#include <random>
#include <print>
#include <string>
#include "character.h"

// Public
// Constructor
Character::Character()
    : nom_("Combattant"), pv_(10), attaque_(10), defense_(10) {}

Character::Character(std::string nom, int pv, int attaque, int defense)
    : nom_(nom), pv_(pv), attaque_(attaque), defense_(defense) {}

// Methods

void Character::ReceiveAttack(int opp_attaque, std::string opp_name) {
    int damage_modifier = 1;
    if (AttackAction() == "manque") {
        std::println("{} a loupe son attaque...", opp_name);
        return;
    }
    else if (AttackAction() == "normal") {
        damage_modifier = 1;
    }
    else {
        std::println("- {} a fait un coup critique! -", opp_name);
        damage_modifier = 2;
    }
    int total_damage = CalculateDamageTaken(opp_attaque) * damage_modifier;
    TakeDamage(total_damage);
    std::println("{} frappe {}: {} degats -> {} : {} PV", opp_name, nom_, total_damage, nom_, pv_);



}


// Setter Getter functions
std::string Character::Nom() {
    return nom_;
}

int Character::Pv() {
    return pv_;
}

int Character::Attaque() {
    return attaque_;
}

bool Character::IsDead() {
    if (pv_ <= 0) {
        return true;
    } else {
        return false;
    }
}
// Private
int Character::CalculateDamageTaken(int opp_attaque) {
    return opp_attaque + LancerDe(6) - defense_;
}

void Character::TakeDamage(int damage) {
    pv_ -= damage;

    if (pv_ <= 0) {
        pv_ = 0;
    }
}

int Character::LancerDe(int nombre) {
    return rand() % nombre + 1;
}

// Warning: I didn't know how to use "continue" in a loop to make BOTH the orc and troll play so I didn't include it.
// I used this as a whole method instead, using a switch statement like asked even though a if condition would have been shorter.
std::string Character::AttackAction() {
    int de = LancerDe(10);
    switch (de) {
        case 1:
            return "manque";
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return "normal";
            break;
        case 10:
            return "critique";
            break;
    }
    /*if (de == 1){
        return "manque";
    } else if ( de <= 9) {
        return "normal";
    } else {
        return "critique";
    }*/
}