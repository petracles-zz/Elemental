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

// State machine:
int main(string args[]) {
	// Welcome prompt:
	cout << "Hello and welcome to Elemental!" << endl;
	cout << "" << endl;
	cout << "Battle the enemy with fire, water, are leaf for as long as you can survive!" << endl;
	cout << "" << endl;
	cout << "Let the match begin!!" << endl;
	cout << "" << endl;

	// Instance of NODE for the player:
	Node* nodeP_p = new Node();

	// (Randomized) instance of NODE for the enemy player:
	Node* nodeE_p = new Node();
	int random = rand() % 3 + 1;
	if(random == 1) {
		Fire* temp = new Fire();
		nodeE_p = temp; // Setting enemy node to FIRE
	}
	else if(random == 2) {
		Water* temp = new Water();
		nodeE_p = temp; // Setting enemy node to WATER
	}
	else {
		Leaf* temp = new Leaf();
		nodeE_p = temp; // Setting enemy node to LEAF
	}

	// Output enemy status:
	cout << "The enemy has been randomly assigned to " << nodeE_p->getColor() << endl;
	cout << "" << endl;

	// Let the player set his/her difficulty (enemy NODE starting HP)
	cout << "Choose the enemy's difficulty. [easy | medium | hard ]" << endl;
	int dif;
	string difficulty;
	cin >> difficulty;
	if(difficulty.compare("easy") == 0) {
		nodeE_p->setHP(easy);
		dif = easy;
		cout << "" << endl;
		cout << "Enemy Hit Points set to: 50" << endl;
		cout << "" << endl;
	}
	else if(difficulty.compare("medium") == 0) {
		nodeE_p->setHP(medium);
		dif = medium;
		cout << "" << endl;
		cout << "Enemy Hit Points set to: 100" << endl;
		cout << "" << endl;
	}
	else if(difficulty.compare("hard") == 0) {
		nodeE_p->setHP(hard);
		dif = hard;
		cout << "" << endl;
		cout << "Enemy Hit Points set to: 150" << endl;
		cout << "" << endl;
	}
	else {
		cout << "Invalid Entry: Setting player to default (medium)" << endl;
	}

	// Let the player choose his/her starting element state:
	cout << "Choose the element state you wish to begin as. Fire, Water, or Leaf? [ f | w | l ]" << endl;
	string playerstate;
	cin >> playerstate;
	if(playerstate.compare("f") == 0) {
		Fire* temp = new Fire();
		nodeP_p = temp;
		cout << "" << endl;
		cout << "You have chosen FIRE!" << endl;
		cout << "" << endl;
	}
	else if(playerstate.compare("w") == 0) {
		Water* temp = new Water();
		nodeP_p = temp;
		cout << "" << endl;
		cout << "You have chosen WATER!" << endl;
		cout << "" << endl;
	}
	else if(playerstate.compare("l") == 0) {
		Leaf* temp = new Leaf();
		nodeP_p = temp;
		cout << "" << endl;
		cout << "You have chosen LEAF!" << endl;
		cout << "" << endl;
	}
	else {
		cout << "Invalid Entry: Setting player to default (FIRE)" << endl;
		Fire* temp = new Fire();
		nodeP_p = temp;
	}

	// Score tracking:
	int score = 0;

	// Game loop:
	// The game will end when player_p is dead.
	while (nodeP_p->getHP() > 0) {

		// Output the game state:
		cout << "" << endl;
		cout << "Your Status: " << nodeP_p->getColor() << endl;
		cout << "Your HP: " << nodeP_p->getHP() << endl;
		cout << "Your Score: " << score << endl;
		cout << "" << endl;
		cout << "Enemy's Status: " << nodeE_p->getColor() << endl;
		cout << "Enemy's HP: " << nodeE_p->getHP() << endl;
		cout << "" << endl;

		// Make sure the user inputs a "good" action:
		bool goodAction = true;
		while(goodAction) {
			// Prompt the player:
			cout << "Attack, defend, or change your element? [a | d | c] :  ";
			string action;
			cin >> action;

			cout << "" << endl;
			cout << "You entered: " << action << endl;
			cout << "" << endl;
			if(action.compare("a") == 0) {
				nodeP_p->attack(nodeE_p);
				goodAction = false;
			}
			else if(action.compare("d") == 0) {
				nodeP_p->defend();
				goodAction = false;
			}
			else if(action.compare("c") == 0) {
				cout << "Choose the element state you wish to morph to. Fire, Water, or Leaf? [ f | w | l ]" << endl;
				string playerstate;
				cin >> playerstate;
				nodeP_p = nodeP_p->changeElement(playerstate);
				cout << "" << endl;
				cout << "You are now " << nodeP_p->getColor() << endl;
				cout << "" << endl;
				goodAction = false;
			}
			else {
				cout << "Invalid entry Try again..." << endl;
			}
		}

		// Player has finished his/her turn...

		// Check to see if enemy is alive. If dead, "spawn" a new enemy
		if(nodeE_p->getHP() < 0) {
			cout << "" << endl;
			cout << "Congrats! You killed the enemy!!" << endl;
			cout << "Your score has increased +1 and the enemy has respawned" << endl;
			cout << "Prepare for battle..." << endl;
			cout << "" << endl;
			nodeE_p->setHP(dif);
			score++;
		}

		// Enemy AI:
		int enemyAttack = rand() % 3 + 1;
		if(enemyAttack == 1) {
			// Enemy chose ATTACK
			cout << "The enemy chose ATTACK!" << endl;
			nodeE_p->attack(nodeP_p);
		}
		else if(enemyAttack == 2) {
			// Enemy chose DEFEND
			cout << "The enemy chose DEFEND!" << endl;
			nodeE_p->defend();
		}
		else {
			// Enemy chose CHANGE ELEMET
			cout << "The enemy chose CHANGE ELEMET!" << endl;
			string el;
			int enemyElement = rand() % 3 + 1;
			if(enemyElement == 1) {
				nodeE_p = nodeE_p->changeElement("f"); // Setting enemy node to FIRE
			}
			else if(enemyElement == 2) {
				nodeE_p = nodeE_p->changeElement("w"); // Setting enemy node to WATER
			}
			else {
				nodeE_p = nodeE_p->changeElement("l"); // Setting enemy node to LEAF
			}
		}
	}

	// The player has lost!
	cout << "GAME OVER: YOU LOSE!!" << endl;
	nodeP_p->~Node();
	nodeE_p->~Node();
}