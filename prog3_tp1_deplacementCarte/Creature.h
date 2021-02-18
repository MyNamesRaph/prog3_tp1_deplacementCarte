#ifndef CREATURE_H
#define CREATURE_H

#include "Point2D.h"
#include <string>

class Creature
{
private:
	std::string m_nom;
	Point2D m_position;
public:
	// Constructeur
	Creature(std::string nom, Point2D position);
	// Retourne le nom de la cérature
	std::string getNom();
	// Retourne un pointeur vers la position de la créature
	Point2D* getPosition();
	// Change la position de la créature
	void deplacerCreature(int x, int y);
};

#endif

