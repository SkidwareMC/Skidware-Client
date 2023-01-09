#ifndef CMETHOD_HPP_GUARD
#define CMETHOD_HPP_GUARD
#pragma once

#include "common.h"

// Created with ReClass.NET 1.2 by KN4CK3R

class CConstMethod {
public:
	unsigned long _fingerprint;
	class CConstantPool* _constants;
	CArray<unsigned char>* _stackmap_data;
	int _constMethod_size;
	unsigned short _flags;
	unsigned char _result_type;
	unsigned short _code_size;
	unsigned short _name_index;
	unsigned short _signature_index;
};

class CMethod {
public:
	char pad_0000[8]; //0x0000
	class CConstMethod* _constMethod; //0x0008
	char pad_0010[16]; //0x0010
	uint32_t _flags; //0x0020
	char pad_0024[12]; //0x0024
	unsigned char* _i2i_entry; //0x0030
	char pad_0038[8]; //0x0038
	unsigned char* _from_compiled_entry; //0x0040	
	char pad_0048[8]; //0x0048
	unsigned char* _from_interpreted_entry; //0x0050
	char pad_0058[40]; //0x0058
   
	void setNative() {
		this->_flags |= 0xe000100;
	}
}; //Size: 0x0068

#endif //CMETHOD_HPP_GUARD
