#pragma once

#include "includes.h"
#include "player.h"
#include "world.h"
#include "machip.h"

class c_context 
{
public:
	std::shared_ptr<c_player> local;
	std::shared_ptr<c_world> world;
	bool ingame;

	c_context(std::shared_ptr<c_player> theplayer, std::shared_ptr<c_world> theworld, bool is_ingame)
	{
		local = theplayer;
		world = theworld;
		ingame = is_ingame;
	}
};

namespace modules
{
	class c_modules 
	{
	private:
		std::vector<std::function<void(std::shared_ptr<c_context>)>> mods;
		std::vector<std::function<void(std::shared_ptr<c_context>)>> mods_reset;
	public:
		~c_modules();

		void create(std::function<void(std::shared_ptr<c_context>)> m);
		void invoke(std::shared_ptr<c_context> ctx);

		void create_reset(std::function<void(std::shared_ptr<c_context>)> m);
		void reset(std::shared_ptr<c_context> ctx);

	};
	inline std::unique_ptr<c_modules> instance = nullptr;
}