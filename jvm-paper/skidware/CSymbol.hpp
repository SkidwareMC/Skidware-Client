#ifndef CSYMBOL_HPP_GUARD
#define CSYMBOL_HPP_GUARD
#pragma once

typedef struct CSymbol {
	short _length;
	short _identity;
	char pad_0004[4];
	char _body[1];

	std::string as_C_string() {
		if (!_body) return "";

		return std::string(_body, _length);
	}
};

#endif //CSYMBOL_HPP_GUARD
