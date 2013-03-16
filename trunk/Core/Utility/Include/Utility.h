#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <typeinfo>
#include <sstream>
#include <iostream>
#include <functional>

namespace engine {

//-------------------------------------------------------------------------------------------

static bool StringToBool (const std::string& s)
	{ return s == "true" ? true : false; }

//-------------------------------------------------------------------------------------------

template <typename T>
const char* typeof (const T& t) 
	{ return std::typeid(t).name(); }

//-------------------------------------------------------------------------------------------

template <typename T>
std::string string_cast(const T & a){
	std::ostringstream os;
	os<<a;
	return os.str();
}

//-------------------------------------------------------------------------------------------

struct RetrieveKey {
    template <typename T>
	typename T::first_type operator()(T & keyValuePair) const
		{ return keyValuePair.first; }
};

//-------------------------------------------------------------------------------------------

struct RetrieveValue {
    template <typename T>
	typename T::second_type operator()(T & keyValuePair) const
		{ return keyValuePair.second; }
};


}	//namespace engine


#endif	//UTILITY_H