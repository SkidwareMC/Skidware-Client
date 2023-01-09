#ifndef CCONSTANTPOOL_HPP_GUARD
#define CCONSTANTPOOL_HPP_GUARD
#pragma once

#include "CArray.hpp"
#include "common.h"

typedef struct CConstantPool {
	char pad_0000[8];
	CArray<unsigned char>* _tags;
	class ConstantPoolCache* _constantPoolCache;
	class CInstanceKlass* _pool_holder;
	CArray<unsigned short>* _operands;
	jobject _resolved_references;
	CArray<unsigned short>* _reference_map;
	enum {
		_has_presolution = 1,
		_on_stack = 2
	};
	int _flags;
	int _length;
	union {
		int _resolved_reference_length;
		int _version;
	} _saved;
	jobject _lock;

	intptr_t* base() const {
		return (intptr_t*)(((char*)this) + sizeof(CConstantPool));
	}

	CSymbol** symbol_at_addr(int idx) const {
		return (CSymbol**)&base()[idx];
	}

	CSymbol* symbol_at(int idx) const {
		return *symbol_at_addr(idx);
	}
};

#endif //CCONSTANTPOOL_HPP_GUARD
