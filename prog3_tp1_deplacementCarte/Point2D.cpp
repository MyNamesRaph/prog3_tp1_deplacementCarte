#include "Point2D.h"

Point2D::Point2D()
	:m_x{0},
	m_y{0} {}

Point2D::Point2D(int x, int y)
	: m_x{ x },
	m_y{ y } {}

int Point2D::getX()
{
	return m_x;
}

int Point2D::getY()
{
	return m_y;
}

void Point2D::setPoint(int x, int y)
{
	m_x = x;
	m_y = y;
}