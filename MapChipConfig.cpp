#include "MapChipConfig.h"
#include <windows.h>
#include <cstdlib>   // std::atoi
#include <string>    // std::string

// 内部ユーティリティ
static int ReadIntFromIni(const std::string& section, const std::string& key, int defaultValue, const std::string& iniPath)
{
	char buffer[64];
	GetPrivateProfileStringA(
		section.c_str(), key.c_str(),
		std::to_string(defaultValue).c_str(),
		buffer, sizeof(buffer), iniPath.c_str()
	);
	return std::atoi(buffer);
}

MapChipConfig LoadMapChipConfig(const std::string& iniPath)
{
	MapChipConfig cfg;
	cfg.TILE_PIX_SIZE = ReadIntFromIni("MapChip", "TILE_PIX_SIZE", 32, iniPath);
	cfg.TILES_X = ReadIntFromIni("MapChip", "TILES_X", 16, iniPath);
	cfg.TILES_Y = ReadIntFromIni("MapChip", "TILES_Y", 12, iniPath);
	cfg.MAPCHIP_VIEW_X = ReadIntFromIni("MapChip", "MAPCHIP_VIEW_X", 8, iniPath);
	cfg.MAPCHIP_VIEW_Y = ReadIntFromIni("MapChip", "MAPCHIP_VIEW_Y", 24, iniPath);
	cfg.MAPCHIP_WIN_WIDTH = cfg.TILE_PIX_SIZE * cfg.MAPCHIP_VIEW_X;
	cfg.MAPCHIP_WIN_HEIGHT = cfg.TILE_PIX_SIZE * cfg.MAPCHIP_VIEW_Y;
	return cfg;
}

const MapChipConfig& GetMapChipConfig()
{
	static MapChipConfig config = LoadMapChipConfig("setting.ini");
	return config;
}