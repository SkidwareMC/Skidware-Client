#include "../headers/velocity.h"

void velocity::invoke(std::shared_ptr<c_context> ctx)
{
	if (ctx->local->get_hurt_time() <= 5) {
		sdk::vec3d x;
		x.x = (double)velocity::m_horizontal/100;
		x.y = (double)velocity::m_vertical/100;
		x.z = (double)velocity::m_horizontal/100;
		ctx->local->set_motion_vector(x);
	}
}
