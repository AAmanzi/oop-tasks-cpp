#pragma once
#include "Player.h"
#include "Deck.h"

class Game
{
	Player Dealer;
	Player Opponent;
	Deck PlayingDeck;
	bool GameOver;
public:
	Game();

	void ResetHands();
	void ShuffleDeckIfEmpty();
	void DealerDrawCard();
	void OpponentDrawCard();
	void DrawStartingCards();
	void DisplayGameStatus();
	void DisplayAllCards();
	void DealerTurn();
	void DealerFinishUp();
	void OpponentTurn(int choice); 
	//int choice: 
	//	1 meaning drawing a card, all else skipping
	bool IsGameOver() const;
	std::string GetWinner();
};

