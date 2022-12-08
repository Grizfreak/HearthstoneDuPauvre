#include <string>
#include <vector>
#include <iostream>

#include "Minion.h"

Minion::Minion(std::string name, int attack, int costMana, int defense, Status status, TypeOfMonster type) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = status;
	this->type = type;
}

Minion::Minion(std::string name, int attack, int costMana, int defense, Status status) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = status;
	this->type = TypeOfMonster::HUMAN;
}

Minion::Minion(std::string name, int attack, int costMana, int defense) : Card(name, attack, costMana) {
	this->defense = defense;
	this->status = Status::DEFAULT;
	this->type = TypeOfMonster::HUMAN;
}

Minion::Minion(std::string name, int attack, int costMana, int defense, TypeOfMonster type) : Card(name, attack, costMana) {
	this->defense = defense;
	this->type = type;
	this->status = Status::DEFAULT;
}

void Minion::useOn(Card* card)
{
	std::cout << "UseOn sur une seule carte";
	return;
}

void Minion::useOn(std::vector<Card*> listOfCards)
{
	std::cout << "UseOn sur plusieurs cartes";
	return;
}

Minion::~Minion() {

}