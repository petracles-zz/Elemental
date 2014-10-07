#include "Node.h"

// Constructor(s):
Node::Node() {
	this->color = "";
	this->HP = 0;
	this->DAM = 0;
	this->offense = 0;
	this->defense = 0;
}

Node::Node(string c, int HP, int DAM, int offense, int defense) {
	this->color = c;
	this->HP = HP;
	this->DAM = DAM;
	this->offense = offense;
	this->defense = defense;
}

// Destructor:
Node::~Node() {
	delete this;
}

void Node::attack(Node* n) {
	// empty parent function
}

void Node::defend() {
	// empty parent function
}

Node* Node::changeElement(string c) {
	// empty parent function
	return new Node();
}

// Getter for color:
string Node::getColor() {
	return color;
}

// Getter for HP:
int Node::getHP() {
	return HP;
}

// Getter for DAM:
int Node::getDAM() {
	return DAM;
}
// Getter for offense:
int Node::getOffense() {
	return offense;
}

// Getter for defense:
int Node::getDefense() {
	return defense;
}

// Setter for color:
void Node::setColor(string c) {
	color = c;
}

// Setter for HP:
void Node::setHP(int i) {
	HP = i;
}

// Setter for DAM:
void Node::setDAM(int i) {
	DAM = i;
}
// Setter for offense:
void Node::setOffense(int i) {
	offense = i;
}

// Setter for defense:
void Node::setDefense(int i) {
	defense = i;
}