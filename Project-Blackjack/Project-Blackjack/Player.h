#pragma once
#include <vector>
#include "CardSpade.h"

class Player
{
protected:
	std::vector<Card> Hand;
	bool Busted;

	int GetSoftAceIndex();
public:
	Player(std::vector<Card> hand);
	Player() = default;
	~Player();

	int GetHandSize() const;
	void AddToHand(Card toAdd);
	void RevealHand();
	void RevealOnlyFirstCard();
	int CardSum();
	bool IsBusted() const;
};
