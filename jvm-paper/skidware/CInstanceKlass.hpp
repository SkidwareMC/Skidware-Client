#ifndef CINSTANCEKLASS_HPP_GUARD
#define CINSTANCEKLASS_HPP_GUARD
#pragma once

#include "CArray.hpp"
#include "CMethod.hpp"
#include "CConstantPool.hpp"

typedef struct CInstanceKlass {
	char pad_0000[16];
	class CSymbol* _name;
	char pad_0018[200];
	class CConstantPool* _constant_pool;
	char pad_00E0[160];
    CArray<CMethod*>* _methods;
};

#endif //CINSTANCEKLASS_HPP_GUARD
