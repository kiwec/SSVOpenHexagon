// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef HG_MENUGAME
#define HG_MENUGAME

#include <vector>
#include <SFML/Graphics.hpp>
#include <SSVStart.h>
#include "Data/LevelData.h"
#include "Data/StyleData.h"
#include "Global/Config.h"

namespace hg
{
	enum class StateType { LEVEL_SELECTION, PROFILE_CREATION, PROFILE_SELECTION };

	class HexagonGame;

	class MenuGame
	{
		private:
			HexagonGame& hexagonGame;
			ssvs::GameState game;
			ssvs::GameWindow& window;
			sses::Manager manager;
			ssvs::Camera backgroundCamera{window, {{0, 0}, {getSizeX() * getZoomFactor(), getSizeY() * getZoomFactor()}}};
			ssvs::Camera overlayCamera{window, {{getWidth() / 2.f, getHeight() * getZoomFactor() / 2.f}, {getWidth() * getZoomFactor(), getHeight() * getZoomFactor()}}};
			StateType state{StateType::PROFILE_SELECTION};

			sf::Sprite titleBar{getAssetManager().getTexture("titleBar.png")};
			sf::Sprite creditsBar1{getAssetManager().getTexture("creditsBar1.png")};
			sf::Sprite creditsBar2{getAssetManager().getTexture("creditsBar2.png")};
			sf::Sprite bottomBar{getAssetManager().getTexture("bottomBar.png")};

			float inputDelay{0};
			std::vector<std::string> levelDataIds;
			int currentIndex{0}, packIndex{0};

			std::string profileCreationName;
			int profileIndex{0};

			std::vector<float> difficultyMultipliers;
			int difficultyMultIndex{0};

			void update(float mFrameTime);
			void draw();
			void drawLevelSelection();
			void drawProfileCreation();
			void drawProfileSelection();
			void setIndex(int mIndex);
			void renderText(const std::string& mString, sf::Text& mText, sf::Vector2f mPosition);

			LevelData levelData;
			StyleData styleData;
			sf::Text 	cProfText{"", getFont("imagine.ttf"), 25},
						levelName{"", getFont("imagine.ttf"), 80},
						levelDesc{"", getFont("imagine.ttf"), 35},
						levelAuth{"", getFont("imagine.ttf"), 20},
						levelMusc{"", getFont("imagine.ttf"), 20};

		public:
			MenuGame(HexagonGame& mHexagonGame, ssvs::GameWindow& mGameWindow);

			void init();
			void render(sf::Drawable&);

			ssvs::GameState& getGame();
	};
}

#endif
