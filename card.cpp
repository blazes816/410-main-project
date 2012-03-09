/*
  Represents a single card.  The value property is the numeric
  value, and the suit is an integer [0,3] representing the suit.
    
  It provides an overloaded << for printing
*/
class Card{
  friend ostream& operator<< (ostream &out, Card us);
  public:
    int value;
    char suit;
};

ostream& operator<< (ostream &out, Card us)
{
  int val = us.value;
  char suit;
  // Display face cards correctly
  switch(us.value)
  {
    case 13:
      out << "K";
      break;
    case 12:
      out << "Q";
      break;
    case 11:
      out << "J";
      break;
    default:
      out << us.value;
  }

  switch(us.suit)
  {
    case 0:
      out << "H";
      break;
    case 1:
      out << "S";
      break;
    case 2:
      out << "D";
      break;
    case 3:
      out << "C";
      break;
  }
}
