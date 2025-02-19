//////////////////////////////////////////
//
//  Copyright (C) 2023 Tracklab, Inc.
//

#include "tools.h"
#include <chrono>

// convert any capital letters in a string to lower-case letters and return new string
std::string toLower(std::string str)
{
	for (auto it = str.begin(); it != str.end(); it++)
	{
		char ch = *it;
		if (ch >= 'A' && ch <= 'Z') *it = 'a' + (*it - 'A');
	}
	return str;
};

int toInt(std::string tstr)
{
    int val = 0;
    tstr = toLower(tstr);

    // Hex formatted string?
    if (tstr.find("0x") == 0)
    {
        tstr = tstr.substr(2);
        sscanf_s(tstr.c_str(), "%x", &val);
    }
    // Otherwise convert string to int
    else
    {
        val = atoi(tstr.c_str());
    }
    return val;
}

bool stringContains(std::string source, std::string substr)
{
	return (source.find(substr) != std::string::npos);
}

bool stringIsDigits(std::string str)
{
    const int ch_0 = int(char('0'));
    const int ch_9 = int(char('9'));

    for (auto& ch : str)
    {
        if (int(ch) < ch_0 || int(ch) > ch_9)
            return false;
    }
    return true;
}

std::vector<std::string> split(std::string str, char delimiter, bool keep_empty)
{
	std::vector<std::string> words;
	size_t pos = str.find_first_of(delimiter);

	if (str.empty()) return words;

	while (pos != std::string::npos)
	{
        std::string word_str = str.substr(0, pos);

        // Keep empty?
        if ( word_str.empty() && !keep_empty)
        {
            words.push_back(word_str);
        }
        else
        {
            words.push_back(word_str);
        }
		
		str.erase(0, pos + 1);
		pos = str.find_first_of(delimiter);
	}
	words.push_back(str);
	return words;
}

void setBit(unsigned char& byte, int pos, bool high)
{
	if (pos >= 0 && pos < 8)
	{
		if (high)
		{
			if (!(byte & (0x1 << pos)))
				byte ^= 0x1 << pos;
		}
		else
		{
			if (byte & (0x1 << pos))
				byte ^= 0x1 << pos;
		}
	}
}

std::vector<std::string> getFiles(std::string directory, std::string extension, bool add_path_to_output)
{
    // File list
    std::vector<std::string> file_list;

    // Create directory pointer and directory entry
    DIR* dir;
    struct dirent* ent;
    struct stat st;

    if (!directory.empty())
    {
        if(directory.back() != '/' && directory.back() != '\\')
            directory.push_back('/');
    }
    

    // Open directory
    if ((dir = opendir(directory.c_str())) != NULL)
    {
        // Check each file in directory
        while ((ent = readdir(dir)) != NULL)
        {
            // Get filename
            std::string filename(ent->d_name);

            // Is directory?
            stat(std::string(directory + filename).c_str(), &st);
            if (!S_ISDIR(st.st_mode))
            {
                // If an extension is defined
                if (extension != "")
                {
                    // Get the extension
                    size_t trim = filename.find_last_of('.');
                    if(trim != std::string::npos)
                    {
                        std::string target_extension = filename.substr(trim);

                        if (target_extension == extension)
                            file_list.push_back(filename);
                    }
                }
                // Otherwise add the filename to the list
                else file_list.push_back(filename);
            }
        }
        closedir(dir);
    }

    if (add_path_to_output)
    {
        for (auto& filename : file_list)
        {
            filename = directory + filename;
        }
    }

    return file_list;
}

std::string getFilenameFromPathString(std::string filepath)
{
    std::size_t end_of_path_pos = filepath.find_last_of('/');
    if (end_of_path_pos == std::string::npos)
        end_of_path_pos = filepath.find_last_of('\\');
    
    if (end_of_path_pos == std::string::npos)
        return filepath;

    return filepath.substr(end_of_path_pos + 1);
}

long long getUnixEpochTimestamp()
{
    auto current_time = std::chrono::system_clock::now();
    auto duration = current_time.time_since_epoch();
    const long long epoch_time = std::chrono::duration_cast<std::chrono::seconds>(duration).count();

    return epoch_time;
}