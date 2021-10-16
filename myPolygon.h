#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define MOVEMEMENT 1

enum class DIRECTION {
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

class MyPolygon {
	//Liczba wierzcholkow
	int n;
	//Wspolrzedne srodka wielokata
	int x, y;
	//Dlugosc promienia okregu opisanego
	int r;
	//Tablica punktow
	float* tablica_punktow;
	//Wielkosc wyswietlacza
	int width, height;
	//Kolor krawedzi wielokata
	ALLEGRO_COLOR color;
	//Zmienne do obrotu
	double fi, dfi, sinfi, cosfi;
	//Zmienne do przesuwania sie
	DIRECTION moveDirectionWidth;
	DIRECTION moveDirectionHeight;

	void ChangePosition();
	bool CheckDirection();
	DIRECTION RandomDirectionHeight();
	DIRECTION RandomDirectionWidth();
	int ValidateN(int n);
public:
	MyPolygon(int n, int x, int y, int r, ALLEGRO_COLOR color, int width, int height);
	void CalculatePosition();
	void DrawPolygon();
	~MyPolygon();
};