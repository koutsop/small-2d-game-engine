#ifndef GRAPHICS_COMMON_H
#define GRAPHICS_COMMON_H

#include <stdlib.h>
#include <iostream>

namespace engine {
	#define CHECK_ALLEGRO_COMPONENT(COMPONENT)		\
		if (!COMPONENT) {							\
			std::cerr	<< "Failed to initialize: " \
						<< #COMPONENT				\
						<< std::endl;				\
			std::abort();							\
		} else
}

#endif	//GRAPHICS_COMMON_H