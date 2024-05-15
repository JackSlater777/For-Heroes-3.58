#pragma once
#include "era.h"



namespace EraJS
{
	inline bool isEmpty(const char* keyName) noexcept
	{
		return !strcmp(Era::tr(keyName), keyName);
	}


	inline int readInt(const char* keyName) noexcept
	{
		return atoi(Era::tr(keyName));
	}

	inline int readInt(const std::string& keyName) noexcept
	{
		return readInt(keyName.data());
	}

	inline int readInt(const char* keyName, bool& success) noexcept
	{
		char* result = Era::tr(keyName);
		success = strcmp(result, keyName);
		return atoi(result);
	}
	inline int readInt(const std::string& keyName, bool& success)  noexcept
	{
		return readInt(keyName.data(), success);
	}

	inline char* read(const char* keyName)
	{
		return Era::tr(keyName);
	}
	inline char* read(const char* keyName, bool& success)
	{
		char* result = Era::tr(keyName);
		success = strcmp(result, keyName);
		return result;
	}

	inline char* read(const std::string &keyName, bool& success)
	{
		return read(keyName.c_str(),success);
	}
	inline double readFloat(char* keyName, bool& success) noexcept
	{

		char* result = Era::tr(keyName);
		success = strcmp(result, keyName);
		return atof(result);

	}
	//inline int readFloat(char* keyName)
	//{
	//	if (isEmpty(keyName))
	//		return NAN;
	//	return atof(Era::tr(keyName));
	//}

}