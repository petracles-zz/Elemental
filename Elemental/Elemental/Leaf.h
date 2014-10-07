// Header guard start
#ifndef LEAF_H
#define LEAF_H

#include "Node.h"

class Leaf : public Node {
public:
	Leaf();
	Leaf(string c, int HP, int DAM, int offense, int defense);
	void attack(Node* that);
	void defend();
	Node* changeElement(string color);
};
// Header guard end
#endif