/****************************************************************************
 * @file KMeans.cpp
 * @brief This code is a C++ program that implements the K-means clustering algorithm.
 *        The K-means algorithm is used to divide data points into groups (clusters)
 *        with similar properties. It divides the given data set into K clusters
 *        and prints the results of these clusters on the screen and saves them to a file.
 *        It takes the data in the form of a file path, gets the number of clusters and
 *        finally gets the directory to save.
 ****************************************************************************/

#include "KMeans.h"  // Definition of the KMeans class
#include "Cluster.h" // Definition of the Cluster class
#include "Sample.h"  // Definition of the Sample data class
#include <fstream>   // For file reading/writing
#include <iostream>  // For console input/output
#include <cmath>     // For mathematical operations 
#include <limits>    // For defining boundary values 
#include <stdexcept> // For exception handling
#include <iomanip>   // For formatted output
#include <vector>
#include <algorithm>

using namespace std; // Use standard namespace

/**
 * @brief Constructor for KMeans class that initializes the algorithm with the given input file,
 *        the number of clusters (K), and the output file name.
 *
 * @param fileName The input file name containing sample data.
 * @param k The number of clusters (K).
 * @param OutputfileName The output file name to save the results.
 */
KMeans::KMeans(const string& fileName, int k, const string& OutputfileName)
    : K(k) {

    // Ensure the number of clusters (K) is a positive integer
    if (K <= 0) {
        throw invalid_argument("K must be a positive number.");
    }

    setFileName(fileName);                ///< Set the input file name
    setOutputFileName(OutputfileName);    ///< Set the output file name

    loadSamples(getFileName());           ///< Load the sample data from the file
    initialize();                         ///< Initialize the clusters using the first K samples
    updateKM();                           ///< Perform the K-means clustering algorithm
}

/**
 * @brief Destructor for the KMeans class that prints and saves the results when the object is destroyed.
 */
KMeans::~KMeans()
{
    printResults(getSamples());          ///< Print the final results
    saveResultsToFile(getOutputFileName()); ///< Save the results to a file
}

/**
 * @brief Get input file directory.
 *
 * @return string The input file path.
 */
string KMeans::getFileName() const {
    return fileName;
}

/**
 * @brief Set input file directory.
 *
 * @param fileName The file path to the input data.
 */
void KMeans::setFileName(const string& fileName) {
    this->fileName = fileName;
}

/**
 * @brief Get output file directory.
 *
 * @return string The output file path.
 */
string KMeans::getOutputFileName() const {
    return outputfileName;
}

/**
 * @brief Set output file directory.
 *
 * @param OutputfileName The file path to save the output data.
 */
void KMeans::setOutputFileName(const string& OutputfileName) {
    this->outputfileName = OutputfileName;
}

/**
 * @brief Method to load sample data from the specified file.
 *        This function reads sample data (index, x, y)
 *        from a file and creates Sample objects to store the data in a vector.
 *
 * @param fileName The name of the input file to load sample data from.
 * @throws runtime_error If the file cannot be opened.
 */
void KMeans::loadSamples(const string& fileName) {
    ifstream file(getFileName());  ///< Open the file
    if (!file) {
        throw runtime_error("File not found: " + getFileName());  ///< Throw an exception if the file cannot be opened
    }

    int index;
    double x, y;

    // Read the data (index, x, y) and create Sample objects to store them
    while (file >> index >> x >> y) {
        samples.emplace_back(index, -1, x, y);  ///< Create a Sample object and add it to the samples vector
    }

    file.close();  ///< Close the file after reading
}

/**
 * @brief This function creates K clusters and sets their centers to the first K samples.
 */
void KMeans::initialize() {
    int clusterId = 1;
    for_each(samples.begin(), samples.begin() + K, [&](const Sample& sample) {
        clusters.emplace_back(clusterId++, sample.getX(), sample.getY());
        });
}

/**
 * @brief This method calculates the Euclidean distance between each sample and
 *        the centers of all clusters, and assigns the sample to the nearest cluster.
 */
