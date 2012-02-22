#include <assert.h>
#include "ConfigFile.h"

namespace engine {

//-----------------------------------------------------------------------

ConfigFile::ConfigFile ()
:	file	((ALLEGRO_CONFIG*)0),
	entry	((ALLEGRO_CONFIG_ENTRY*)0),
	section	((ALLEGRO_CONFIG_SECTION*)0)
{}

//-----------------------------------------------------------------------

ConfigFile::~ConfigFile () { 
	if (file)
		al_destroy_config(file); 
}

//-----------------------------------------------------------------------

bool ConfigFile::LoadFile (const std::string & path) 
	{ return file = al_load_config_file(path.c_str()); }

//-----------------------------------------------------------------------

const char * ConfigFile::GetFistSection (void) {
	assert(file);
	return al_get_first_config_section(file, &section);
}

//-----------------------------------------------------------------------

const char * ConfigFile::GetNextSection (void) {
	assert(section);
	return al_get_next_config_section(&section);
}

//-----------------------------------------------------------------------

const char * ConfigFile::GetValue (const char *section, const char *key) {
	assert(file && section && key);
	return al_get_config_value(file, section, key);
}

//-----------------------------------------------------------------------

const char * ConfigFile::GetFistEntry (const char * section) {
	assert(file && section);
	return al_get_first_config_entry(file, section, &entry);
}

//-----------------------------------------------------------------------

const char * ConfigFile::GetNextEntry (void) {
	assert(entry);
	return al_get_next_config_entry(&entry);
}

}	//namespace engine