#include "../headers/sprint.h"
#include "../../../../sdk/minecraft/player/player.h"

void sprint::invoke(std::shared_ptr<c_context> ctx)
{
    if (sprint::m_enabled)
    {
        ctx->local->setSprint(true);
    }
}