/*****************************************************************************
		Tyler Smith
		E433Z722
		Project #1 (C++ project)

    This implements a game of Blackjack played between a player and the
    computer.  Each get's dealt 2 cards, and then can take as many more
    as they like.  In the end, the person with the higher total <= 21
    wins.  If there is a tie, neither wins or loses.

    The implementation uses a state-machine styled screen system.
    The screens are Playing, Rules, and Menu.  Each is represented
    by a child class of the Screen class.  Each game "tick", the current
    screen has it's public Update() method called which does it's calculations
    and returns the next state to go to.
******************************************************************************/
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

// Declare valid game states, and how many credits a palyer starts with
enum GameState {MENU, RULES, PLAYING, EXIT};
const unsigned int STARTING_CREDS = 100;

// Project includes
#include "card.cpp"
#include "deck.cpp"
#include "screen.cpp"
#include "menu.cpp"
#include "rules.cpp"
#include "playing.cpp"

/*  Represents our game.  It holds the screens and a pointer
    to the current screen.
*/
class Blackjack
{
  // The objects representing each state
  Screen *menu;
  Screen *playing;
  Screen *rules;

  // The current state
  Screen *current;

	public:
    Blackjack()
    {
      // Initialize our screens
      this->menu = new Menu();
      this->playing = new Playing();
      this->rules = new Rules();

      // Start with the menu
      this->current = this->menu;
    }

    // Input: none
    // Output: 0 to end the game, anything else to continue
    int Update()
    {
      // Update for a state returns the next state
      GameState next_state = this->current->Update();
      switch(next_state)
      {
        case MENU:
          this->current = this->menu;
          break;
        case PLAYING:
          this->current = this->playing;
          break;
        case RULES:
          this->current = this->rules;
          break;
        case EXIT:
          return 0;
          break;
      }

      return 1;
    }
};

 
int main()
{
  Blackjack game;
  int running = 1;

  while(running)
  {
    // Clear the screen for drawing
    system("clear");

    // Update will return 0 when we're finished
    running = game.Update();
  }

	return 0;
}
