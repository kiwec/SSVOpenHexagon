// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef HG_UTILS
#define HG_UTILS

#include <string>
#include <json/json.h>
#include <json/reader.h>
#include <SFML/Graphics.hpp>
#include <SSVStart.h>
#include "Data/LevelData.h"
#include "Data/ProfileData.h"
#include "Data/MusicData.h"
#include "Data/StyleData.h"

namespace hg
{
	template<typename T> T getJsonValue(const Json::Value& mRoot, const std::string& mValue);
	template<typename T> T getJsonValueOrDefault(const Json::Value& mRoot, const std::string& mValue, T mDefault)
	{
		return mRoot.isMember(mValue) ? getJsonValue<T>(mRoot, mValue) : mDefault;
	}

	sf::Color getColorFromHue(double);
	sf::Color getColorDarkened(sf::Color, float);
	sf::Color getColorFromJsonArray(Json::Value mArray);

	Json::Value getJsonFileRoot(const std::string& mFilePath);

	LevelData loadLevelFromJson(Json::Value mRoot);
	MusicData loadMusicFromJson(Json::Value mRoot);
	StyleData loadStyleFromJson(Json::Value mRoot);
	ProfileData loadProfileFromJson(Json::Value mRoot);

	std::string getScoreValidator(const std::string& mId, float mDifficultyMult);

	void shakeCamera(ssvs::TimelineManager& mTimelineManager, ssvs::Camera& mCamera);
}

#endif
