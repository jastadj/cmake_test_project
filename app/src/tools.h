
#ifndef CD_TOOLS_H
#define CD_TOOLS_H

#include <string>
#include <vector>
#include <memory>

#include "dirent.h"

// convert any capital letters in a string to lower-case letters and return new string
std::string toLower(std::string str);

int toInt(std::string str);

// check if string contains a sub string
bool stringContains(std::string source, std::string substr);

// check if a string only contains digit characters 0-9
bool stringIsDigits(std::string str);

// separate a string into a list of strings
std::vector<std::string> split(std::string tstr, char delimiter = ' ', bool keep_empty = true);

// format and return a string in printf style ("%d", my_int)
// this is useful for supplying formatted strings to the logger
template<typename ... Args>
std::string formatString(const std::string& format, Args ... args)
{
	int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
	if (size_s <= 0) { throw "Error during formatting."; }
	auto size = static_cast<size_t>(size_s);
	std::unique_ptr<char[]> buf(new char[size]);
	std::snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
};

void setBit(unsigned char& byte, int pos, bool high);

std::vector<std::string> getFiles(std::string directory, std::string extension = "", bool add_path_to_output = false);
std::string getFilenameFromPathString(std::string filepath);

long long getUnixEpochTimestamp();

#endif // __TOOLS_H
