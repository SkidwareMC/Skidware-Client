#include "../headers/fly.h"
#include "../../../../sdk/minecraft/player/player.h"

void fly::invoke(std::shared_ptr<c_context> ctx)
{
    if (fly::m_enabled)
    {
        ctx->local->setFlying(true);
    }
}