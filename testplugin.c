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
#define USR_AGENT "TESTPidginPlugin/0.1 (+https://github.com/mrkurot/testplugin)"

#define CHAT_NAME "ukoc@chat.pleaseignore.com"
#define BITTERVET_NAME "Khuros Khan"
#define NEWBRO_NAME "Kurot Askulf"
#define NEWBRO_ALT "Kurot 'Carrot' Askulf"

#define NSHIPS 250

static PurplePlugin *test_plugin = NULL;
static CURL *curl = NULL;

static void chat_buddy_joined(PurpleConversation *conv, const char *name,
                          PurpleConvChatBuddyFlags flags,
                          gboolean new_arrival) {
    if (!strcmp(conv->name, CHAT_NAME) && \
            !strcmp(name, BITTERVET_NAME)) {
        purple_debug_info(PLUGIN_ID, "Changing nick to %s\n", NEWBRO_ALT);
        gchar *error;
        PurpleCmdStatus status = purple_cmd_do_command(conv, "nick " NEWBRO_ALT, "", &error);
        g_free(error);
        purple_debug_info(PLUGIN_ID, "Executed %d\n", status);
    }
}

static void chat_buddy_left(PurpleConversation *conv, const char *name,
                          PurpleConvChatBuddyFlags flags,
                          gboolean new_arrival) {
    purple_debug_info(PLUGIN_ID, "Changing nick to %s\n", NEWBRO_NAME);
    if (!strcmp(conv->name, CHAT_NAME) && \
            !strcmp(name, BITTERVET_NAME)) {
        gchar *error;
        PurpleCmdStatus status = purple_cmd_do_command(conv, "nick " NEWBRO_NAME, "", &error);
        g_free(error);
        purple_debug_info(PLUGIN_ID, "Executed %d\n", status);
    }
}

int compare_str(const void *a, const void *b) {
    char *aa, *bb;
    aa = (char *)a;
    bb = *((char **)b);

    return strncmp(aa, bb, strlen(bb));
}

