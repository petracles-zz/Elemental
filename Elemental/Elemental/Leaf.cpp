#include "Fire.h"
#include "Water.h"
#include "Leaf.h"

Leaf::Leaf() {
	color = "LEAF";
	HP = 100;
	DAM = damage;
	offense = 1;
	defense = 3;
}

Leaf::Leaf(string c, int h, int da, int off, int def) {
	color = c;
	HP = h;
	DAM = da;
	offense = off;
	defense = def;
}

/* attack - takes in a Node pointer and takes off an amount of HP from that
node based off of the offense of the attacker's node and the bonus*/
void Leaf::attack(Node* n) {
	cout << "" << endl;
	cout << "Attck!" << endl;
	cout << "" << endl;
	if(n->getColor().compare("FIRE") == 0) {
		int attack = this->getDAM() * this->getOffense();
		n->setHP(n->getHP() - attack + bonus);
		cout << attack << " damage given!" << endl;
		cout << "" << endl;
	}
	else if(n->getColor().compare("WATER") == 0) {
		int attack = this->getDAM() * this->getOffense();
		n->setHP(n->getHP() - attack - bonus);
		cout << attack << " damage given!" << endl;
		cout << "" << endl;
	}
	else if(n->getColor().compare("LEAF") == 0) {
		int attack = this->getDAM() * this->getOffense();
		n->setHP(n->getHP() - attack);
		cout << attack << " damage given!" << endl;
		cout << "" << endl;
	}
	else {
		// ERROR, OH NO!
	}
}

/* defend - Heals the player an amount of HP based upon the defense of
the defender's node*/
void Leaf::defend() {
	cout << "" << endl;
	cout << "Defend!" << endl;
	cout << "" << endl;
	int h = this->defense * heal;
	this->setHP(this->getHP() + h);
	cout << "" << endl;
	cout << "Healed " << h << " Hit Points!" << endl;
	cout << "" << endl;
}

/* changeElement - takes in a string color (either f, w, or l) and
returns an instance of the appropriate node with the same stats*/
Node* Leaf::changeElement(string color) {
	if(color.compare("f") == 0) {
		Node* temp = new Fire("FIRE", this->HP, this->DAM, this->offense, this->defense);
		cout << "Changed to FIRE!" << endl;
		cout << "" << endl;
		return temp;
	}
	else if(color.compare("w") == 0) {
		Node* temp = new Water("WATER", this->HP, this->DAM, this->offense, this->defense);
		cout << "Changed to WATER!" << endl;
		cout << "" << endl;
		return temp;
	}
	else if(color.compare("l") == 0) {
		cout << "You were already LEAF... wated turn!" << endl;
		cout << "" << endl;
		return this;
	}
	else {
		cout << "Invalid entry, ya dummy. You were supposed to select an element..." << endl;
	}
}