#ifndef KMEANS_H
#define KMEANS_H

#include <iostream>
#include "Cluster.h"
#include <fstream>
#include <cmath>
#include <limits>
#include <stdexcept>

using namespace std;

/**
 * @class KMeans
 * @brief Represents the K-means clustering algorithm.
 *        The class performs clustering of data points into K clusters based on the K-means algorithm.
 */
class KMeans
{
public:

    /**
     * @brief Constructor that initializes the KMeans object with the provided file name and number of clusters (K).
     *
     * @param fileName The name of the input file containing the sample data.
     * @param k The number of clusters (K) to form.
     * @param OutputfileName The name of the output file to save the results.
     */
    KMeans(const string& fileName, int k, const string& OutputfileName);

    /**
     * @brief Getter method to return the input file name.
     *
     * @return The name of the input file containing the sample data.
     */
    string getFileName() const;

    /**
     * @brief Setter method to set the input file name.
     *
     * @param fileName The name of the input file.
     */
    void setFileName(const string& fileName);

    /**
     * @brief Getter method to return the output file name.
     *
     * @return The name of the output file where results are saved.
     */
    string getOutputFileName() const;

    /**
     * @brief Setter method to set the output file name.
     *
     * @param OutputfileName The name of the output file.
     */
    void setOutputFileName(const string& OutputfileName);

    /**
     * @brief Getter method to access the vector of samples.
     *
     * @return A reference to the vector of Sample objects.
     */
    const vector<Sample>& getSamples(void) const;

    /**
     * @brief Getter method to access the vector of clusters.
     *
     * @return A reference to the vector of Cluster objects.
     */
    const vector<Cluster>& getClusters(void) const;

    /**
     * @brief Loads sample data from the specified file.
     *
     * @param fileName The name of the file containing sample data.
     */
    void loadSamples(const string& fileName);

    /**
     * @brief Initializes clusters using the first K samples as initial cluster centers.
     */
    void initialize(void);

    /**
     * @brief Assigns each sample to the nearest cluster based on Euclidean distance.
     */
    void assignSamplesToClusters(void);

    /**
     * @brief Runs the K-means algorithm: assigns samples to clusters and updates centers until convergence.
     */
    void updateKM(void);

    /**
     * @brief Saves the clustering results to the specified output file.
     *
     * @param filePath The path of the output file to save the results.
     */
    void saveResultsToFile(const string& filePath) const;

    /**
     * @brief Prints the clustering results to the console.
     *
     * @param samples The vector of Sample objects to print.
     */
    void printResults(const vector<Sample>& samples);

    /**
     * @brief Destructor that cleans up any resources when the KMeans object is destroyed.
     */
    ~KMeans();

private:

    /** The number of clusters (K) for the K-means algorithm. */
    int K;

    /** A vector that holds all the samples. */
    vector<Sample> samples;

    /** A vector that holds the clusters. */
    vector<Cluster> clusters;

    /** The input file name from which the sample data is loaded. */
    string fileName;

    /** The output file name where results are saved. */
    string outputfileName;
};

#endif
