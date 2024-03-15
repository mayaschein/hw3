#include "HealthPoints.h"
HealthPoints::HealthPoints(int maximalPoints) :m_points(maximalPoints), m_maximalPoints(maximalPoints)
{
    //Verifying that the value of points received is positive
    //printf("%d, %d",m_points, m_maximalPoints);
   // printf("%d ", m_points);
    if (!(maximalPoints>0)){
        throw HealthPoints::InvalidArgument();
    } 
}
HealthPoints::HealthPoints(int points, int maximalPoints) :m_points(points), m_maximalPoints(maximalPoints) {
   // printf("%d ", m_points);
}
/*The function adds an integer value to the points of a HealthPoints object, while maintaining the maximal point limit defined for the object at its instantiation
In any case, the new value of m_points will not exceed the predefined maximal value */
HealthPoints HealthPoints::operator+(int addition) const
{
    if (addition >=0)
    {
        if (m_points+addition<m_maximalPoints) {
            return HealthPoints(m_points+addition, m_maximalPoints);
        }
        else {
            return HealthPoints(m_maximalPoints);
        }
    }
    else
    {
        if(m_points+addition>0){
            return HealthPoints(m_points+addition, m_maximalPoints);
        } 
        else{
            return HealthPoints(0,m_maximalPoints);
        }
    }
} 
int HealthPoints::operator+=(int addition)
{
    if (addition>=0)
    {
    if (m_points+addition<m_maximalPoints){
        m_points+=addition;
    }
    else{
        m_points=m_maximalPoints;
    } 
    }
    else
    {
        if(m_points+addition>0){
            m_points+=addition;
        }
        else{
           m_points=0; 
        }
        printf("%d, %d ", m_points, m_maximalPoints);
        return m_points;
    }
   // printf("%d ", m_points);
    return m_points;
}
/*The function subtracts an integer value from the points of a HealthPoints object, while maintaining the maximal point limit defined for the object at its instantiation
In any case, the new value of m_points will not descend below 0 */
HealthPoints HealthPoints::operator-(int subtraction) const
{
    if (subtraction>=0)
    {
        if(m_points-subtraction>0){
            return HealthPoints(m_points-subtraction, m_maximalPoints);
        } 
        else{
            return HealthPoints(0,m_maximalPoints);
        }
    }
    else
    {
        if(m_points-subtraction<m_maximalPoints)
        {
            return HealthPoints(m_points-subtraction, m_maximalPoints);
        }
        else return HealthPoints(m_maximalPoints);
    }
}
int HealthPoints::operator-=(int subtraction)
{
    if (subtraction>=0)
    {
        if(m_points-subtraction>0){
            m_points-=subtraction;
        }
        else{
           m_points=0; 
        }
        printf("%d, %d ", m_points, m_maximalPoints);
    }
    else
    {
        if (m_points-subtraction<m_maximalPoints){
        m_points-=subtraction;
    }
    else{
        m_points=m_maximalPoints;
    } 
    }
        return m_points;
}
//Comparison operators - compares the m_points parameter of a HealthPoints object with another int
bool operator==(const HealthPoints& HP, const int points)
{
    return HP.m_points==points;
}

bool operator==(const int points, const HealthPoints& HP)
{
    return HP.m_points==points;
}

bool HealthPoints::operator==(const HealthPoints& other) const
{
    return this->m_points == other.m_points;
}

bool HealthPoints::operator!=(int points) const
{
    return this->m_points!=points;
}

bool HealthPoints::operator!=(const HealthPoints& other) const
{
    return this->m_points != other.m_points;
}

bool HealthPoints::operator>(int points) const
{
    return this->m_points>points;
}

bool HealthPoints::operator>(const HealthPoints& other) const
{
    return this->m_points > other.m_points;
}

bool HealthPoints::operator>=(int points) const
{
    return this->m_points>=points;
}

bool HealthPoints::operator>=(const HealthPoints& other) const
{
    return this->m_points >= other.m_points;
}
bool HealthPoints::operator<(int points) const
{
    return this->m_points<points;
}
bool HealthPoints::operator<(const HealthPoints& other) const
{
    return this->m_points < other.m_points;
}
bool HealthPoints::operator<=(int points) const
{
    return this->m_points<=points;
}
bool HealthPoints::operator<=(const HealthPoints& other) const
{
    return this->m_points <= other.m_points;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& object) {
    os << object.m_points << "(" << object.m_maximalPoints << ")";
    return os;
}


HealthPoints::HealthPoints(const HealthPoints& other)
    : m_points(other.m_points), m_maximalPoints(other.m_maximalPoints) {
}

HealthPoints operator+(int addition1, HealthPoints addition2)
{
    if (addition1>=0)
    {
        if (addition1+addition2.m_points<addition2.m_maximalPoints){
            return HealthPoints(addition1+addition2.m_points, addition2.m_maximalPoints);
        } 
        else{
            return HealthPoints(addition2.m_maximalPoints);
        }
    }
    else
    {
        if (addition1+addition2.m_points>0){
            return HealthPoints(addition1+addition2.m_points, addition2.m_maximalPoints);
        } 
        else{
            return HealthPoints(0,addition2.m_maximalPoints);
    }
}
}
/*
HealthPoints operator-(HealthPoints subtraction1, int subtraction2)
{
if(subtraction1.m_points-subtraction2>0) return HealthPoints(subtraction1.m_points-subtraction2, subtraction1.m_maximalPoints);
        else return HealthPoints(0,subtraction1.m_maximalPoints);
} */