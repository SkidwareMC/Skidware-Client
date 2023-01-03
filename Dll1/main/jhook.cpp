#include "jhook.h"
#include "machip.h"
#include "minecraft.h"
#include "player.h"
#include "world.h"
#include "scaffold.h"

typedef void(__cdecl* runTick) (void**, void**);

runTick pRunTick;
runTick pRunTickTarget;

void __cdecl tickHook(void** p1, void** p2) {
    sdk::instance->hasTick = true;
    return pRunTick(p1, p2);
}

void machip::hooks::jhooks::rehook_tick() {
    wrapper::output("rehook!");
    if (MH_DisableHook(reinterpret_cast<void**>(pRunTickTarget)) != MH_OK) {
        wrapper::output("failed to rehook onTick hook");
        return;
    }
    apply_jtickhook(false);
}

bool  machip::hooks::jhooks::apply_jtickhook(bool create) {
    jclass mc_class = machip::instance->get_env()->FindClass("ave");
    jmethodID method = machip::instance->get_env()->GetMethodID(mc_class, "s", "()V");
    pRunTickTarget = reinterpret_cast<runTick>(*(unsigned __int64*)(*(unsigned __int64*)method + 0x40));

    if (create)
    {
        MH_STATUS status = MH_CreateHook(reinterpret_cast<void**>(pRunTickTarget), &tickHook, reinterpret_cast<void**>(&pRunTick));
        if (status != MH_OK) {
            wrapper::output("failed to hook onTick");
            wrapper::output(MH_StatusToString(status));
            return false;
        }
    }
    

    if (MH_EnableHook(reinterpret_cast<void**>(pRunTickTarget)) != MH_OK) {
        wrapper::output("failed to enable onTick hook");
        return false;
    }

    machip::instance->get_env()->DeleteLocalRef(mc_class);

    wrapper::output("onTick hooked");

    return true;
}

typedef void(__cdecl* mvEntity) (double, double, double);

mvEntity pMoveEntity;
mvEntity pMoveEntityarget;

void __cdecl pmvEntity(double x, double y, double z) {
    if (sdk::instance->blockMovement)
    {
        sdk::instance->blockMovement = false;
        return pMoveEntity(sdk::instance->mx, y, sdk::instance->mz);
    }
    
    return pMoveEntity(x, y, z);
}

bool machip::hooks::jhooks::apply_moveEntityHook() {
    jclass player_class = machip::instance->get_env()->FindClass("wn");
    jmethodID method = machip::instance->get_env()->GetMethodID(player_class, "d", "(DDD)V");
    pMoveEntityarget = reinterpret_cast<mvEntity>(*(unsigned __int64*)(*(unsigned __int64*)method + 0x40));

    MH_STATUS status = MH_CreateHook(reinterpret_cast<void**>(pMoveEntityarget), &pmvEntity, reinterpret_cast<void**>(&pMoveEntity));
    if (status != MH_OK) {
        wrapper::output("failed to hook moveEntity");
        wrapper::output(MH_StatusToString(status));
        return false;
    }

    if (MH_EnableHook(reinterpret_cast<void**>(pMoveEntityarget)) != MH_OK) {
        wrapper::output("failed to enable moveEntity hook");
        return false;
    }

    machip::instance->get_env()->DeleteLocalRef(player_class);

    wrapper::output("moveEntity hooked");

    return true;
}

typedef float(__cdecl* gtreach) (void**, void**);

gtreach pGetReach;
gtreach pGetReachTarget;

int i = 0;

float __cdecl gtReach(void** p1, void** p2) {
    wrapper::output("gtreach");
    if (scaffold::m_enabled)
        return 5.0f;
    return pGetReach(p1, p2);
}

bool  machip::hooks::jhooks::apply_jreachhook() {
    jclass mc_class = machip::instance->get_env()->FindClass("bda");
    jmethodID method = machip::instance->get_env()->GetMethodID(mc_class, "d", "()F");
    pGetReachTarget = reinterpret_cast<gtreach>(*(unsigned __int64*)(*(unsigned __int64*)method + 0x45));

    MH_STATUS status = MH_CreateHook(reinterpret_cast<void**>(pGetReachTarget), &gtReach, reinterpret_cast<void**>(&pGetReach));
    if (status != MH_OK) {
        wrapper::output("failed to hook getReach");
        wrapper::output(MH_StatusToString(status));
        return false;
    }

    if (MH_EnableHook(reinterpret_cast<void**>(pGetReachTarget)) != MH_OK) {
        wrapper::output("failed to enable getReach hook");
        return false;
    }

    machip::instance->get_env()->DeleteLocalRef(mc_class);

    wrapper::output("getReach hooked");

    return true;
}
