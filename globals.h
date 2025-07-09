#pragma once

struct Point
{
	int x;
	int y;
};

struct Rect
{
	int x, y;
	int w, h;
};

int ReadIntFromIni(const std::string& section, const std::string& key, int defaultValue, const std::string& iniPath)
{
    char buffer[64];
    GetPrivateProfileStringA(
        section.c_str(),  // Å© string Å® const char*
        key.c_str(),
        std::to_string(defaultValue).c_str(),
        buffer,
        sizeof(buffer),
        iniPath.c_str()
    );
    return std::atoi(buffer);
}

