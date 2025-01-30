#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>

using namespace std;

/**
 * @class Sample
 * @brief Represents a single sample in the K-means algorithm.
 *        Each sample consists of an index, cluster ID, and (x, y) coordinates in a 2D space.
 */
class Sample
{
    // Non-member overloaded << operator for the Sample class
    // This allows us to output Sample objects to an ostream (e.g., cout)
    friend ostream& operator<<(ostream& OUTPUT, const Sample& a);

public:

    /**
     * @brief Constructor that initializes a Sample object with the given index, cluster ID, and (x, y) coordinates.
     *
     * @param i The index of the sample.
     * @param ID The ID of the cluster the sample belongs to.
     * @param X The X coordinate of the sample.
     * @param Y The Y coordinate of the sample.
     */
    Sample(int i, int ID, double X, double Y);

    /**
     * @brief Destructor for the Sample class.
     *        Performs cleanup when the object is destroyed.
     */
    ~Sample();

    /**
     * @brief Sets the cluster ID for the sample.
     *
     * @param ID The ID of the cluster.
     */
    void setClusterID(int ID);

    /**
     * @brief Gets the index of the sample.
     *
     * @return The index of the sample.
     */
    int getIndex(void) const;

    /**
     * @brief Gets the cluster ID of the sample.
     *
     * @return The cluster ID.
     */
    int getClusterID(void) const;

    /**
     * @brief Gets the X coordinate of the sample.
     *
     * @return The X coordinate of the sample.
     */
    double getX(void) const;

    /**
     * @brief Gets the Y coordinate of the sample.
     *
     * @return The Y coordinate of the sample.
     */
    double getY(void) const;

private:

    /** The index of the sample. */
    int idx;

    /** The ID of the cluster the sample belongs to. */
    int cID;

    /** The X coordinate of the sample in the 2D space. */
    double x;

    /** The Y coordinate of the sample in the 2D space. */
    double y;
};

#endif
