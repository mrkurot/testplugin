#define PURPLE_PLUGINS

#include <glib.h>
#include <string.h>
#include <curl/curl.h>

#include "notify.h"
#include "conversation.h"
#include "cmds.h"
#include "plugin.h"
#include "version.h"
#include "debug.h"

#define PLUGIN_ID "core-test-plugin"
#define USR_AGENT "TESTPidginPlugin/0.1 (+mailto:mrkurotsuki@gmail.com)"

#define CHAT_NAME "ukoc@chat.pleaseignore.com"
#define BITTERVET_NAME "Khuros Khan"
#define NEWBRO_NAME "Kurot Askulf"
#define NEWBRO_ALT "Kurot 'Carrot' Askulf"

static PurplePlugin *test_plugin = NULL;
static CURL *curl = NULL;

static void chat_buddy_joined(PurpleConversation *conv, const char *name,
                          PurpleConvChatBuddyFlags flags,
                          gboolean new_arrival) {
    if (!strncmp(conv->name, CHAT_NAME, 100) && !strncmp(name, BITTERVET_NAME, 100)) {
        purple_debug_error(PLUGIN_ID, "Changing nick\n");
        gchar *error;
        PurpleCmdStatus status = purple_cmd_do_command(conv, "nick " NEWBRO_ALT, "", &error);
        g_free(error);
        purple_debug_error(PLUGIN_ID, "Executed %d\n", status);
    }
}

static void chat_buddy_left(PurpleConversation *conv, const char *name,
                          PurpleConvChatBuddyFlags flags,
                          gboolean new_arrival) {
    if (!strncmp(conv->name, CHAT_NAME, 100) && !strncmp(name, BITTERVET_NAME, 100)) {
        gchar *error;
        PurpleCmdStatus status = purple_cmd_do_command(conv, "nick " NEWBRO_NAME, "", &error);
        g_free(error);
    }
    
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, char *output) {
    memcpy(output, ptr, size * nmemb);
    output[size*nmemb] = '\0';

    return size*nmemb;
}

