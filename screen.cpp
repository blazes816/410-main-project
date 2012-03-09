/*
  The base class for all game screens.  A game screen only requires
  an Update method that does the current state-tick, and returns the
  next state to transition to.
*/
class Screen
{
  public:
    Screen()
    {

    }

    /*
      Input: none
      Output: A GameState enum for the next state
    */
    virtual GameState Update()
    {
      cout << "Default" << endl;
      return EXIT;
    }
};
