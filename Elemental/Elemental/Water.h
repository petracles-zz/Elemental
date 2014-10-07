// Header guard start
#ifndef WATER_H
#define WATER_H

#include "Node.h"

class Water : public Node {
public:
	Water();
	Water(string c, int HP, int DAM, int offense, int defense);
	void attack(Node* that);
	void defend();
	Node* changeElement(string color);
};
// Header guard end
#endif