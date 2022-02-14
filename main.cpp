#include <Windows.h>
#include "DiscordSDK/include/discord_rpc.h"
#include "DiscordSDK/include/discord_register.h"
#include <iostream>
#include "..\..\..\..\Desktop\shizukou\cpp\discord.h"

bool gInit = true;

void Initialize()
{
		DiscordEventHandlers handlers;
		memset(&handlers, 0, sizeof(handlers));
		Discord_Initialize("935720284223307836", &handlers, 1, "0");
}

static void UpdatePresence()
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "Playing Solo";
    discordPresence.details = "Competitive";
    discordPresence.startTimestamp = 1507665886;
    discordPresence.endTimestamp = 1507665886;
    discordPresence.largeImageText = "Numbani";
    discordPresence.smallImageText = "Rogue - Level 100";
    discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
    discordPresence.partySize = 1;
    discordPresence.partyMax = 5;
    discordPresence.joinSecret = "MTI4NzM0OjFpMmhuZToxMjMxMjM= ";
    Discord_UpdatePresence(&discordPresence);
}

int main()
{
	if (gInit){
        Initialize();
		gInit = false;
	}

    UpdatePresence();
	char k;
	std::cin >> k;
	if(k=='k')
		Discord_Shutdown();
}
