/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#pragma once

#include "ScriptMgr.h"
#include "Chat.h"

class GvgCommands : public CommandScript
{
public:
    GvgCommands();

    Acore::ChatCommands::ChatCommandTable GetCommands() const override;

    static bool HandleGvgReloadCommand(ChatHandler* handler);
    static bool HandleGvgRelationSetCommand(ChatHandler* handler, uint32 guildA, uint32 guildB, int8 relation);
    static bool HandleGvgRelationListCommand(ChatHandler* handler);
};

