#include "Scene.h"
#include "GameConfig.h"
#include "Backgroung.h"


Scene::Scene() 
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Scene::addLayer(Layer *layer)
{
	layers.push_back(layer);
}

void Scene::draw()
{
	CHAR_INFO consBuffer[GameConfig::WIDTH * GameConfig::HEIGHT]{}; // массив блока данных

	for (std::size_t i = 0; i < layers.size(); i++) {
		auto layer = layers[i];
		auto render = layer->render();
		for (std::size_t j = 0; j < render.size(); j++) {
			consBuffer[render[j].pos] = render[j].charInfo;
		}
	}

	COORD charPosition = { 0, 0 }; // точка в блоке
	SMALL_RECT writeArea = { 0, 0, GameConfig::WIDTH, GameConfig::HEIGHT};
	COORD bufferSize = {GameConfig::WIDTH, GameConfig::HEIGHT};
	WriteConsoleOutput(hConsole, consBuffer, bufferSize, charPosition, &writeArea);

	SetConsoleCursorPosition(hConsole, {0, GameConfig::HEIGHT});
}