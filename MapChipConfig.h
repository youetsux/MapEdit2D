#pragma once

struct MapChipConfig {
	int TILE_PIX_SIZE;// 1タイルのピクセルサイズ
	int TILES_X;//マップチップシートのマップチップの横並び数
	int TILES_Y; //マップチップシートのマップチップの縦並び数
	int MAPCHIP_VIEW_X;//マップチップウィンドウの横並び数
	int MAPCHIP_VIEW_Y; //マップチップウィンドウの縦並び数
	int MAPCHIP_WIN_WIDTH;
	int	MAPCHIP_WIN_HEIGHT;
};

const MapChipConfig& GetMapChipConfig();