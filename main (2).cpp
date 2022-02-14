#include <Windows.h>
#include <chrono>
#include <iostream>
#include <array>
#include <string>


#include "discord_rpc.h"
#include "discord_register.h"

void SetupDiscord()
{
    printf("does this get called?\n");
		DiscordEventHandlers handlers;
		memset(&handlers, 0, sizeof(handlers));
		Discord_Initialize("", &handlers, 1, "0");

}
std::string ee;
std::array<std::string, 11> lines = { "Bakerloo Line","Central Line", "Circle Line","District Line","Hammersmith & City Line","Jubilee Line","Metropolitan Line Tube","Northern Line","Piccadilly Line","Victoria Line","Waterloo & City Line" };
std::array<std::string, 25> tubes = { "Elephant And Castle",
"Lambeth North",
"Waterloo",
"Embankment",
"Charing Cross",
"Piccadilly Circus",
"Oxford Circus",
"Regent's Park",
"Baker Street",
"Marylebone",
"Edgware Road",
"Paddington",
"Warwick Avenue",
"Maida Vale",
"Kilburn Park",
"Queen's Park",
"Kensal Green",
"Willesden Junction",
"Harlesden",
"Stonebridge Park",
"Wembley Central",
"North Wembley",
"South Kenton",
"Kenton",
"Harrow And Wealdstone" };
int g = 1;
int e;
int tramse=0;
size_t next = time(NULL);
std::time_t current = next;

static void UpdateDiscord()
{
   // printf("[2] does this get called?\n");
    ee = tubes[tramse];
        DiscordRichPresence discordPresence;
        memset(&discordPresence, 0, sizeof(discordPresence));
        discordPresence.state = ee.c_str();
        discordPresence.details = "Bakerloo Line";
        discordPresence.startTimestamp = next;
        discordPresence.endTimestamp = current;
        discordPresence.buttonsLabel = "bebebee";
        discordPresence.buttonsUrl = "bebebee";
        discordPresence.largeImageKey = "1200px-underground_svgex";
        discordPresence.largeImageText = "Roundel";
        discordPresence.smallImageText = "Roundel";
        discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
        discordPresence.partySize = tramse;
        discordPresence.partyMax = 25;
        discordPresence.joinSecret = "MTI4NzM0OjFpMmhuZToxMjMxMjM= ";
        
        Discord_UpdatePresence(&discordPresence);
}

int main()
{
	printf("[3] int main!\r\n");
	printf("excusez moi!");

		SetupDiscord();
        while (true) {
            next = time(NULL);
            std::cout << "[" << next-current-((next - current)*2)-1 << "] Station:" << ee << " | Line:" << "Bakerloo Line" << std::endl;
            if (next >= current) {
                tramse++;
                if (tramse > 25)
                    tramse = 1;
               
                current = next + 60;
            }
            UpdateDiscord();
        }

}
