#include <HealthPoints.h>
HealthPoints::HealthPoints(int maximalPoints) :m_points(maximalPoints), m_maximalPoints(maximalPoints)
HealthPoints::HealthPoints(int points, int maximalPoints) :m_points(points), m_maximalPoints(maximalPoints);
{
    //Verifying that the value of points received is positive
    if (!(maximalPoints>0)) throw HealthPoints::invalidArgument();
}
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
std::ostream& operator<<(const HealthPoints& object) {
    std::cout << object.m_points << "(" << object.m_maximalPoints << ")" << std::endl;
    return std::cout;
}