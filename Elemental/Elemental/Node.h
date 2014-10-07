// Header guard start
#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>

using namespace std;

// Constants:
#ifndef CONSTANTS

const int damage = 10;
const int heal = 5;
const int bonus = 5;

#endif CONSTANTS;

// Base class NODE, that serves as the aprent of FIRE, WATER, and LEAF:
class Node {
protected:
	string color;
	int HP;
	int DAM;
	int offense;
	int defense;
public:
	Node();
	Node(string c, int HP, int DAM, int offense, int defense);
	~Node();
	virtual void attack(Node* n);
	virtual void defend();
	virtual Node* changeElement(string color);
	string getColor();
	int getHP();
	int getDAM();
	int getOffense();
	int getDefense();
	void setColor(string c);
	void setHP(int i);
	void setDAM(int i);
	void setOffense(int i);
	void setDefense(int i);
};
// Header guard end
#endif