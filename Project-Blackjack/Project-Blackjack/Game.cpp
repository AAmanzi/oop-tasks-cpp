#include "Game.h"
#include <iostream>
#include "Utils.h"

Game::Game()
{
	Dealer = *new Player();
	Opponent = *new Player();
	PlayingDeck = *new Deck();
	GameOver = false;
}

void Game::ResetHands()
{
	Dealer = *new Player();
	Opponent = *new Player();
	GameOver = false;
}

void Game::ShuffleDeckIfEmpty()
{
	if(PlayingDeck.IsEmpty())
	{
		std::cout << "THE DECK HAS BEEN RESHUFFLED!" << std::endl;
		PlayingDeck = *new Deck();
	}
}

void Game::DealerDrawCard()
{
	Dealer.AddToHand(PlayingDeck.RemoveTopCard());
	ShuffleDeckIfEmpty();
}

void Game::OpponentDrawCard()
{
	Opponent.AddToHand(PlayingDeck.RemoveTopCard());
	ShuffleDeckIfEmpty();
}

void Game::DrawStartingCards()
{
	OpponentDrawCard();
	DealerDrawCard();
	OpponentDrawCard();
	DealerDrawCard();
}

void Game::DisplayGameStatus()
{
	utils::GuiUtils::PrintNewLines(1);
	std::cout << "Dealers hand: " << std::endl;
	Dealer.RevealOnlyFirstCard();
	utils::GuiUtils::PrintNewLines
		(
			22 - Dealer.GetHandSize() - Opponent.GetHandSize()
		);
	std::cout << "Your hand: " << std::endl;
	Opponent.RevealHand();
	std::cout << "_____________________________________________"
		<< std::endl << std::endl;
}

void Game::DisplayAllCards()
{
	utils::GuiUtils::PrintNewLines(1);
	std::cout << "Dealers hand: " << std::endl;
	Dealer.RevealHand();
	utils::GuiUtils::PrintNewLines
		(
			21 - Dealer.GetHandSize() - Opponent.GetHandSize()
		);
	std::cout << "Your hand: " << std::endl;
	Opponent.RevealHand();
}

void Game::DealerTurn()
{
	if(Dealer.CardSum() < 17)
	{
		DealerDrawCard();
	}
}

void Game::DealerFinishUp()
{
	while(Dealer.CardSum() < 17)
	{
		DealerTurn();
	}
}

void Game::OpponentTurn(int choice)
{
	if(choice == 2)
	{
		OpponentDrawCard();
		if(Opponent.IsBusted())
		{
			GameOver = true;
		}
	}
	else
	{
		GameOver = true;
	}
}

bool Game::IsGameOver() const
{
	return GameOver;
}

std::string Game::GetWinner()
{
	if(!Dealer.IsBusted() && Dealer.CardSum() > Opponent.CardSum()
		|| !Dealer.IsBusted() && Opponent.IsBusted())
	{
		return "The dealer won!";
	}
	if(!Opponent.IsBusted() && Dealer.CardSum() != Opponent.CardSum())
	{
		return "You won!";
	}
	return "It's a tie!";
}