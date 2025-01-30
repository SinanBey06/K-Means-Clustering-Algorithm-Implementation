/********************************************************
Filename: OPP_LAB_FİNAL.cpp
Author: Sinan İLBEY
Date: 10.12.2024
Course: OOP
Description: KMeans clustering algorithm
Deadline: 25.12.2025
********************************************************/

/**
 * @file main.cpp
 * @brief Main function to execute KMeans clustering algorithm.
 */

#include <iostream>
#include <fstream>
#include "KMeans.h"
#include "Cluster.h"
using namespace std;

/**
 * @brief Main function of the program.
 *
 * This function initializes the KMeans algorithm with the input data file,
 * number of clusters (K), and the output file where the results will be saved.
 * If any exception occurs during the execution, it is caught and displayed as an error message.
 *
 * @return int Status code of the execution.
 */
int main() {
    try {
        /**
         * @brief Create a KMeans object to perform clustering.
         *
         * This object initializes the KMeans algorithm with the following parameters:
         * - The file path to the input data: "C:\\Users\\asus\\OneDrive\\Masaüstü\\OOP LAB FINAL\\40.txt"
         * - The number of clusters (K): 6
         * - The file path for saving the output: "C:\\Users\\asus\\OneDrive\\Masaüstü\\OOP LAB FINAL\\output.txt"
         *
         * The KMeans constructor will load the dataset, perform clustering, and store the results in the output file.
         */
        KMeans kmeans("C:\\Users\\asus\\OneDrive\\Masaüstü\\OOP_PROJE_LAB_FİNAL\\40.txt", 6,
            "C:\\Users\\asus\\OneDrive\\Masaüstü\\OOP LAB FINAL\\OUTPUT\\output.txt");


    }
    catch (const exception& e) {
        /**
         * @brief Catch any exceptions thrown during the execution.
         *
         * This block handles errors that occur during the clustering process and
         * displays the error message to the user.
         *
         * @param e The exception object which contains the error message.
         */
        cerr << "Error: " << e.what() << endl;
    }

    return 0;  ///< Return 0 to indicate successful execution.
}