int binsearch(char *arr[], int l, int r, char *x) {
    while (l <= r) {
        int m = l + (r-l)/2;
        if (arr[m][0] == x[0]) {
            if (arr[m][1] == x[1]) {
                for (int i = 0; arr[m][1] == x[1]; i++) {
                    if (!strncmp(x, arr[m+i], strlen(arr[m+i]))){
                        return m+i;
                    }
                }
                for (int i = -1; arr[m][1] == x[1]; i--) {
                    if (!strncmp(x, arr[m+i], strlen(arr[m+i]))){
                        return m+i;
                    }
                }
            }
            if (arr[m][1] < x[1]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        } else if (arr[m][0] < x[0]) {
             l = m + 1;
        } else {
             r = m - 1; 
        }
    }
 
    return -1; 

}

int iseft(char *str) {
    char *ships[246];

    ships[0] = "Abaddon";
    ships[1] = "Absolution";
    ships[2] = "Aeon";
    ships[3] = "Algos";
    ships[4] = "Anathema";
    ships[5] = "Anshar";
    ships[6] = "Apocalypse";
    ships[7] = "Apocalypse Navy Issue";
    ships[8] = "Apocalypse Imperial Issue";
    ships[9] = "Apotheosis";
    ships[10] = "Arazu";
    ships[11] = "Arbitrator";
    ships[12] = "Archon";
    ships[13] = "Ares";
    ships[14] = "Ark";
    ships[15] = "Armageddon";
    ships[16] = "Ashimmu";
    ships[17] = "Astarte";
    ships[18] = "Astero";
    ships[19] = "Atron";
    ships[20] = "Augoror";
    ships[21] = "Augoror Navy Issue";
    ships[22] = "Avatar";
    ships[23] = "Badger";
    ships[24] = "Bantam";
    ships[25] = "Basilisk";
    ships[26] = "Bellicose";
    ships[27] = "Bestower";
    ships[28] = "Bhaalgorn";
    ships[29] = "Blackbird";
    ships[30] = "Breacher";
    ships[31] = "Broadsword";
    ships[32] = "Brutix";
    ships[33] = "Burst";
    ships[34] = "Bustard";
    ships[35] = "Buzzard";
    ships[36] = "Caldari Navy Hookbill";
    ships[37] = "Caracal";
    ships[38] = "Catalyst";
    ships[39] = "Celestis";
    ships[40] = "Cerberus";
    ships[41] = "Chameleon";
    ships[42] = "Cheetah";
    ships[43] = "Chimera";
    ships[44] = "Claw";
    ships[45] = "Claymore";
    ships[46] = "Coercer";
    ships[47] = "Condor";
    ships[48] = "Confessor";
    ships[49] = "Corax";
    ships[50] = "Cormorant";
    ships[51] = "Covetor";
    ships[52] = "Crane";
    ships[53] = "Crow";
    ships[54] = "Crucifier";
    ships[55] = "Cruor";
    ships[56] = "Crusader";
    ships[57] = "Curse";
    ships[58] = "Cyclone";
    ships[59] = "Cynabal";
    ships[60] = "Damnation";
    ships[61] = "Daredevil";
    ships[62] = "Deimos";
    ships[63] = "Devoter";
    ships[64] = "Dominix";
    ships[65] = "Dragoon";
    ships[66] = "Drake";
    ships[67] = "Dramiel";
    ships[68] = "Eagle";
    ships[69] = "Enyo";
    ships[70] = "Eos";
    ships[71] = "Erebus";
    ships[72] = "Eris";
    ships[73] = "Executioner";
    ships[74] = "Exequror";
    ships[75] = "Exequror Navy Issue";
    ships[76] = "Falcon";
    ships[77] = "Ferox";
    ships[78] = "Flycatcher";
    ships[79] = "Federation Navy Comet";
    ships[80] = "Garmur";
    ships[81] = "Gila";
    ships[82] = "Gnosis";
    ships[83] = "Gold Magnate";
    ships[84] = "Golem";
    ships[85] = "Goru's Shuttle";
    ships[86] = "Griffin";
    ships[87] = "Guardian";
    ships[88] = "Guardian-Vexor";
    ships[89] = "Guristas Shuttle";
    ships[90] = "Harbinger";
    ships[91] = "Harpy";
    ships[92] = "Hawk";
    ships[93] = "Hecate";
    ships[94] = "Hel";
    ships[95] = "Helios";
    ships[96] = "Heretic";
    ships[97] = "Heron";
    ships[98] = "Hoarder";
    ships[99] = "Hound";
    ships[100] = "Huginn";
    ships[101] = "Hulk";
    ships[102] = "Hurricane";
    ships[103] = "Hyena";
    ships[104] = "Hyperion";
    ships[105] = "Ibis";
    ships[106] = "Imicus";
    ships[107] = "Impairor";
    ships[108] = "Impel";
    ships[109] = "Imperial Navy Slicer";
    ships[110] = "Incursus";
    ships[111] = "Inquisitor";
    ships[112] = "Ishkur";
    ships[113] = "Ishtar";
    ships[114] = "Iteron Mark V";
    ships[115] = "Jaguar";
    ships[116] = "Jackdaw";
    ships[117] = "Keres";
    ships[118] = "Kestrel";
    ships[119] = "Kitsune";
    ships[120] = "Kronos";
    ships[121] = "Lachesis";
    ships[122] = "Legion";
    ships[123] = "Leviathan";
    ships[124] = "Loki";
    ships[125] = "Machariel";
    ships[126] = "Mackinaw";
    ships[127] = "Maelstrom";
    ships[128] = "Magnate";
    ships[129] = "Malediction";
    ships[130] = "Maller";
    ships[131] = "Mammoth";
    ships[132] = "Manticore";
    ships[133] = "Mastodon";
    ships[134] = "Maulus";
    ships[135] = "Megathron";
    ships[136] = "Megathron Federate Issue";
    ships[137] = "Megathron Navy Issue";
    ships[138] = "Merlin";
    ships[139] = "Moa";
    ships[140] = "Moros";
    ships[141] = "Muninn";
    ships[142] = "Myrmidon";
    ships[143] = "Naga";
    ships[144] = "Naglfar";
    ships[145] = "Navitas";
    ships[146] = "Nemesis";
    ships[147] = "Nereus";
    ships[148] = "Nidhoggur";
    ships[149] = "Nighthawk";
    ships[150] = "Nightmare";
    ships[151] = "Nomad";
    ships[152] = "Nyx";
    ships[153] = "Occator";
    ships[154] = "Omen";
    ships[155] = "Omen Navy Issue";
    ships[156] = "Oneiros";
    ships[157] = "Onyx";
    ships[158] = "Oracle";
    ships[159] = "Orca";
    ships[160] = "Osprey";
    ships[161] = "Osprey Navy Issue";
    ships[162] = "Paladin";
    ships[163] = "Panther";
    ships[164] = "Phantasm";
    ships[165] = "Phobos";
    ships[166] = "Phoenix";
    ships[167] = "Pilgrim";
    ships[168] = "Prorator";
    ships[169] = "Probe";
    ships[170] = "Procurer";
    ships[171] = "Prophecy";
    ships[172] = "Prospect";
    ships[173] = "Proteus";
    ships[174] = "Prowler";
    ships[175] = "Punisher";
    ships[176] = "Purifier";
    ships[177] = "Ragnarok";
    ships[178] = "Rapier";
    ships[179] = "Raptor";
    ships[180] = "Rattlesnake";
    ships[181] = "Raven";
    ships[182] = "Raven Navy Issue";
    ships[183] = "Raven State Issue";
    ships[184] = "Reaper";
    ships[185] = "Redeemer";
    ships[186] = "Republic Fleet Firetail";
    ships[187] = "Retribution";
    ships[188] = "Retriever";
    ships[189] = "Revelation";
    ships[190] = "Rhea";
    ships[191] = "Rifter";
    ships[192] = "Rokh";
    ships[193] = "Rook";
    ships[194] = "Rorqual";
    ships[195] = "Rupture";
    ships[196] = "Sabre";
    ships[197] = "Sacrilege";
    ships[198] = "Scimitar";
    ships[199] = "Scorpion";
    ships[200] = "Scythe";
    ships[201] = "Scythe Fleet Issue";
    ships[202] = "Sentinel";
    ships[203] = "Sigil";
    ships[204] = "Silver Magnate";
    ships[205] = "Sin";
    ships[206] = "Skiff";
    ships[207] = "Slasher";
    ships[208] = "Sleipnir";
    ships[209] = "Stabber";
    ships[210] = "Stabber Fleet Issue";
    ships[211] = "Stiletto";
    ships[212] = "Stratios";
    ships[213] = "Succubus";
    ships[214] = "Svipul";
    ships[215] = "Talos";
    ships[216] = "Talwar";
    ships[217] = "Taranis";
    ships[218] = "Tempest";
    ships[219] = "Tempest Fleet Issue";
    ships[220] = "Tempest Tribal Issue";
    ships[221] = "Tengu";
    ships[222] = "Thanatos";
    ships[223] = "Thorax";
    ships[224] = "Thrasher";
    ships[225] = "Tormentor";
    ships[226] = "Tornado";
    ships[227] = "Tristan";
    ships[228] = "Typhoon";
    ships[229] = "Vagabond";
    ships[230] = "Vargur";
    ships[231] = "Velator";
    ships[232] = "Vengeance";
    ships[233] = "Vexor";
    ships[234] = "Vexor Navy Issue";
    ships[235] = "Viator";
    ships[236] = "Vigil";
    ships[237] = "Vigilant";
    ships[238] = "Vindicator";
    ships[239] = "Vulture";
    ships[240] = "Widow";
    ships[241] = "Wolf";
    ships[242] = "Worm";
    ships[243] = "Wreathe";
    ships[244] = "Wyvern";
    ships[245] = "Zealot";

    int l = strlen(str);

    if (l <= 1 || str[0] != '[') {
        return -1;
    }
    return binsearch(ships, 0, 245, str + 1);
}

void brtonl(char *str, int l) {
    for (int i = 0; i < l; i++) {
        if (str[i] == '<' && i < l - 3 && str[i+1] == 'b' && str[i+2] == 'r' && str[i+3] == '>') {
            str[i] = ' ';
            str[i+1] = ' ';
            str[i+2] = ' ';
            str[i+3] = '\n';
            i += 3;
        }
    }
}

static void sending_chat_msg(PurpleAccount *accout, char **message, int id) {
    if (iseft(*message) >= 0) {
        char *url_format_dna = "https://o.smium.org/api/convert/eft/dna/dna.txt?input=%s";
        char *url_format_loadout = "https://o.smium.org/loadout/dna/%s\n";
        char request[10000], dnabuffer[10000], buffer[10000] = {'\0'};

        memcpy(buffer, *message, strlen(*message));
        brtonl(buffer, strlen(buffer));
        char *output = curl_easy_escape(curl, buffer, 0);
        sprintf(request, url_format_dna, output);
        curl_free(output);

        curl_easy_setopt(curl, CURLOPT_URL, request);
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, USR_AGENT);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, dnabuffer);

        CURLcode ret = curl_easy_perform(curl);
        if (ret != CURLE_OK) {
            purple_debug_error(PLUGIN_ID, "curl_easy_perform() failed: %s\n",
                                curl_easy_strerror(ret));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                char *newmsg = calloc(strlen(url_format_loadout) + strlen(dnabuffer), sizeof(char));
                sprintf(newmsg, url_format_loadout, dnabuffer);
                free(*message);
                *message = newmsg;
            } else {
                purple_debug_warning(PLUGIN_ID, "Request failed: %s\n", dnabuffer);
            }

        }
    } 
}

