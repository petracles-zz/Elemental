#include <iostream>
#include <string>
#include "Node.h"
#include "Fire.h"
#include "Water.h"
#include "Leaf.h"

using namespace std;

// Constants:
#ifndef CONSTANTS

const int easy = 50;
const int medium = 100;
const int hard = 150;

#endif CONSTANTS;

int test() {
	// Various testing of constructors:
	Node* testNode1 = new Node();
	Node* testNode2 = new Node("", 0, 0, 0, 0);
	Fire* testFire1 = new Fire();
	Fire* testFire2 = new Fire("", 0, 0, 0, 0);
	Water* testWater1 = new Water();
	Water* testWater2 = new Water("", 0, 0, 0, 0);
	Leaf* testLeaf1 = new Leaf();
	Leaf* testLeaf2 = new Leaf("", 0, 0, 0, 0);

	// Testing 'attack':
	cout << "Health before: " << testWater1->getHP() << endl;
	testFire1->attack(testWater1);
	cout << "Health after: " << testWater1->getHP() << endl;

	// Testing 'defend':
	cout << "Health before: " << testWater1->getHP() << endl;
	testWater1->defend();
	cout << "Health after: " << testWater1->getHP() << endl;

	// Testing 'changeElement':
	cout << "Element before: " << testWater1->getColor() << endl;
	testWater1->changeElement("f");
	cout << "Element after: " << testWater1->getColor() << endl;

	return 0;
}