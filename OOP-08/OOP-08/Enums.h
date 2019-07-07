#pragma once

namespace enums
{
	enum Platform
	{
		PC,
		PS4,
		XBOX
	};

	class EnumParser
	{
	public:
		static std::string ParsePlatform(enums::Platform platform)
		{
			if(platform == enums::PC)
				return "PC";
			if(platform == enums::PS4)
				return "PS4";
			if(platform == enums::XBOX)
				return "XBox";
			return {};
		}
	};
}
