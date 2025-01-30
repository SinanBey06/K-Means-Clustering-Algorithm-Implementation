/***********************************************************************
 * @file Sample.cpp
 * @brief Represents a data point in 2D space. Each instance has an index number,
 *        x and y coordinates, and a cluster ID. Provides the overloaded <<
 *        operator to print its information to the screen.
 ***********************************************************************/

#include "Sample.h"
#include <stdexcept>

using namespace std;

/**
 * @brief Constructor: Initializes a Sample object with the provided index, cluster ID, and (x, y) coordinates.
 *
 * @param i Index of the sample.
 * @param clusterID The ID of the cluster to which the sample belongs.
 * @param X The X coordinate of the sample in 2D space.
 * @param Y The Y coordinate of the sample in 2D space.
 */
Sample::Sample(int i, int clusterID, double X, double Y)
    : idx(i), x(X), y(Y)
{
    // The constructor initializes the sample's index, cluster ID, and coordinates (x, y).
}

/**
 * @brief Destructor: Default destructor for the Sample class.
 */
Sample::~Sample()
{
    // Destructor implementation
}

/**
 * @brief Method to set the cluster ID for the sample.
 *
 * @param clusterID The new cluster ID for the sample.
 */
void Sample::setClusterID(int clusterID)
{
    cID = clusterID;  ///< Set the sample's cluster ID.
}

/**
 * @brief Method to get the index of the sample.
 *
 * @return int The index of the sample.
 */
int Sample::getIndex(void) const
{
    return idx;  ///< Return the sample's index.
}

/**
 * @brief Method to get the cluster ID of the sample.
 *
 * @return int The cluster ID of the sample.
 */
int Sample::getClusterID(void) const
{
    return cID;  ///< Return the sample's assigned cluster ID.
}

/**
 * @brief Method to get the X coordinate of the sample.
 *
 * @return double The X coordinate of the sample.
 */
double Sample::getX(void) const
{
    return x;  ///< Return the X coordinate of the sample.
}

/**
 * @brief Method to get the Y coordinate of the sample.
 *
 * @return double The Y coordinate of the sample.
 */
double Sample::getY(void) const
{
    return y;  ///< Return the Y coordinate of the sample.
}

/**
 * @brief Overloaded << operator to output sample details to an output stream.
 *
 * This operator allows printing the sample's details including index, coordinates, and cluster ID.
 *
 * @param output The output stream to which the sample details are written.
 * @param sample The Sample object whose details are printed.
 * @return ostream& The output stream to allow for chaining.
 */
ostream& operator<<(ostream& output, const Sample& sample)
{
    // Format and print the sample's details: index, coordinates, and assigned cluster ID
    output << "Index: " << sample.getIndex()
        << "\t| X: " << sample.getX()
        << " \t| Y: " << sample.getY()
        << "\t| Cluster ID: " << sample.getClusterID()
        << endl;

    return output;  ///< Return the output stream to allow for chaining.
}
