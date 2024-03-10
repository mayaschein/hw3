#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H

#include <iostream>

class HealthPoints
{
private:
    int m_points; // Member variable to store current points
    int m_maximalPoints; // Member variable to store maximal points

public:
    // Constructor function to initialize HealthPoints object with a default maximal points value of 100
    HealthPoints(int maximalPoints=100);

    // Constructor function to initialize HealthPoints object with specified points and maximal points
    HealthPoints(int points, int maximalPoints);

    // Overloaded addition operator (+) to add an integer value to the points of a HealthPoints object
    // If the sum exceeds the maximal points, the resultant HealthPoints object will have maximal points
    HealthPoints operator+(int addition) const;

    // Overloaded compound addition assignment operator (+=) to add an integer value to the points of a HealthPoints object
    // If the sum exceeds the maximal points, the current points will be set to maximal points
    int operator+=(int addition);

    // Overloaded subtraction operator (-) to subtract an integer value from the points of a HealthPoints object
    // If the difference becomes less than 0, the resultant HealthPoints object will have 0 points
    HealthPoints operator-(int subtraction) const;

    // Overloaded compound subtraction assignment operator (-=) to subtract an integer value from the points of a HealthPoints object
    // If the difference becomes less than 0, the current points will be set to 0
    int operator-=(int subtraction);

    // Overloaded equality comparison operator (==) to compare the points of a HealthPoints object with an integer value
    bool operator==(int points);

    // Overloaded equality comparison operator (==) to compare the points of a HealthPoints object with another HealthPoints object
    bool operator==(HealthPoints& other);

    // Overloaded inequality comparison operator (!=) to compare the points of a HealthPoints object with an integer value
    bool operator!=(int points);

    // Overloaded inequality comparison operator (!=) to compare the points of a HealthPoints object with another HealthPoints object
    bool operator!=(HealthPoints& other);

    // Overloaded greater than comparison operator (>) to compare the points of a HealthPoints object with an integer value
    bool operator>(int points);

    // Overloaded greater than comparison operator (>) to compare the points of a HealthPoints object with another HealthPoints object
    bool operator>(HealthPoints& other);

    // Overloaded greater than or equal to comparison operator (>=) to compare the points of a HealthPoints object with an integer value
    bool operator>=(int points);

    // Overloaded greater than or equal to comparison operator (>=) to compare the points of a HealthPoints object with another HealthPoints object
    bool operator>=(HealthPoints& other);

    // Overloaded less than comparison operator (<) to compare the points of a HealthPoints object with an integer value
    bool operator<(int points);

    // Overloaded less than comparison operator (<) to compare the points of a HealthPoints object with another HealthPoints object
    bool operator<(HealthPoints& other);

    // Overloaded less than or equal to comparison operator (<=) to compare the points of a HealthPoints object with an integer value
    bool operator<=(int points);

    // Overloaded less than or equal to comparison operator (<=) to compare the points of a HealthPoints object with another HealthPoints object
    bool operator<=(HealthPoints& other);

    // Overloaded insertion operator (<<) to print the points and maximal points of a HealthPoints object to an output stream
    std::ostream& operator<<(const HealthPoints& object);

    // Exception class for invalid arguments
    class invalidArgument{};
};

// Constructor implementation for the invalidArgument exception class
class HealthPoints::invalidArgument
{
public:
    invalidArgument();
};

#endif // HEALTHPOINTS_H
