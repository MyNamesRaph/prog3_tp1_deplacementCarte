#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
private:
	int m_x;
	int m_y;
public:
	// Constructeur par défaut, initialise à 0,0
	Point2D();
	// Constructeur avec position
	Point2D(int x, int y);
	// Acesseurs de position
	int getX();
	int getY();
	// Changer le point
	void setPoint(int x, int y);
};

#endif



