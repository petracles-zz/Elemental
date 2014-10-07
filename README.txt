John Kelly
Assignment 1 - Text Adventure Game
README File

The game I made is a simple Rock-Paper-Scissors game where the player can either
be a FIRE, WATER, or LEAF node. The game is turn based, with enemy AI automated
through a simple 3-choice RNG.

The player can attack the other node, where the following rules apply:
 - A FIRE node does the most damage, with a bonus against LEAF
 - A WATER node does the middle damage, with a bonus against FIRE
 - A LEAF node does the least damage, with a bonus against WATER
 
However, the player can also defend, where the following rules apply:
 - A FIRE node heals the least amount of HP
 - A WATER node heals the middle amount of HP
 - A LEAF node heals the most amount of HP
 
The player can also choose to change his/her node's element state, at the cost of
one turn.

The game ends when the player runs out of HP.

Game score is determined by the number of enemy nodes that the player manages
to kill before dying.