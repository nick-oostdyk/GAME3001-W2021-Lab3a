#include "Tile.h"

#include "TextureManager.h"
#include "Config.h"
#include "Util.h"

Tile::Tile() {

	//TextureManager::Instance()->load("../Assets/textures/tile.png", "Tile");

	//auto size = TextureManager::Instance()->getTextureSize("Tile");
	//setWidth(size.x);
	//setHeight(size.y);

	setWidth(Config::TILE_SIZE);
	setHeight(Config::TILE_SIZE);

}

Tile::~Tile()
= default;

void Tile::draw() {

	//TextureManager::Instance()->
	//	draw("Tile", getTransform()->position.x, getTransform()->position.y, 0, 255, false);

	Util::DrawRect(getTransform()->position, getWidth(), getHeight());
}

void Tile::update() {

}

void Tile::clean() {

}
