#ifndef CLUSTER_H
#define CLUSTER_H

#include <iostream>
#include <vector>
#include "Sample.h"

using namespace std;

/**
 * @class Cluster
 * @brief Represents a cluster in the K-means algorithm.
 *        Each cluster has a unique ID, a center (calculated as the average of its sample points),
 *        and a list of samples belonging to the cluster.
 */
class Cluster
{
public:

    /**
     * @brief Constructor to initialize a cluster with a unique ID and center coordinates.
     *
     * @param ID The unique ID of the cluster.
     * @param X The X coordinate of the cluster's center.
     * @param Y The Y coordinate of the cluster's center.
     */
    Cluster(int ID, double X, double Y);

    /**
     * @brief Destructor to clean up resources when the Cluster object is destroyed.
     */
    ~Cluster();

    /**
     * @brief Adds a sample to the cluster's list of samples.
     *
     * @param sample A pointer to the Sample object to be added.
     */
    void addSample(Sample* sample);

    /**
     * @brief Clears all samples from the cluster's sample list.
     */
    void clearSamples();

    /**
     * @brief Calculates the new center of the cluster based on the average coordinates of the samples.
     *        It returns true if the center has changed, false otherwise.
     *
     * @return true If the center has changed.
     * @return false If the center remains the same.
     */
    bool calculateCenter();

    /**
     * @brief Returns the X coordinate of the cluster's center.
     *
     * @return The X coordinate of the cluster's center.
     */
    double getXofCluster() const;

    /**
     * @brief Returns the Y coordinate of the cluster's center.
     *
     * @return The Y coordinate of the cluster's center.
     */
    double getYofCluster() const;

    /**
     * @brief Returns the unique ID of the cluster.
     *
     * @return The ID of the cluster.
     */
    int getIDofCluster() const;

    /**
     * @brief Prints the cluster's ID and center coordinates.
     */
    void print() const;

private:

    /** The ID of the cluster. */
    int clusterID;

    /** The X coordinate of the cluster's center. */
    double centerX;

    /** The Y coordinate of the cluster's center. */
    double centerY;

    /** A vector of pointers to the samples belonging to the cluster. */
    vector<Sample*> samples;
};

#endif
