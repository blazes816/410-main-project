/*
    Name: Tyler Smith
    WSUID: E433Z722

    Description: A Blackjack game

    Pseudocode:

      Core Game:
        Game Starts
          Assign default state (Menu)
          Loop
            Clear screen
            Update the current state clock (call an Update() method)
              The state handler draws as appropriate
              The state handler returns the new state (could be the same)
            Assign returned state to new current state
          End Loop


      Playing State:
        Create Deck
        Loop
          Deal cards
          Get bet from player
          Loop
            Ask player for more cards
            Add card if needed
          End Loop
          Do computer Artificial Intelligence
          Determine winner
          Award betted credits
        End Loop
        
*/
#include "blackjack.cpp"
