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
	void OpponentTurn(int choice); //1 meaning drawing a card, 0 skipping
	bool IsGameOver() const;
	std::string GetWinner();
};

