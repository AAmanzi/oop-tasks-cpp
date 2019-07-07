#pragma once
#include <iostream>

namespace utils{
	class GuiUtils final
	{
	public:
		static void PrintNewLines(const int amount)
		{
			for(auto i = 0; i < amount; ++i)
			{
				std::cout << std::endl;
			}
		}
	};
}
