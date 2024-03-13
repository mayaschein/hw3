#include "HealthPoints.h"
HealthPoints::HealthPoints(int maximalPoints) :m_points(maximalPoints), m_maximalPoints(maximalPoints)
{
    //Verifying that the value of points received is positive
    if (!(maximalPoints>0)) throw HealthPoints::InvalidArgument();
}
HealthPoints::HealthPoints(int points, int maximalPoints) :m_points(points), m_maximalPoints(maximalPoints) {}
/*The function adds an integer value to the points of a HealthPoints object, while maintaining the maximal point limit defined for the object at its instantiation
In any case, the new value of m_points will not exceed the predefined maximal value */
HealthPoints HealthPoints::operator+(int addition) const
{
        if (m_points+addition<m_maximalPoints) return HealthPoints(m_points+addition, m_maximalPoints);
        else return HealthPoints(m_maximalPoints);
}
int HealthPoints::operator+=(int addition)
{
    if (m_points+addition<m_maximalPoints) m_points+=addition;
    else m_points=m_maximalPoints;
    return m_points;
}
/*The function subtracts an integer value from the points of a HealthPoints object, while maintaining the maximal point limit defined for the object at its instantiation
In any case, the new value of m_points will not descend below 0 */
HealthPoints HealthPoints::operator-(int subtraction) const
{
        if(m_points-subtraction>0) return HealthPoints(m_points-subtraction, m_maximalPoints);
        else return HealthPoints(0,m_maximalPoints);
}
int HealthPoints::operator-=(int subtraction)
{
        if(m_points-subtraction>0) m_points-=subtraction;
        else m_points=0;
        return m_points;
}
//Comparison operators - compares the m_points parameter of a HealthPoints object with another int
bool HealthPoints::operator==(int points) const
{
    return this->m_points==points;
}
bool HealthPoints::operator==(HealthPoints& other) const
{
    return this->m_points == other.m_points;
}
bool HealthPoints::operator!=(int points) const
{
    return this->m_points!=points;
}
bool HealthPoints::operator!=(HealthPoints& other) const
{
    return this->m_points != other.m_points;
}
bool HealthPoints::operator>(int points) const
{
    return this->m_points>points;
}
bool HealthPoints::operator>(HealthPoints& other) const
{
    return this->m_points > other.m_points;
}
bool HealthPoints::operator>=(int points) const
{
    return this->m_points>=points;
}
bool HealthPoints::operator>=(HealthPoints& other) const
{
    return this->m_points >= other.m_points;
}
bool HealthPoints::operator<(int points) const
{
    return this->m_points<points;
}
bool HealthPoints::operator<(HealthPoints& other) const
{
    return this->m_points < other.m_points;
}
bool HealthPoints::operator<=(int points) const
{
    return this->m_points<points;
}
bool HealthPoints::operator<=(HealthPoints& other) const
{
    return this->m_points < other.m_points;
}
std::ostream& operator<<(std::ostream& os, const HealthPoints& object) {
    os << object.m_points << "(" << object.m_maximalPoints << ")" << std::endl;
    return os;
}

HealthPoints operator+(int addition1, HealthPoints addition2)
{
        if (addition1+addition2.m_points<addition2.m_maximalPoints){
            return HealthPoints(addition1+addition2.m_points, addition2.m_maximalPoints);
        } 
        else return HealthPoints(addition2.m_maximalPoints);
}