/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "GvgCommands.h"
#include "GvgCore.h"
#include "Chat.h"
#include "Player.h"
#include "Log.h"

using namespace Acore::ChatCommands;

GvgCommands::GvgCommands() : CommandScript("GvgCommands")
{
}

// FIXED: Use static ChatCommandTable with initializer lists
ChatCommandTable GvgCommands::GetCommands() const
{
    static ChatCommandTable relationSubCommands =
    {
        { "set",  HandleGvgRelationSetCommand,  SEC_ADMINISTRATOR, Console::No },
        { "list", HandleGvgRelationListCommand, SEC_GAMEMASTER,    Console::No }
    };

    static ChatCommandTable gvgSubCommands =
    {
        { "reload",   HandleGvgReloadCommand, SEC_GAMEMASTER, Console::No },
        { "relation", relationSubCommands }
    };

    static ChatCommandTable commandTable =
    {
        { "gvg", gvgSubCommands }
    };

    return commandTable;
}

bool GvgCommands::HandleGvgReloadCommand(ChatHandler* handler)
{
    GvgCore::Instance().LoadRelationsFromDB();
    handler->SendSysMessage("[mod-gvg-core] Reloaded relations from DB.");
    return true;
}

bool GvgCommands::HandleGvgRelationSetCommand(ChatHandler* handler, uint32 guildA, uint32 guildB, int8 relation)
{
    GvgCore::Instance().SetGuildRelation(guildA, guildB, relation);
    handler->PSendSysMessage("Guild relation set between {} and {} to {}.", guildA, guildB, (int)relation);
    return true;
}

bool GvgCommands::HandleGvgRelationListCommand(ChatHandler* handler)
{
    handler->SendSysMessage("Relations listing: (use SQL for full view)");
    handler->SendSysMessage("Use DB query: SELECT * FROM gvg_guild_relations");
    return true;
}

// Add all command scripts
void AddGvgCommandScripts()
{
    new GvgCommands();
}

