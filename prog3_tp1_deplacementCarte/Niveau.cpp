#include "Niveau.h"
#include "constantes.h"

Niveau::Niveau(int* carte, std::string nomCreature, Point2D positionDepart)
	:m_carte{carte},
	m_creature{ new Creature(nomCreature,positionDepart) } 
{
	int i = Niveau::getIndexCarte(positionDepart);
	m_carte[i] = -1;
}

Niveau::~Niveau()
{
	delete m_creature;
}

int Niveau::getIndexCarte(Point2D position)
{
	int width = constantes::dimension;
	int x = position.getX();
	int y = position.getY();

	return x + (width * y);

}

int* Niveau::getCarte() 
{
	return m_carte;
}

std::string Niveau::getNomCreature() 
{
	return m_creature->getNom();
}

void Niveau::getDeplacementPossible(bool* tabDeplacements) 
{
	Point2D* pos = m_creature->getPosition();


	if (m_carte[getIndexCarte(Point2D(pos->getX() - 1,pos->getY()))] == 0)
	{
		tabDeplacements[0] = true;
	}
	if (m_carte[getIndexCarte(Point2D(pos->getX() + 1, pos->getY()))] == 0)
	{
		tabDeplacements[1] = true;
	}
	if (m_carte[getIndexCarte(Point2D(pos->getX(), pos->getY() - 1))] == 0)
	{
		tabDeplacements[2] = true;
	}
	if (m_carte[getIndexCarte(Point2D(pos->getX(), pos->getY() + 1))] == 0)
	{
		tabDeplacements[3] = true;
	}
}

void Niveau::deplacerCreature(constantes::Direction direction)
{
	int x = m_creature->getPosition()->getX();
	int y = m_creature->getPosition()->getY();

	int i = Niveau::getIndexCarte(*m_creature->getPosition());
	m_carte[i] = 0;

	switch (direction)
	{
	case constantes::gauche:
		m_creature->deplacerCreature(x - 1, y);
		i = Niveau::getIndexCarte(Point2D(x-1,y));
		m_carte[i] = -1;
		break;
	case constantes::droite:
		m_creature->deplacerCreature(x + 1, y);
		i = Niveau::getIndexCarte(Point2D(x + 1, y));
		m_carte[i] = -1;
		break;
	case constantes::haut:
		m_creature->deplacerCreature(x, y - 1);
		i = Niveau::getIndexCarte(Point2D(x, y-1));
		m_carte[i] = -1;
		break;
	case constantes::bas:
		m_creature->deplacerCreature(x, y + 1);
		i = Niveau::getIndexCarte(Point2D(x, y+1));
		m_carte[i] = -1;
		break;
	default:
		break;
	}
}