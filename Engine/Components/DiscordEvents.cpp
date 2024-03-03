/**
 *  DiscordEvents.cpp
 *  ONScripter-RU
 *
 *  Core functions for the discord api.
 *
 *  Consult LICENSE file for licensing terms and copyright holders.
 */

#if defined(DISCORD)
#include <discord/discord.h>
#include "Support/FileIO.hpp"
#include <iostream>
struct DiscordState {
	discord::User currentUser;

	std::unique_ptr<discord::Core> core;
};

DiscordState state{};
discord::Core* core{};

LogLevel translateLogLevel(discord::LogLevel level) {
	switch (level) {
		case discord::LogLevel::Warn:
			return LogLevel::Warn;
			break;
		case discord::LogLevel::Error:
			return LogLevel::Error;
			break;
		default:
			return LogLevel::Info;
			break;
	}
}

void shutdownDiscord() {
	state.core->ActivityManager().ClearActivity([](discord::Result result) {
		sendToLog(((result == discord::Result::Ok) ? LogLevel::Info : LogLevel::Error), "Stopping discord extension!\n");
	});
}

void initDiscord(const char* id) {
	auto result = discord::Core::Create(strtoll(id, NULL, 10), DiscordCreateFlags_NoRequireDiscord, &core);
	state.core.reset(core);
	std::string error;
	std::string description;

	// std::exit(-1);
	// state.core.reset();
	// shutdownDiscord();

	state.core->SetLogHook(
	    discord::LogLevel::Debug, [](discord::LogLevel level, const char* message) {
		    sendToLog(translateLogLevel(level), "Discord: %s\n", message);
	    });
}

void setPresence(const char* details, const char* currentState, const char* largeImageKey, const char* largeImageText, const char* smallImageKey, const char* smallImageText, const char* startTimestamp, const char* endTimestamp = NULL) {
	discord::Activity activity{};
	activity.SetDetails(details);
	activity.SetState(currentState);
	activity.GetAssets().SetSmallImage(smallImageKey);
	activity.GetAssets().SetSmallText(smallImageText);
	activity.GetAssets().SetLargeImage(largeImageKey);
	activity.GetAssets().SetLargeText(largeImageText);
	activity.GetTimestamps().SetStart(strtoll(startTimestamp, NULL, 10));
	activity.GetTimestamps().SetEnd(strtoll(endTimestamp, NULL, 10));
	activity.SetType(discord::ActivityType::Playing);
	state.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
		sendToLog(((result == discord::Result::Ok) ? LogLevel::Info : LogLevel::Error), "Updating discord status!\n");
	});
}

void runDiscordCallbacks() {
	state.core->RunCallbacks();
}

#endif