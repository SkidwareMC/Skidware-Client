#ifndef CINTELLIGENTMAPPINGS_HPP_GUARD
#define CINTELLIGENTMAPPINGS_HPP_GUARD
#pragma once

#include "common.h"
#include "CCheat.hpp"

enum Version {
	ONE_TWELVE_TWO, ONE_EIGHT_NINE
};

typedef struct CIntelligentMappedField {
	CIntelligentMappedField(std::string unmappedName, std::string unmappedSignature, std::map<std::string, std::pair<std::string, std::string>> names, std::map<std::string, std::pair<std::string, std::string>> signatures) {
		this->_unmappedName = unmappedName;
		this->_unmappedSignature = unmappedSignature;
		this->_names = names;
		this->_signatures = signatures;
	}
	std::string name();
	std::string signature();
	std::string _unmappedName, _unmappedSignature;
	std::map<std::string, std::pair<std::string, std::string>> _names; //unmapped, pair<forge, vanilla>
	std::map<std::string, std::pair<std::string, std::string>> _signatures; //unmapped, pair<forge, vanilla>
} CIntelligentMappedField;

typedef struct CIntelligentMappedMethod {
	CIntelligentMappedMethod(std::string unmappedName, std::string unmappedSignature, std::map<std::string, std::pair<std::string, std::string>> names, std::map<std::string, std::pair<std::string, std::string>> signatures) {
		this->_unmappedName = unmappedName;
		this->_unmappedSignature = unmappedSignature;
		this->_names = names;
		this->_signatures = signatures;
	}
	std::string name();
	std::string signature();
	std::string _unmappedName, _unmappedSignature;
	std::map<std::string, std::pair<std::string, std::string>> _names; //unmapped, pair<forge, vanilla>
	std::map<std::string, std::pair<std::string, std::string>> _signatures; //unmapped, pair<forge, vanilla>
} CIntelligentMappedMethod;

typedef struct CIntelligentMappedClass {
	CIntelligentMappedClass(std::string unmappedName, std::map<std::string, std::pair<std::string, std::string>> names, std::vector<CIntelligentMappedField> fields, std::vector<CIntelligentMappedMethod> methods) {
		this->_unmappedName = unmappedName;
		this->_names = names;
		this->_fields = fields;
		this->_methods = methods;
	}
	std::string name();
	CIntelligentMappedField getField(std::string unmappedName) {
		for (CIntelligentMappedField field : this->_fields) {
			if (field._unmappedName._Equal(unmappedName)) return field;
		}
	}
	CIntelligentMappedMethod getMethod(std::string unmappedName) {
		for (CIntelligentMappedMethod method : this->_methods) {
			if (method._unmappedName._Equal(unmappedName)) return method;
		}
	}
	std::string _unmappedName;
	std::map<std::string, std::pair<std::string, std::string>> _names; //unmapped, pair<forge, vanilla>
	std::vector<CIntelligentMappedField> _fields;
	std::vector<CIntelligentMappedMethod> _methods;
} CIntelligentMappedClass;

typedef struct CIntelligentMappings {
	static void init(Version ver);
	static CIntelligentMappedClass getClass(std::string unmappedName) {
		for (CIntelligentMappedClass klass : _klasses) {
			if (klass._unmappedName._Equal(unmappedName)) {
				return klass;
			}
		}
	}
private:
	static CIntelligentMappedMethod make_method(std::string unmappedName, std::string unmappedSignature, std::string forgeName,
		std::string vanillaName, std::string forgeSignature, std::string vanillaSignature) {
		return CIntelligentMappedMethod{ unmappedName, unmappedSignature, make_map(unmappedName, forgeName, vanillaName),
			make_map(unmappedSignature, forgeSignature, vanillaSignature) };
	}
	static CIntelligentMappedField make_field(std::string unmappedName, std::string unmappedSignature, std::string forgeName,
		std::string vanillaName, std::string forgeSignature, std::string vanillaSignature) {
		return CIntelligentMappedField{ unmappedName, unmappedSignature, make_map(unmappedName, forgeName, vanillaName),
			make_map(unmappedSignature, forgeSignature, vanillaSignature) };
	}
	static CIntelligentMappedClass make_klass(std::string unmappedName, std::string forge, std::string vanilla, std::vector<CIntelligentMappedField> fields, std::vector<CIntelligentMappedMethod> methods) {
		return CIntelligentMappedClass{ unmappedName, make_map(unmappedName, forge, vanilla), fields, methods };
	}
	static std::map<std::string, std::pair<std::string, std::string>> make_map(std::string unmappedName, std::string forge, std::string vanilla) {
		return std::map({ std::make_pair(unmappedName, std::make_pair(forge, vanilla)) });
	}
	static std::vector<CIntelligentMappedClass> _klasses;
};

#endif //CINTELLIGENTMAPPINGS_HPP_GUARD
