#pragma once

#include <dung/tokenizer.h>
#include <dung/sha1.h>

#include <string>
#include <vector>

namespace hatch
{
	struct Registry;
	struct RegistryAction;
}

namespace hatch
{
	typedef std::string String_t;

	class RegistryParser
	{
	public:
		RegistryParser();
		~RegistryParser();
	
		void Open( const char* text, size_t size );
		void Close();

		bool Parse( Registry& registry );

	private:
		bool ParseWordValue( String_t& value );
		bool ParseFile( Registry& registry, RegistryAction& action );
		bool SkipEndLines();

		dung::TextTokenizer m_tokenizer;
	};

	struct Registry
	{
		Registry();
		~Registry();

		String_t newVersion;
		String_t oldVersion;
		std::vector< RegistryAction* > actions;
	};

	struct RegistryAction
	{
		Sha1 newSha1, oldSha1;
		int newSize, oldSize;
	};
}
