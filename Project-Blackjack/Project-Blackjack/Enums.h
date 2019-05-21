#pragma once
#include <string>

namespace enums
{
	enum Suit
	{
		Spades,
		Hearts,
		Clubs,
		Diamonds
	};

	class EnumParser final
	{
	public:
		static std::string ParseSuit(enums::Suit suit)
		{
			switch(suit)
			{
			case enums::Spades:
				return "Spades";
			case enums::Hearts:
				return "Hearts";
			case enums::Clubs:
				return "Clubs";
			case enums::Diamonds:
				return "Diamonds";
			default:
				return "Error 404 not found!";
			}
		}
	};
}

