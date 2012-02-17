#include "Film.h"

namespace engine {

	
Film::Film (
	const std::string & id_, 
	const std::string & bitmapPath_, 
	const std::string & bboxesPath_) 
:	id(id_),
	bitmapPath(bitmapPath_),
	bbxoesPath(bboxesPath_)
{}

	
}