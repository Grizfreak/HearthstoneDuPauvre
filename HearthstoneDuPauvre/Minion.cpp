#include <string>
#include <vector>
#include <iostream>

#include "Minion.h"

/* Constructors */
Minion::Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, Status status) : Card(name, attack, costMana, imagePath) {
	this->defense = defense;
	this->status = status;
	this->effects = std::vector<Effect*>();
	this->defenseText = sf::Text(std::to_string(this->defense), this->font, 40);
	this->defenseText.setFillColor(sf::Color::Green);
	this->textRectangles.push_back(this->defenseText);
	if (this->status == Status::RUSH_STATUS) {
		this->setCanAttack(true);
	}
}

Minion::Minion(std::string name, int attack, int costMana, std::string imagePath, int defense) : Card(name, attack, costMana, imagePath) {
	this->defense = defense;
	this->status = Status::DEFAULT_STATUS;
	this->effects = std::vector<Effect*>();
	this->defenseText = sf::Text(std::to_string(this->defense), this->font, 40);
	this->defenseText.setFillColor(sf::Color::Green);
	this->textRectangles.push_back(this->defenseText);
}

Minion::Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, Status status, std::vector<Effect*> effects)
	: Card(name, attack, costMana, imagePath) {
	this->defense = defense;
	this->status = status;
	this->effects = effects;
	this->defenseText = sf::Text(std::to_string(this->defense), this->font, 40);
	this->defenseText.setFillColor(sf::Color::Green);
	this->textRectangles.push_back(this->defenseText);
	if (this->status == Status::RUSH_STATUS) {
		this->setCanAttack(true);
	}
}

Minion::Minion(std::string name, int attack, int costMana, std::string imagePath, int defense, std::vector<Effect*> effects)
	: Card(name, attack, costMana, imagePath) {
	this->defense = defense;
	this->status = Status::DEFAULT_STATUS;
	this->effects = effects;
	this->defenseText = sf::Text(std::to_string(this->defense), this->font, 40);
	this->defenseText.setFillColor(sf::Color::Green);
	this->textRectangles.push_back(this->defenseText);
}

/* Methods */
void Minion::useOn(Card* card)
{
	/* If the card can attack */
	if (this->getCanAttack() == true) {
		/* Cast the card into a minion so it can access it's following attributes */
		Minion* minionToAttack = dynamic_cast<Minion*>(card);

		/* Console Input */
		std::cout << "Minion " << this->getName() << " attacks " << minionToAttack->getName() + "\n";
		std::cout << "Minion " << minionToAttack->getName() << " attacks " << this->getName() + "\n";

		/* Each minion lose like by attacking each other */
		minionToAttack->loseLife(this->getAttack());
		this->loseLife(minionToAttack->getAttack());

		/* The card can't attack several times */
		this->setCanAttack(false);
	}
	else {
		std::cout << "The card can't attack on this turn";
	}
}

void Minion::useOn(std::vector<Card*> listOfCards)
{
	std::cout << "Un minion ne peut pas attaquer plusieurs cibles en meme temps";
	return;
}

std::string Minion::statusToString(Status status) const
{
	switch (status)
	{
		case Status::DEFAULT_STATUS:
			return "DEFAULT";
		case Status::PROVOCATION_STATUS:
			return "PROVOCATION";
		case Status::DIVINE_SHIELD_STATUS:
			return "DIVINE_SHIELD";
		case Status::RUSH_STATUS:
			return "RUSH";
		default:
			return "DEFAULT";
	}
}

void Minion::refreshTextDatas() {
	this->defenseText.setString(std::to_string(this->defense));
	Card::refreshTextDatas();
}

std::vector<sf::Vector2f> Minion::refreshTextPositions() {
	std::vector<sf::Vector2f> positions = Card::refreshTextPositions();
	positions.push_back(sf::Vector2f(this->cardRectangle.getPosition().x + 120, this->cardRectangle.getPosition().y + 130));
	return positions;
}

void Minion::loseLife(int life)
{
	this->defense -= life;
}

void Minion::gainLife(int life)
{
	this->defense += life;
}

int Minion::getDefense()
{
	return this->defense;
}

bool Minion::hasEffect()
{
	bool hasEffect = this->effects.size() > 0;
	return hasEffect;
}

std::vector<Effect*> Minion::getEffects()
{
	return this->effects;
}

/* Destructors */
Minion::~Minion() {

}

/* Redefined operators */
std::ostream& operator<<(std::ostream& os, const Minion& minion)
{
	os << "Minion Description : \n"
		<< "\t - Name : " << minion.getName() << "\n"
		<< "\t - Attack : " << minion.getAttack() << "\n"
		<< "\t - Cost Mana : " << minion.getCostMana() << "\n"
		<< "\t - Defense : " << minion.defense << "\n"
		<< "\t - Status : " << minion.statusToString(minion.status) << "\n";
	return os;
}
