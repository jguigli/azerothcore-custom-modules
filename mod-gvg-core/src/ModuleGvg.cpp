/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "GvgCore.h"
#include "Config.h"
#include "Log.h"

// Module initialization script
class GvgCoreWorldScript : public WorldScript
{
public:
    GvgCoreWorldScript() : WorldScript("GvgCoreWorldScript") { }

    void OnStartup() override
    {
        if (sConfigMgr->GetOption<bool>("GvgCore.Enable", true))
        {
            LOG_INFO("module", ">> Loading mod-gvg-core...");
            GvgCore::Instance().LoadRelationsFromDB();
            LOG_INFO("module", ">> mod-gvg-core loaded.");
        }
        else
        {
            LOG_INFO("module", ">> mod-gvg-core is disabled in config.");
        }
    }

    void OnShutdown() override
    {
        if (sConfigMgr->GetOption<bool>("GvgCore.Enable", true))
        {
            LOG_INFO("module", ">> Saving GvG data...");
            GvgCore::Instance().SaveRelationsToDB();
            LOG_INFO("module", ">> mod-gvg-core unloaded.");
        }
    }
};

// Add all core scripts
void AddGvgCoreScripts()
{
    new GvgCoreWorldScript();
}

