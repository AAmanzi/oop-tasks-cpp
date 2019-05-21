#include "Deck.h"
#include <chrono>

Deck::Deck()
{
	const auto cardsPerSuit = 52 / 4;
	for (auto i = 0; i < 4; ++i)
	{
		const auto currentSuit = static_cast<enums::Suit>(i);
		for(auto value = 1; value <= cardsPerSuit; ++value)
		{
			Cards.push_back(*new Card(value, currentSuit));
		}
	}
	Shuffle();
}

Deck::~Deck()
{
	Cards.clear();
}

Card Deck::RemoveTopCard()
{
	const auto topCard = Cards.back();
	Cards.pop_back();
	return topCard;
}

bool Deck::IsEmpty() const
{
	return Cards.empty();
}

void Deck::Shuffle()
{
	for(auto i = Cards.begin(); i != Cards.end(); ++i)
	{
		const unsigned toSwapWith = 
			std::chrono::system_clock::now()
			.time_since_epoch()
			.count() % 52;

		std::iter_swap(i, Cards.begin() + toSwapWith);
	}
}
