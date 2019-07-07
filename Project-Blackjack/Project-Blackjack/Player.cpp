#include "Player.h"
#include "HardAce.h"
#include <iostream>

int Player::GetSoftAceIndex()
{
	auto index = 0;
	for(auto card = Hand.begin(); card != Hand.end(); ++card)
	{
		if (*card == 11)
		{
			return index;
		}
		index++;
	}
	return INT32_MIN;
}

Player::Player(std::vector<Card> hand)
{
	Hand = hand;
	Busted = false;
}

Player::~Player()
{
	Hand.clear();
}

int Player::GetHandSize() const
{
	return Hand.size();
}

void Player::AddToHand(Card toAdd)
{
	Hand.push_back(toAdd);

	const auto softAceIndex = GetSoftAceIndex();
	if(CardSum() > 21 && softAceIndex != INT32_MIN)
	{
		auto tmpAce = *(Hand.begin() + softAceIndex);
		*(Hand.begin() + softAceIndex) = *new HardAce(tmpAce.GetSuit());
	}
	else if(CardSum() > 21)
	{
		Busted = true;
	}
}

void Player::RevealHand()
{
	for(auto card = Hand.begin(); card != Hand.end(); ++card)
	{
		std::cout << *card;
	}
}

void Player::RevealOnlyFirstCard()
{
	std::cout << *Hand.begin();
	for
	(
		auto card = Hand.begin() + 1; 
		card != Hand.end(); 
		++card
	)
	{
		std::cout << "?" << std::endl;
	}
}

int Player::CardSum()
{
	auto sum = 0;
	for(auto card = Hand.begin(); card != Hand.end(); ++card)
	{
		sum = *card + sum;
	}
	return sum;
}

bool Player::IsBusted() const
{
	return Busted;
}
