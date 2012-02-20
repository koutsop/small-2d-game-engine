#ifndef UTILITY_H
#define UTILITY_H

#include <typeinfo>

namespace engine {



template <typename T>
const char* typeof (const & T) 
	{ return std::typeid(T).name(); }



}	//namespace engine


#endif	//UTILITY_H