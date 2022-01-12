#include<iostream>
using namespace std;
class TicTacToe
{
	private:
		char mak[3][3];
	public:
		TicTacToe();
		void makeMove();
		void printBoard();
		int validMove();
		int gameStatus();
		void startGame();
};
int TicTacToe::validMove()
{
	int move,player=1,i;
	char mark='X';
	do
	{
		player =(player%2)? 1 : 2;
		printBoard();
		mark=(player == 1)? 'X' : 'O';
		cout << "Player "<< mark << " enter move: ";
		cin >> move;
		mark=(player == 1)? 'X' : 'O';
		if(move == 1 && mak[0][0] == ' ')
		{
			mak[0][0] = mark;
		}
		else if(move == 2 && mak[0][1] == ' ')
		{
			mak[0][1] = mark;
		}
		else if(move == 3 && mak[0][2] == ' ')
		{
			mak[0][2] = mark;
		}
		else if(move == 4 && mak[1][0] == ' ')
		{
			mak[1][0] = mark;
		}
		else if(move == 5 && mak[1][1] == ' ')
		{
			mak[1][1] = mark;
		}
		else if(move == 6 && mak[1][2] == ' ')
		{
			mak[1][2] = mark;
		}
		else if(move == 7 && mak[2][0] == ' ')
		{
			mak[2][0] = mark;
		}
		else if(move == 8 && mak[2][1] == ' ')
		{
			mak[2][1] = mark;
		}
		else if(move == 9 && mak[2][2] == ' ')
		{
			mak[2][2] = mark;
		}
		else{
			cout <<"Invalid move ";
			player--;
			cin.ignore();
			cin.get();
		}
		i=gameStatus();
		player++;
	}while (i==-1);
	
	printBoard();
	if(i==1)
	{
		--player;
		cout<<"\n==>\aPlayer "<<mark<<" win "<<endl;
		for(int hs = 0; hs < 3; hs++)
		{
			for(int sk = 0; sk < 3; sk++)
			{
				mak[hs][sk] = ' ';
			}
		}
	}
	else
	{
		cout << "\n==>\aGame Draw" <<endl;
		for(int ma = 0; ma < 3; ma++)
		{
			for(int mk = 0; mk < 3; mk++)
			{
				mak[ma][mk] = ' ';
			}
		}
	}	
}

TicTacToe::TicTacToe()
{
	for(int ma = 0; ma < 3; ma++)
	{
          for(int mk = 0; mk < 3; mk++)
	     {
               mak[ma][mk] = ' ';
          }
	}
}
int TicTacToe::gameStatus()
{
	if(mak [0][0] == mak[0][1] && mak[0][1] == mak[0][2] && mak[0][0] != ' ')	
	return 1;
	
	else if(mak [1][0] == mak[1][1] && mak[1][1] == mak[1][2] && mak[1][0] != ' ')
	return 1;
	
	else if(mak [2][0] == mak[2][1] && mak[2][1] == mak[2][2] && mak[2][0] != ' ')
	return 1;
	
	else if(mak [0][0] == mak[1][0] && mak[1][0] == mak[2][0] && mak[0][0] != ' ')
	return 1;
	
	else if(mak [0][1] == mak[1][1] && mak[1][1] == mak[2][1] && mak[0][1] != ' ')
	return 1;
	
	else if(mak [0][2] == mak[1][2] && mak[1][2] == mak[2][2] && mak[0][2] != ' ')
	return 1;
	
	else if(mak [0][0] == mak[1][1] && mak[1][1] == mak[2][2] && mak[0][0] != ' ')
	return 1;
	
	else if(mak [0][2] == mak[1][1] && mak[1][1] == mak[2][0] && mak[0][2] != ' ')
	return 1;
	
	else if(mak[0][0] != ' ' && mak[0][1] != ' ' && mak[0][2] != ' ' && mak[1][0] != ' ' && mak[1][1] != ' ' && mak[1][2] != ' ' && mak[2][0] != ' ' && mak[2][1] != ' ' && mak[2][2] != ' ')
	return 0;
	else
	return -1;
	
}
void TicTacToe::makeMove()
{
	validMove();
}
void TicTacToe::startGame()
{
	makeMove();
}
void TicTacToe::printBoard()
{
	cout<<" 0\t1\t2" <<endl <<endl;
	cout <<"0    :    :    " <<endl;
	cout << "   " <<mak[0][0] <<" : " << "" <<mak[0][1] <<"  : "<<" " <<mak[0][2] <<endl;
	cout <<" ____:____:____" <<endl;
	cout << "1    :    :    " <<endl;
	cout << "   " <<mak[1][0] <<" : " << "" <<mak[1][1] <<"  : "<<" " <<mak[1][2] <<endl;
	cout <<" ____:____:____" <<endl;
	cout << "2    :    :    " <<endl;
	cout << "   " <<mak[2][0] <<" : " << "" <<mak[2][1] <<"  : "<<" " <<mak[2][2] <<endl;
	cout << "     :    :    " <<endl;
	cout <<"\n";
	
}

int main()
{
	TicTacToe myGame;
	int run = 1;
	char choice;
	do{
		myGame.startGame();
		cout << "\nDo you want to play again[y/n]: ";
		cin >> choice;
		cout <<"\n";
		if(choice=='y' || choice=='Y')
		{
			run =1;
		}
		else
		{
			run=0;
		}
	}while(run==1);
	
	return 0;
}
