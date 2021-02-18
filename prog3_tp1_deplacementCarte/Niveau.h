#ifndef NIVEAU_H
#define NIVEAU_H

#include "Point2D.h"
#include "Creature.h"
#include "constantes.h"
#include <string>

class Niveau
{
private:
	// Un tableau d'entiers à 1 dimension représentant une carte carrée
	// Les murs (infranchissables) sont des 1
	// Le cases libres pour le déplacement sont des 0
	// La position de la créature est un -1
	int* m_carte; 
	// Un pointeur vers la créature
	Creature* m_creature;
	// Une fonction interne pour avoir l'index du tableau correspondant au point2d
	int getIndexCarte(Point2D position); 
public:
	// Constructeur, reçoit un tableau pour représenter l'arène de jeu, le nom de la créature et sa position initiale
	Niveau(int* carte, std::string nomCreature, Point2D positionDepart);
	// Destructeur selon l'utilisation d'allocation dynamique de mémoire
	~Niveau();
	// Retourne la carte de jeu pour l'affichage
	int* getCarte();
	// Retourne le nom de la créature pour l'affichage
	std::string getNomCreature();
	// Reçoit un tableau de 4 bool
	// Modifie le tableau pour savoir dans quelles directions on peut se déplacer
	void getDeplacementPossible(bool* tabDeplacements);
	// Change la position de la créature selon la direction choisie
	void deplacerCreature(constantes::Direction direction);
};

#endif

