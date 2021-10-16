#include "myPolygon.h"

int MyPolygon::ValidateN(int n) {
	if (n < 3) return 3; else return n;
}

bool MyPolygon::CheckDirection() {
	for (int i = 0; i < n; i++) {
		if (tablica_punktow[2 * i] < 0){
			moveDirectionWidth = DIRECTION::EAST;
			return false;
		}
		if (tablica_punktow[2 * i] > width) {
			moveDirectionWidth = DIRECTION::WEST;
			return false;
		}
		if (tablica_punktow[2 * i + 1] < 0) {
			moveDirectionHeight = DIRECTION::SOUTH;
			return false;
		}
		if (tablica_punktow[2 * i  + 1] > height) {
			moveDirectionHeight = DIRECTION::NORTH;
			return false;
		}
	}
	return true;
}

DIRECTION MyPolygon::RandomDirectionHeight() {
	switch (rand() % 2) {
	case 0:
		return DIRECTION::NORTH;
	case 1:
		return DIRECTION::SOUTH;
	}
	return DIRECTION::NORTH;
}

DIRECTION MyPolygon::RandomDirectionWidth() {
	switch (rand() % 2) {
	case 0:
		return DIRECTION::WEST;
	case 1:
		return DIRECTION::EAST;
	}
	return DIRECTION::WEST;
}

void MyPolygon::ChangePosition() {
	if (moveDirectionHeight == DIRECTION::NORTH)
		y -= MOVEMEMENT;
	else
		y += MOVEMEMENT;

	if (moveDirectionWidth == DIRECTION::WEST)
		x -= MOVEMEMENT;
	else
		x += MOVEMEMENT;
}

MyPolygon::MyPolygon(int n, int x, int y, int r, ALLEGRO_COLOR color, int width, int height) {
	this->n = ValidateN(n);
	this->x = x;
	this->y = y;
	this->r = r;
	this->color = color;
	this->height = height;
	this->width = width;
	this->fi = 0.0;
	this->dfi = 0.1;
	moveDirectionHeight = RandomDirectionHeight();
	moveDirectionWidth = RandomDirectionWidth();
	tablica_punktow = (float*)malloc(sizeof(float) * 2 * n);
}

void MyPolygon::CalculatePosition() {
	do {
		ChangePosition();
		//Generowanie wspolrzednych punktow bokow
		for (int i = 0; i < n; i++) {
			tablica_punktow[2 * i] = x + r * cos(2 * i * M_PI / n + fi);
			tablica_punktow[2 * i + 1] = y + r * sin(2 * i * M_PI / n + fi);
		}
	} while (!CheckDirection());
	fi += dfi;
}

void MyPolygon::DrawPolygon() {
	al_draw_polygon(tablica_punktow, n, ALLEGRO_LINE_JOIN_BEVEL, color, 3, 2);
}

MyPolygon::~MyPolygon() {
	free(tablica_punktow);
}