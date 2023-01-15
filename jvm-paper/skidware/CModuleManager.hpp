#ifndef CMODULEMANAGER_HPP_GUARD
#define CMODULEMANAGER_HPP_GUARD
#pragma once

#include "common.h"
#include "CModule.hpp"

typedef struct CModuleManager {
	void registerModule(CModule* module) {
		this->modules.push_back(module);
	}

	void registerModules();

	template<class T> T* getModule() {
		for (CModule* module : this->modules) {
			if (auto m = dynamic_cast<typename std::remove_pointer<T>::type*>(module)) {
				return m;
			}
		}

		return nullptr;
	}

	std::vector<CModule*> modules;
};

#endif //CMODULEMANAGER_HPP_GUARD
