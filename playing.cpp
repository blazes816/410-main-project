/*
  Represents the Play screen.  This is where the heavy game logic is
*/
class Playing : public Screen
{
  // Create the deck, and arrays to hold the dealer and player hands
  Deck deck;
  int p_hand[26];
  int d_hand[26];

  // Create indexes to the current place in the hands
  int p_index;
  int d_index;

  // Tracks how many credits a user has, and what the current bet is
  unsigned int creds;
  unsigned int current_bet;

  /*
    Input: none
    Output: none
    Description: Deals two cards to each the player, and the dealer.
      First the player, then dealer, then player, then dealer.
  */
  void deal()
  {
    this->p_hand[p_index++] = this->deck.Next();
    this->d_hand[d_index++] = this->deck.Next();
    this->p_hand[p_index++] = this->deck.Next();
    this->d_hand[d_index++] = this->deck.Next();
  }

  /*
    Input: none
    Output: none
    Description: Draws the current game state to the screen.
  */
  void show()
  {
    int i, total;

    // Loop from the current end of the hand, down to 0.
    // For each loop:
    //   Get the card from the deck with that index, show
    //   the card, and add the total
    total = 0;
    cout << "House: ";
    for(i = this->d_index - 1; i >= 0; i--){
      Card c = this->deck.getCard(this->d_hand[i]);
      cout << c << "\t";
      total += c.value;
    }
    cout << "(" << total << ")" << endl;

    // Repeat for player
    total = 0;
    cout << "You:   ";
    for(i = this->p_index - 1; i >= 0; i--){
      Card c = this->deck.getCard(this->p_hand[i]);
      cout << c << "\t";
      total += c.value;
    }
    cout << "(" << total << ")" << endl;
  }

  /*
    Input: none
    Output: none
    Description: Prompts the user for a bet.  Loops until bet is valid
      (At least 5)
  */
  void get_bet()
  {
    int i = 0;
    do
    {
      cout << "How much would you like to bet (5 minimum): ";
      cin >> i;
    } while(i < 5);
    this->current_bet = i;
  }

  /*
    Input: none
    Output: none
    Description: Prompt the user to draw more cards.
  */
  void get_hits()
  {
    char ans = 'a';
    while(1)
    {
      do
      {
        cout << "Would you like another card ('y' or 'n')? ";
        cin >> ans;
      } while (ans != 'y' && ans != 'n');

      if(ans == 'y')
      {
        hit(this->p_hand, this->p_index);
        show();
      }
      else
      {
        break;
      }
    }
  }

  /*
    Input: none
    Output: none
    Description: Checks the hands to determine the winner of the round.
      Awards credits accordingly.
  */
  void check()
  {
    int p_total = get_total(this->p_hand, this->p_index);
    int d_total = get_total(this->d_hand, this->d_index);

    if(((p_total > 21) && (d_total > 21)) || (p_total == d_total))
    {
      cout << endl << "PUSH!" << endl;  
    }
    else if((p_total > 21) && (d_total <= 21))
    {
      cout << endl << "BUST!" << endl;
      this->creds -= this->current_bet;
    }
    else
    {
      cout << endl << "WIN!" << endl;
      this->creds += this->current_bet;
    }
  }

  /*
    Input: A reference to the hand, and it's matching index
    Output: none
    Description: Puts the next card from deck in the passed in hand.
  */
  void hit(int (&hand)[26], int &index)
  {
    hand[index++] = this->deck.Next();
  }

  /*
    Input: none
    Output: none
    Description: Controls the AI for the computer player
  */
  void play_dealer()
  {
    int total = 0;
    int i = 0;

    for(i = this->d_index - 1; i >= 0; i--)
    {
      Card c = this->deck.getCard(this->d_hand[i]);
      total += c.value;
    }

    // Very simple algorithm.  If our total is < 17, hit.
    while(total < 17){
      hit(this->d_hand, this->d_index);
      for(i = this->d_index - 1; i >= 0; i--)
      {
        Card c = this->deck.getCard(this->d_hand[i]);
        total += c.value;
      }
    }
  }

  /*
    Input: The hand and it's matching index
    Output: The total
    Description: Determines the total for a given hand
  */
  int get_total(int (&hand)[26], int &index){
    int total = 0;
    int i = 0;
    for(i = index - 1; i >= 0; i--)
    {
      total += this->deck.getCard(hand[i]).value;
    }
    return total;
  }

  public:
    Playing()
    {
      this->creds = STARTING_CREDS;
      this->p_index = 0;
      this->d_index = 0;
    }

    GameState Update()
    {
      // Show the starting message for the round
      cout << "(Press ctrl+c to quit)" << endl;
      cout << "You have: " << this->creds << " credits" << endl << endl;
      // Get the bet from the player
      get_bet();
      // Deal the cards to dealer and player
      deal();
      // Show the hands
      show();
      // Prompt the user for more cards until satisfied
      get_hits();
      // Run the computer AI
      play_dealer();
      // Show the new standing
      show();
      // Check for winning or losing, award credits
      check();

      cout << endl;
      // Show the user's new credit total and prompt to press enter to continue
      cout << "You have: " << this->creds << " credits" << endl << endl;
      cout << "Press ENTER to continue...";

      // Wait for enter press
      while (getchar() != '\n');
      while (getchar() != '\n');

      // Reset.  All we have to do is set our hand index to 0.
      // It will overwrite the new cards drawn.
      this->p_index = 0;
      this->d_index = 0;

      // For now, we simple keep playing
      return PLAYING;
    }
};