static gboolean plugin_load(PurplePlugin *plugin) {
#ifdef NICKCHANGER
    // Add all of this as settings
    purple_signal_connect(purple_conversations_get_handle(), "chat-buddy-joined", 
            plugin, PURPLE_CALLBACK(chat_buddy_joined), NULL);
    purple_signal_connect(purple_conversations_get_handle(), "chat-buddy-left", 
            plugin, PURPLE_CALLBACK(chat_buddy_left), NULL);
#endif
    purple_signal_connect(purple_conversations_get_handle(), "sending-chat-msg", 
            plugin, PURPLE_CALLBACK(sending_chat_msg), NULL);

    test_plugin = plugin;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (!curl) {
        return FALSE;
    }

    purple_debug_warning(PLUGIN_ID, "test debug please ignore\n");

    return TRUE;
}

static gboolean plugin_unload(PurplePlugin *plugin) {
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return TRUE;
}

static PurplePluginInfo info = {
    PURPLE_PLUGIN_MAGIC,
    PURPLE_MAJOR_VERSION,
    PURPLE_MINOR_VERSION,
    PURPLE_PLUGIN_STANDARD,
    NULL,
    0,
    NULL,
    PURPLE_PRIORITY_DEFAULT,

    PLUGIN_ID,
    "TEST Plugin Please Ignore",
    "0.1",

    "Utilities for TEST jabber",          
    "(UKOC best KOC!)",          
    "Kurot Askulf",                          
    "",     
    
    plugin_load,                   
    plugin_unload,                          
    NULL,                          
                                   
    NULL,                          
    NULL,                          
    NULL,                        
    NULL,                   
    NULL,                          
    NULL,                          
    NULL,                          
    NULL                           
};                               
    
static void init_plugin(PurplePlugin *plugin) {
}

PURPLE_INIT_PLUGIN(hello_world, init_plugin, info)
