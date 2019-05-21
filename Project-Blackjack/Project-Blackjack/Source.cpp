#include <iostream>
#include "Deck.h"
#include "Game.h"

int main()
{
	auto match = new Game();
	auto playAgain = 0;

	do
	{
		match->ResetHands();
		match->DrawStartingCards();

		while(!match->IsGameOver())
		{
			match->DealerTurn();

			match->DisplayGameStatus();

			auto playerDecision = 0;
			std::cout << "1) Stand" << std::endl;
			std::cout << "2) Hit" << std::endl;
			std::cin >> playerDecision;

			match->OpponentTurn(playerDecision);
		}

		match->DealerFinishUp();
		match->DisplayAllCards();
		std::cout 
			<< std::endl
			<< match->GetWinner() << std::endl
			<< "Do you want to continue playing?" << std::endl
			<< "1) Yes" << std::endl
			<< "2) No" << std::endl;
		std::cin >> playAgain;
	}while(playAgain != 2);

	system("pause");
}