int iseft(char *str) {
    char *ships[NSHIPS];

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
    ships[29] = "Bifrost";
    ships[30] = "Blackbird";
    ships[31] = "Breacher";
    ships[32] = "Broadsword";
    ships[33] = "Brutix";
    ships[34] = "Burst";
    ships[35] = "Bustard";
    ships[36] = "Buzzard";
    ships[37] = "Caldari Navy Hookbill";
    ships[38] = "Caracal";
    ships[39] = "Catalyst";
    ships[40] = "Celestis";
    ships[41] = "Cerberus";
    ships[42] = "Chameleon";
    ships[43] = "Cheetah";
    ships[44] = "Chimera";
    ships[45] = "Claw";
    ships[46] = "Claymore";
    ships[47] = "Coercer";
    ships[48] = "Condor";
    ships[49] = "Confessor";
    ships[50] = "Corax";
    ships[51] = "Cormorant";
    ships[52] = "Covetor";
    ships[53] = "Crane";
    ships[54] = "Crow";
    ships[55] = "Crucifier";
    ships[56] = "Cruor";
    ships[57] = "Crusader";
    ships[58] = "Curse";
    ships[59] = "Cyclone";
    ships[60] = "Cynabal";
    ships[61] = "Damnation";
    ships[62] = "Daredevil";
    ships[63] = "Deimos";
    ships[64] = "Devoter";
    ships[65] = "Dominix";
    ships[66] = "Dragoon";
    ships[67] = "Drake";
    ships[68] = "Dramiel";
    ships[69] = "Eagle";
    ships[70] = "Enyo";
    ships[71] = "Eos";
    ships[72] = "Erebus";
    ships[73] = "Eris";
    ships[74] = "Executioner";
    ships[75] = "Exequror";
    ships[76] = "Exequror Navy Issue";
    ships[77] = "Falcon";
    ships[78] = "Ferox";
    ships[79] = "Flycatcher";
    ships[80] = "Federation Navy Comet";
    ships[81] = "Garmur";
    ships[82] = "Gila";
    ships[83] = "Gnosis";
    ships[84] = "Gold Magnate";
    ships[85] = "Golem";
    ships[86] = "Goru's Shuttle";
    ships[87] = "Griffin";
    ships[88] = "Guardian";
    ships[89] = "Guardian-Vexor";
    ships[90] = "Guristas Shuttle";
    ships[91] = "Harbinger";
    ships[92] = "Harpy";
    ships[93] = "Hawk";
    ships[94] = "Hecate";
    ships[95] = "Hel";
    ships[96] = "Helios";
    ships[97] = "Heretic";
    ships[98] = "Heron";
    ships[99] = "Hoarder";
    ships[100] = "Hound";
    ships[101] = "Huginn";
    ships[102] = "Hulk";
    ships[103] = "Hurricane";
    ships[104] = "Hyena";
    ships[105] = "Hyperion";
    ships[106] = "Ibis";
    ships[107] = "Imicus";
    ships[108] = "Impairor";
    ships[109] = "Impel";
    ships[110] = "Imperial Navy Slicer";
    ships[111] = "Incursus";
    ships[112] = "Inquisitor";
    ships[113] = "Ishkur";
    ships[114] = "Ishtar";
    ships[115] = "Iteron Mark V";
    ships[116] = "Jaguar";
    ships[117] = "Jackdaw";
    ships[118] = "Keres";
    ships[119] = "Kestrel";
    ships[120] = "Kitsune";
    ships[121] = "Kronos";
    ships[122] = "Lachesis";
    ships[123] = "Legion";
    ships[124] = "Leviathan";
    ships[125] = "Loki";
    ships[126] = "Machariel";
    ships[127] = "Mackinaw";
    ships[128] = "Maelstrom";
    ships[129] = "Magnate";
    ships[130] = "Magus";
    ships[131] = "Malediction";
    ships[132] = "Maller";
    ships[133] = "Mammoth";
    ships[134] = "Manticore";
    ships[135] = "Mastodon";
    ships[136] = "Maulus";
    ships[137] = "Megathron";
    ships[138] = "Megathron Federate Issue";
    ships[139] = "Megathron Navy Issue";
    ships[140] = "Merlin";
    ships[141] = "Moa";
    ships[142] = "Moros";
    ships[143] = "Muninn";
    ships[144] = "Myrmidon";
    ships[145] = "Naga";
    ships[146] = "Naglfar";
    ships[147] = "Navitas";
    ships[148] = "Nemesis";
    ships[149] = "Nereus";
    ships[150] = "Nidhoggur";
    ships[151] = "Nighthawk";
    ships[152] = "Nightmare";
    ships[153] = "Nomad";
    ships[154] = "Nyx";
    ships[155] = "Occator";
    ships[156] = "Omen";
    ships[157] = "Omen Navy Issue";
    ships[158] = "Oneiros";
    ships[159] = "Onyx";
    ships[160] = "Oracle";
    ships[161] = "Orca";
    ships[162] = "Osprey";
    ships[163] = "Osprey Navy Issue";
    ships[164] = "Paladin";
    ships[165] = "Panther";
    ships[166] = "Phantasm";
    ships[167] = "Phobos";
    ships[168] = "Phoenix";
    ships[169] = "Pilgrim";
    ships[170] = "Pontifex";
    ships[171] = "Prorator";
    ships[172] = "Probe";
    ships[173] = "Procurer";
    ships[174] = "Prophecy";
    ships[175] = "Prospect";
    ships[176] = "Proteus";
    ships[177] = "Prowler";
    ships[178] = "Punisher";
    ships[179] = "Purifier";
    ships[180] = "Ragnarok";
    ships[181] = "Rapier";
    ships[182] = "Raptor";
    ships[183] = "Rattlesnake";
    ships[184] = "Raven";
    ships[185] = "Raven Navy Issue";
    ships[186] = "Raven State Issue";
    ships[187] = "Reaper";
    ships[188] = "Redeemer";
    ships[189] = "Republic Fleet Firetail";
    ships[190] = "Retribution";
    ships[191] = "Retriever";
    ships[192] = "Revelation";
    ships[193] = "Rhea";
    ships[194] = "Rifter";
    ships[195] = "Rokh";
    ships[196] = "Rook";
    ships[197] = "Rorqual";
    ships[198] = "Rupture";
    ships[199] = "Sabre";
    ships[200] = "Sacrilege";
    ships[201] = "Scimitar";
    ships[202] = "Scorpion";
    ships[203] = "Scythe";
    ships[204] = "Scythe Fleet Issue";
    ships[205] = "Sentinel";
    ships[206] = "Sigil";
    ships[207] = "Silver Magnate";
    ships[208] = "Sin";
    ships[209] = "Skiff";
    ships[210] = "Slasher";
    ships[211] = "Sleipnir";
    ships[212] = "Stabber";
    ships[213] = "Stabber Fleet Issue";
    ships[214] = "Stiletto";
    shipw[215] = "Stork";
    ships[216] = "Stratios";
    ships[217] = "Succubus";
    ships[218] = "Svipul";
    ships[219] = "Talos";
    ships[220] = "Talwar";
    ships[221] = "Taranis";
    ships[222] = "Tempest";
    ships[223] = "Tempest Fleet Issue";
    ships[224] = "Tempest Tribal Issue";
    ships[225] = "Tengu";
    ships[226] = "Thanatos";
    ships[227] = "Thorax";
    ships[228] = "Thrasher";
    ships[229] = "Tormentor";
    ships[230] = "Tornado";
    ships[231] = "Tristan";
    ships[232] = "Typhoon";
    ships[233] = "Vagabond";
    ships[234] = "Vargur";
    ships[235] = "Velator";
    ships[236] = "Vengeance";
    ships[237] = "Vexor";
    ships[238] = "Vexor Navy Issue";
    ships[239] = "Viator";
    ships[240] = "Vigil";
    ships[241] = "Vigilant";
    ships[242] = "Vindicator";
    ships[243] = "Vulture";
    ships[244] = "Widow";
    ships[245] = "Wolf";
    ships[246] = "Worm";
    ships[247] = "Wreathe";
    ships[248] = "Wyvern";
    ships[249] = "Zealot";

    int l = strlen(str);

    if (l <= 1 || str[0] != '[') {
        return -1;
    }
    char **ship = bsearch(str + 1, ships, NSHIPS, sizeof(char *), compare_str);
    if (ship != NULL) {
        return ship - ships;
    } else {
        return -1;
    }
}

