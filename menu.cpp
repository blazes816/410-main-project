/*
  Represents the Menu screen.  Provides a few options for the player
  to choose from.
*/
class Menu : public Screen
{
  public:
    GameState Update()
    {
      // Display welcome prompt
      cout << "Welcome to Blackjack!" << endl;
      cout << endl << endl;
      cout << "1) Play" << endl;
      cout << "2) Rules" << endl;
      cout << "3) Exit" << endl << endl;
      cout << "Please choose an option: " << endl;

      // Get the option selection from the player
      int option;
      cin >> option;

      switch(option)
      {
        case 1:
          return PLAYING;
        case 2:
          return RULES;
        case 3:
          return EXIT;
      }
      return MENU;
    }
};
