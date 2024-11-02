#ifndef BLOCK_H
#define BLOCK_H

#include "checkML.h"
#include <SDL.h>
#include "Vector2D.h"
#include "texture.h"
#include <istream>
#include <iostream>
#include <fstream>
#include <string>

class Game;

using uint = unsigned int;
using namespace std;

class Block
{
	// atributos privados
private:
	Texture* texture = nullptr;	// puntero a su textura
	Game* game = nullptr;		// puntero al juego

	Point2D<double> position;	// posicion actual en Point2D

	char tipoL;
	int tipo;
	enum Tipo // tipo de bloque
	{
		LADRILLO, SORPRESA, OCULTO, VACIO
	};

	char accionL;
	int accion;
	enum Accion // accion
	{
		POTENCIADOR, MONEDA
	};

	// Guia de bloques txt
	// TIPO
	// ? -> sorpresa
	// B -> ladrillo
	// H -> oculto
	// ACCION
	// P -> potenciador
	// C -> moneda

	int blockFrame;
	int animationFrame = 0;   // Contador para el ciclo de caminar
	int frameTimer = 0;

public:
	Block(Game* g, std::istream& in);

	// -- render --
	void render() const;

	// -- update --
	void update();

	// -- hit --
	// controla las colisiones
	// Los bloques son obstaculos para todos los personajes cuando lo golpeen desde arriba o desde un lateral
	// Si Mario lo golpa desde abajo:
	//	-> si el bloque es de ladrillo y el player es SuperMario: bloque se rompe
	//	-> si el bloque es sorpresa/oculto y accion es potenciador: saca mushroom sobre el bloque y lo hace vacio
	//	-> nada en el resto de casos
	void hit(const SDL_Rect& rect, bool fromPlayer);
};

#endif