// Header guard start
#ifndef FIRE_H
#define FIRE_H

#include "Node.h"

class Fire : public Node {
public:
	Fire();
	Fire(string c, int HP, int DAM, int offense, int defense);
	void attack(Node* that);
	void defend();
	Node* changeElement(string color);
};
// Header guard end
#endif