/**
 *	Configuration File 
 *
 * A configuration file consists of key-value pairs separated by newlines. 
 * Keys are separated from values by an equals sign (=). All whitespace before the key, 
 * after the value and immediately adjacent to the equals sign is ignored. 
 * Keys and values may have whitespace characters within them. Keys do not need to be unique, 
 * but all but the last one are ignored.
 * 
 * The hash (#) character is used a comment when it is the first non-whitespace 
 * character on the line. All characters following that character are ignored 
 * to the end of the line. The hash character anywhere else on the line has 
 * no special significance.
 * 
 * Key-value pairs can be optionally grouped into sections, which are declared 
 * by surrounding a section name with square brackets ([ and ]) on a single line. 
 * Whitespace before the opening bracket is ignored. All characters after the 
 * trailing bracket are also ignored.
 * 
 * All key-value pairs that follow a section declaration belong to the last 
 * declared section. Key-value pairs that don't follow any section declarations 
 * belong to the global section. Sections do not nest.
 * 
 *	# comment
 *	[...]	//section
 *	x = v	//entry, x == key, v == value
 *
 */

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

#include <string>
#include <allegro5/allegro.h>

namespace engine {

class ConfigFile {
public:
	ConfigFile ();
	~ConfigFile ();

	bool			IsLoaded (void) const;
	bool			LoadFile (const std::string & path);
	const char *	GetFistSection (void);
	const char *	GetNextSection (void);
	const char *	GetValue (const char *section, const char *key);
	const char *	GetFistEntry (const char * section);
	const char *	GetNextEntry (void);

private:
	ALLEGRO_CONFIG *			file;
	ALLEGRO_CONFIG_ENTRY *		entry;
	ALLEGRO_CONFIG_SECTION *	section;
	
};

}	//namespace engine

#endif	//CONFIG_FILE_H