#pragma once
#include <vector>
#include "CardSpade.h"

class Deck
{
protected:
	std::vector<Card> Cards;
public:
	Deck();
	~Deck();

	Card RemoveTopCard();
	bool IsEmpty() const;
	void Shuffle();
};

