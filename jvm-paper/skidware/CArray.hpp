#ifndef CARRAY_HPP_GUARD
#define CARRAY_HPP_GUARD
#pragma once

template<class T> struct CArray {
	int _length;
	T _data[1];
	T at(int idx) const {
		return _data[idx];
	}
};

#endif //CARRAY_HPP_GUARD
