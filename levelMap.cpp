#include"LevelMap.h"
#include <iostream>

using namespace sf;

LevelMap::LevelMap() {

	if (levelMapImage.loadFromFile("images/map.png")) { std::cout << "file was successful loaded!" << std::endl; }
	else { std::cout << "file was unsuccessful loaded!!!" << std::endl; }
	levelMapTexture.loadFromImage(levelMapImage);
	levelMapSprite.setTexture(levelMapTexture);
}

LevelMap::~LevelMap() {

}

void LevelMap::renderLevelMap(RenderWindow &window) {
	for (int i(0); i < HEIGHT_MAP; i++) {
		for (int j(0); j < WIDTH_MAP; j++) {

			if (TileMap[i][j] == ' ')	levelMapSprite.setTextureRect(IntRect( 0, 0, 32, 32));	//если встретили символ пробел, то рисуем 1й квадратик
			if (TileMap[i][j] == 'S')	levelMapSprite.setTextureRect(IntRect(32, 0, 32, 32));	//если встретили символ s, то рисуем 2й квадратик
			if (TileMap[i][j] == '0')	levelMapSprite.setTextureRect(IntRect(64, 0, 32, 32));	//если встретили символ 0, то рисуем 3й квадратик

			levelMapSprite.setPosition(j * 32, i * 32);		//по сути раскидывает квадратики, превращая в карту. Tо есть задает каждому из них позицию. 
															//Eсли убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат.
			window.draw(levelMapSprite);
		}
	}
}

Image LevelMap::getLevelMapImage() {
	return this->levelMapImage;
}

Texture LevelMap::getLevelMapTexture() {
	return this->levelMapTexture;
}

Sprite LevelMap::getLevelMapSprite() {
	return this->levelMapSprite;
}