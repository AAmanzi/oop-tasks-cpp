#pragma once
#include "IVideoGame.h"

class VideoGame : public IVideoGame
{
protected:
	std::string Name;
	std::string Type;
	std::list<enums::Platform> Platforms;
public:
	VideoGame
	(
		std::string name, 
		std::string type, 
		std::list<enums::Platform> platforms
	);
	VideoGame() = default;

	std::string GetType() override;
	std::string GetName() override;
	std::list<enums::Platform> GetPlatforms() override;

	virtual ~VideoGame();
};

