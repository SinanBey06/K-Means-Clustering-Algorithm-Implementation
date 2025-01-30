/**********************************************************************************************************
 * @file Cluster.cpp
 * @brief This file contains the implementation of the Cluster class. Each cluster represents a group
 *        of samples in the K-means algorithm. It stores the unique ID of the cluster, its center
 *        coordinates (centerX, centerY), and a list of samples belonging to the cluster. The center
 *        is updated based on the average of the samples' coordinates. The class also provides methods
 *        to add samples, clear samples, and print cluster information.
 ************************************************************************************************************/

#include "Cluster.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Constructor to initialize a cluster with its ID and center coordinates.
 *
 * @param ID The unique ID for the cluster.
 * @param X The X coordinate of the cluster's center.
 * @param Y The Y coordinate of the cluster's center.
 */
Cluster::Cluster(int ID, double X, double Y)
    : clusterID(ID), centerX(X), centerY(Y)
{
    // Constructor: Initializes the cluster with ID, center X, and center Y.
}

/**
 * @brief Destructor for the Cluster class.
 *        It calls the print method to display the cluster's information when the object is destroyed.
 */
Cluster::~Cluster()
{
    print();
}

/**
 * @brief Adds a sample to the cluster's list of samples.
 *        The sample is added at the end of the sample list.
 *
 * @param sample A pointer to the Sample object to be added to the cluster.
 */
void Cluster::addSample(Sample* sample)
{
    samples.push_back(sample);  ///< Add a new sample to the cluster's sample list.
}

/**
 * @brief Clears all samples from the cluster's list.
 */
void Cluster::clearSamples(void)
{
    samples.clear();  ///< Clears all samples from the cluster's sample list.
}

/**
 * @brief Calculates the new center of the cluster based on the average coordinates of the samples.
 *        If the center changes, it returns true; otherwise, it returns false.
 *
 * @return true If the center of the cluster has changed.
 * @return false If the center of the cluster remains the same.
 */
bool Cluster::calculateCenter(void) {
    // Check if the sample list is empty. If it is, return false.
    if (samples.empty()) return false;

    // Initialize variables to store the sum of X and Y coordinates.
    double sumX = 0, sumY = 0;

    // Loop through all the samples and sum their X and Y coordinates.
    for (const auto& sample : samples) {
        sumX += sample->getX();  ///< Add X coordinate of the sample to sumX.
        sumY += sample->getY();  ///< Add Y coordinate of the sample to sumY.
    }

    // Calculate the new center by averaging the X and Y coordinates of all samples.
    double newCenterX = sumX / samples.size();  ///< Compute the average X coordinate.
    double newCenterY = sumY / samples.size();  ///< Compute the average Y coordinate.

    // Check if the new center is different from the old center.
    bool changed = (newCenterX != centerX || newCenterY != centerY);

    // Update the cluster's center with the new calculated values.
    centerX = newCenterX;
    centerY = newCenterY;

    // Return true if the center has changed, otherwise return false.
    return changed;
}

/**
 * @brief Gets the X coordinate of the cluster's center.
 *
 * @return double The X coordinate of the cluster's center.
 */
double Cluster::getXofCluster(void) const
{
    return centerX;  ///< Return the X coordinate of the cluster's center.
}

/**
 * @brief Gets the Y coordinate of the cluster's center.
 *
 * @return double The Y coordinate of the cluster's center.
 */
double Cluster::getYofCluster(void) const
{
    return centerY;  ///< Return the Y coordinate of the cluster's center.
}

/**
 * @brief Gets the unique ID of the cluster.
 *
 * @return int The ID of the cluster.
 */
int Cluster::getIDofCluster(void) const
{
    return clusterID;  ///< Return the cluster's ID.
}

/**
 * @brief Prints the cluster's information, including the ID and center coordinates.
 */
void Cluster::print(void) const
{
    cout << "Cluster Information:" << endl;
    cout << "--------------------" << endl;
    cout << "Cluster ID       : " << getIDofCluster() << endl;
    cout << "Center Coordinates: (" << getXofCluster() << ", " << getYofCluster() << ")" << endl;
    cout << "--------------------" << endl;
}
