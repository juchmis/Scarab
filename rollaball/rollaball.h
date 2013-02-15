#pragma once

#include <dung/dung.h>

#include <string>
#include <vector>

namespace rab
{
	typedef std::wstring String_t;
	typedef std::vector< String_t > ConfigValues_t;

	struct Options
	{
		String_t pathToNew, pathToOld, pathToTemp;
		String_t newVersion, oldVersion;
		String_t configFile;
	};

	struct Config
	{
		ConfigValues_t dst_folders;
		ConfigValues_t dst_files;
		ConfigValues_t dst_ignore_folders;
		ConfigValues_t dst_ignore_files;
		ConfigValues_t pack_files_using;
		ConfigValues_t dst_ignore_changed;
		ConfigValues_t dst_preserve_removed;
		ConfigValues_t src_ignore_files;
		int src_file_limit;
		String_t packedExtension;
	};

	void ProcessData( Options const &options, Config const &config );
};

