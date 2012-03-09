class Rules : public Screen
{
  public:
    GameState Update()
    {
      cout << "The game of Blackjack is you against the dealer." << endl;
      cout << "You will each be dealt two cards after you make a bet." << endl;
      cout << "You can take as many cards from the deck as you like" << endl;
      cout << "then the dealer does the same." << endl << endl;

      cout << "After both of you have finished drawing cards a winner" << endl;
      cout << "is determined.  If you tie, neither wins.  If you have" << endl;
      cout << "the highest total, under 22, you win." << endl << endl;

      cout << "Press ENTER to return to menu...";

      // Wait for enter press
      while (getchar() != '\n');
      while (getchar() != '\n');
      return MENU;
    }
};
