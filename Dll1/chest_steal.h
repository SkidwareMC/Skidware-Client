#pragma once
#include "module.h"

namespace chest_steal {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;
	inline bool m_keep_open = false;
	inline bool m_random = false;
	inline long long m_clear_delay = 50L;

	static bool was_running = false;
	static std::shared_ptr<c_timer> timer = std::make_shared<c_timer>();
	static std::shared_ptr<std::vector<int>> idxsToLoop = std::make_shared<std::vector<int>>();

}

/*
- Check menu (ver se não está em um menu de bot, opcional)
- Keep open (deixar o baú aberto após limpar)
- RandomClear (pegar os itens em ordem aleatória)
- Clear delay
*/