/* Substitutes in place '<br>' by '   \n' */
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

size_t writefunc(void *ptr, size_t size, size_t nmemb, char **output) {
    *output = (char *)calloc(nmemb + 1, size);
    memcpy(*output, ptr, size * nmemb);
    (*output)[size*nmemb] = '\0';

    return size*nmemb;
}

static void sending_chat_msg(PurpleAccount *accout, char **message, int id) {
    if (iseft(*message) >= 0) {
        purple_debug_warning(PLUGIN_ID, "EFT message detected\n");

        char *url_format_dna = "http://o.smium.org/api/convert/eft/dna/dna.txt?input=%s";
        char *url_format_loadout = "https://o.smium.org/loadout/dna/%s";
        char *request, *dnabuffer, *buffer;

        buffer = (char *)calloc(strlen(*message) + 1, sizeof(char));
        memcpy(buffer, *message, strlen(*message));
        brtonl(buffer, strlen(buffer));
        char *output = curl_easy_escape(curl, buffer, 0);

        request = (char *)calloc(strlen(url_format_dna) + strlen(output) + 1, sizeof(char));
        sprintf(request, url_format_dna, output);

        curl_easy_setopt(curl, CURLOPT_URL, request);
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, USR_AGENT);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &dnabuffer);

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

        curl_free(output);
        free(buffer);
        free(dnabuffer);
        free(request);
    } else {
        //purple_debug_warning(PLUGIN_ID, "Normal message: %s\n", *message);
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

    purple_debug_info(PLUGIN_ID, "TEST plugin loaded, please ignore\n");

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
    "Transforms an EFT formatted fit into an o.smium.org link\n"
        "Contact: https://github.com/mrkurot/testplugin\n\n"
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
