#pragma once

#include "LivePP/API/x64/LPP_API_x64_CPP.h"

#include "ofMain.h"

class ofxLivePP {
public:
    static lpp::LppDefaultAgent lppAgent;

    static bool setup(bool use_as_local_addon=false){
        std::string LivePP_Path =
            (use_as_local_addon)?
            ofToDataPath("../../addons/ofxLivePP/libs/LivePP/LivePP", true)
            :ofToDataPath("../../../../../addons/ofxLivePP/libs/LivePP/LivePP", true);
        ofLog() << "LivePP Path: " << LivePP_Path;

        std::wstring LivePP_Path_w = std::wstring(LivePP_Path.begin(), LivePP_Path.end());

        // create a default agent, loading the Live++ agent from the given path, e.g. "ThirdParty/LivePP"
        lppAgent = lpp::LppCreateDefaultAgent(nullptr, LivePP_Path_w.c_str());

        // bail out in case the agent is not valid
        if (!lpp::LppIsValidDefaultAgent(&lppAgent))
        {
            return false;
        }

        // enable Live++ for all loaded modules
        lppAgent.EnableModule(lpp::LppGetCurrentModulePath(), lpp::LPP_MODULES_OPTION_ALL_IMPORT_MODULES, nullptr, nullptr);
    }

    static void destroy(){
        // destroy the Live++ agent
        lpp::LppDestroyDefaultAgent(&lppAgent);
    }

protected:
};