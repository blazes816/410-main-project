/*
  Represents the deck of cards.  It stores cards as an array of Cards.
  It generates the cards, then shuffles them.  Then, cards are handed
  out in index order.
*/
class Deck{
  Card deck[52];
  int used_index;

  public:
    /*
      The construtor creates 13 cards for each of the 4 suits
      and thens huffles them.
    */
    Deck()
    {
      int i, j, index;
      for(i=0; i < 4; i++)
      {
        for(j=1; j <= 13; j++)
        {
          index = (i*13) + j - 1;
          this->deck[index].value = j;
          this->deck[index].suit = i;
        }
      }

      Shuffle();
      this->used_index = 0;
    }

    /*
      Input: none
      Output: none
      Description: Shuffles the deck of cards
    */
    void Shuffle()
    {
      random_shuffle(this->deck, (this->deck + 52));
    }

    /*
      Input: none
      Output: The next index
      Description: Returns the next index to use.  If we're out
        of cards, shuffle and start over.
    */
    int Next()
    {
      int i =  this->used_index++;
      if(this->used_index > 51)
      {
        Shuffle();
        this->used_index = 0;
      }
      return i;
    }

    /*
      Input: The integer index of the card in the deck
      Output: The card
    */
    Card getCard(int index)
    {
      return this->deck[index];
    }
};