void KMeans::assignSamplesToClusters() {
    // Clear all existing samples from the clusters before reassigning
    for_each(clusters.begin(), clusters.end(), [](Cluster& cluster) {
        cluster.clearSamples();
        });

    // Assign each sample to the nearest cluster
    for_each(samples.begin(), samples.end(), [&](Sample& sample) {
        double minDistance = numeric_limits<double>::max();  ///< Initialize with a large value
        int bestClusterID = -1;

        // Calculate the distance from the sample to each cluster center
        for_each(clusters.begin(), clusters.end(), [&](const Cluster& cluster) {
            double distance = sqrt(pow(sample.getX() - cluster.getXofCluster(), 2) +
                pow(sample.getY() - cluster.getYofCluster(), 2));

            // Update the best cluster if the current one is closer
            if (distance < minDistance) {
                minDistance = distance;
                bestClusterID = cluster.getIDofCluster();
            }
            });

        // Assign the sample to the closest cluster
        sample.setClusterID(bestClusterID);  ///< Ensure this method exists and is accessible
        clusters[bestClusterID - 1].addSample(&sample);  ///< Add the sample to the best cluster
        });
}

/**
 * @brief This function assigns samples to clusters, calculates
 *        new cluster centers, and repeats the process until the cluster centers stop changing.
 */
void KMeans::updateKM() {
    bool changed;
    do {
        changed = false;

        // Step 1: Assign samples to the closest clusters
        assignSamplesToClusters();

        // Step 2: Update the cluster centers and check if any of them changed
        for (auto& cluster : clusters) {
            if (cluster.calculateCenter()) {
                changed = true;  ///< If any cluster center changed, continue the iteration
            }
        }
    } while (changed);  ///< Repeat until no cluster centers change
}

/**
 * @brief Getter function to access the sample vector.
 *
 * @return const vector<Sample>& A reference to the vector of samples.
 */
const vector<Sample>& KMeans::getSamples(void) const {
    return samples;
}

/**
 * @brief Getter function to access the clusters vector.
 *
 * @return const vector<Cluster>& A reference to the vector of clusters.
 */
const vector<Cluster>& KMeans::getClusters(void) const {
    return clusters;
}

/**
 * @brief This function prints the information of each sample, its index, coordinates (x, y) and the cluster ID it belongs to.
 *
 * @param samples The vector of Sample objects to print.
 */
void KMeans::printResults(const vector<Sample>& samples) {
    cout << "K-Means Results:" << endl;
    cout << "---------------------------------------------------------------" << endl;

    // Print each sample's information using the overloaded << operator
    for_each(samples.begin(), samples.end(), [](const auto& sample) {
        cout << sample;
        });

    cout << "\nK-Means clustering result calculated successfully!" << endl;
}

/**
 * @brief This function writes the results, including the instance’s index, coordinates,
 *        and assigned cluster ID, to an output file.
 *
 * @param filePath The path of the file where results will be saved.
 */
void KMeans::saveResultsToFile(const string& filePath) const {
    ofstream outFile(filePath);  ///< Open the file to write the results

    if (outFile.is_open()) {
        // Write headers for the output file
        outFile << "----------------------------------------------\n";
        outFile << "|  Index   |  X     |   Y    | Cluster ID |\n";  ///< Column headers
        outFile << "----------------------------------------------\n";

        // Write each sample's data (Index, X, Y, Cluster ID)
        for (const auto& sample : samples) {
            outFile << "| "
                << setw(8) << sample.getIndex() << " | "  ///< Index
                << setw(6) << fixed << setprecision(2) << sample.getX() << " | "  ///< X coordinate
                << setw(6) << fixed << setprecision(2) << sample.getY() << " | "  ///< Y coordinate
                << setw(10) << sample.getClusterID() << " |\n";  ///< Cluster ID
        }

        outFile << "----------------------------------------------\n";  ///< Footer line
        outFile.close();  ///< Close the file after writing
    }
    else {
        cerr << "Unable to open file: " << filePath << endl;  ///< Print error if file cannot be opened
    }
}
