#include<iostream>
#include<fstream>
#include<queue>

/* Function: AppendQueue
   

*/
void AppendQueue(queue<char> &player_pile, queue<char> &discard_pile);

int main(int argc, char *argv[])
{
  using namespace std;

  queue<char> discard_pile, player1_pile, player2_pile;

  istream infile(argv[1])
    if(!infile)
      {
	exit();
      }

  ostream outfile(argv[2])
    if(!outfile)
      {
	exit();
      }

  //declaring variables
  int num_games;
  char ch;
  
  infile >> ch;
  num_games = '0' - ch;

  bool endGame = false, endRound = false;
  int n=0, k=0;
  while(n < num_games && !endGame) // Will run 'num_games' times unless endGame become TRUE
    {
      infile >> ch;
	  cardsNum = '0' - ch;

      //filling the queues with cards
      for(int j=0; j < (starting_piles*2); j++)
	{
	  if(j < starting_piles)
	    player1_pile.push(card);
	  else
	    player2_pile.push(card);
	}  // end filling

      while(k < starting_piles && !endRound)
	{
	  
      p1Card = player1_pile.top();
      p2Card = player2_pile.top();

      if(p1Card > p2Card)
	{
	  AppendQueue(player1_pile, discard_pile);
	  player1_pile.push(p1Card);
	  player1_pile.push(p2Card);
	  endRound = true;
	}
      
      else if(p1Card < p2Card)
	{
	  AppendQueue(player2_pile, discard_pile);
	  player2_pile.push(p1Card);
	  player2_pile.push(p2Card);
	  endRound = true;
	}

      else if(p1Card = p2Card)

	}

	  if (player1_pile.empty() && player2_pile.empty())
	  {
		  endRound = true;
		  endGame = true;
	  }

	  else if (player1_pile.empty())
	  {
		  AppendQueue(player2_pile, discard_pile);
		  endRound = true;
		  endGame = true;
	  }

	  else if (player2_pile.empty())
	  {
		  AppendQueue(player1_pile, discard_pile);
		  endRound = true;
		  endGame = true;
	  }
      

      n++;
    } // the end of the game
  
}


void AppendQueue(queue<char> &player_pile, queue<char> &discard_pile)
{
  char front;
  
  while(!discard_pile.empty())
    {
      
  front =discard_pile.front();
  discard_pile.pop();
  player_pile(front);
    }
  
}
