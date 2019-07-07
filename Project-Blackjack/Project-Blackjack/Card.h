#pragma once
#include "Enums.h"
#include <ostream>

class Card
{
protected:
	int Rank;
	int Value;
	enums::Suit Suit;
public:
	Card(int rank, enums::Suit suit);
	Card() = default;

	enums::Suit GetSuit() const;

	bool operator==(const int& intR) const;
	int operator+(const int& intR) const;

	friend std::ostream & operator<<(std::ostream& outputStream, const Card& toOutput);
};

