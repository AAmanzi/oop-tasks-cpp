#include "Card.h"


Card::Card(int rank, enums::Suit suit)
{
	Rank = rank;

	switch(rank)
	{
	case 1:
		Value = 11;
		break;
	case 11:
	case 12:
	case 13:
		Value = 10;
		break;
	default:
		Value = rank;
	}

	Suit = suit;
}

enums::Suit Card::GetSuit() const
{
	return Suit;
}

bool Card::operator==(const int& intR) const
{
	return Value == intR;
}

int Card::operator+(const int& intR) const
{
	return Value + intR;
}

std::ostream& operator<<(std::ostream& outputStream, const Card& toOutput)
{
	outputStream 
		<< toOutput.Rank
		<< " of " 
		<< enums::EnumParser::ParseSuit(toOutput.Suit)
		<< std::endl;
	return outputStream;
}
