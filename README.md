

1. Introduction 
K-Means is a widely used clustering algorithm that divides data points into K clusters based 
on their similarity. This implementation focuses on building a reusable and extensible K
Means algorithm in C++ to cluster 2D data points. The codebase consists of three primary 

classes: 
 Sample: Represents a single data point. 
 Cluster: Represents a group of data points with a center point. 
 KMeans: Implements the K-Means algorithm and manages the clustering process. 

2. Code Overview 

Simple Class: 
This code defines the Sample class, which represents a data point (for example, a sample) in 
2D space. Each sample has an index number, x and y coordinates, and a cluster ID. 

Data Members 

int idx: This data member holds a unique index number for the sample. 
int cID: Holds the cluster ID to which the sample is attached. During the K-means algorithm, 
each sample is assigned to a cluster, and this data member specifies which cluster the 
sample belongs to. 
double x: Holds the x coordinate of the sample. 
double y: Holds the y coordinate of the sample. 

Functions 

Sample(int i, int clusterID, double X, double Y) (Constructor Function); This constructor 
function takes the index number, cluster ID, and x, y coordinates of the sample when creating 
a Sample object, and assigns this information to the object. 
~Sample() (Destructor Function): This is the default destructor function of the Sample class. 
No extra action is required when clearing the object memory. 
void setClusterID(int clusterID) This function is used to set the cluster ID of the instance. 
int getIndex(void) const: This function returns the index number of the instance. 
int getClusterID(void) const: This function returns the cluster ID to which the instance 
belongs. 

double getX(void) const: This function returns the x-coordinate of the instance. 
double getY(void) const: This function returns the y-coordinate of the instance. 
Overloaded Operator:ostream& operator<<(ostream& output, const Sample& sample). This 
function is used to print the information of the Sample class to the screen. The << operator is 
paired with the ostream class to print the properties of a Sample object to the screen in a 
formatted manner. This function prints the index number, x, y coordinates and cluster ID of 
the instance. 

Cluster Class: 

The basic function of this class is to create a cluster that holds the samples together and to 
calculate the center of this cluster. In the K-means algorithm, each cluster finds a center by 
collecting the samples and this center represents the location of the cluster. This center is 
updated in each iteration. 

Data Members 

ID (Cluster ID): Each cluster has a unique ID number. This ID number is used to distinguish 
clusters and track each cluster. 
X and Y (Center Coordinates): In the K-means algorithm, each cluster represents a center 
(centroid). This center is calculated by taking the average of the coordinates of all the 
samples in the cluster. X and Y hold the coordinates representing this center. 
samples: This is the list of samples in the cluster. Each sample is considered a member of 
the cluster and each of them tends to be close to the center of the cluster. These samples 
are managed within the functionality of the class. 

Functions 

Constructor Function:The constructor function of the Cluster class determines the identity 
(ID) and initial center (X and Y coordinates) of the cluster when creating a cluster. This 
function initializes the data members of the class with the initial parameters required when 
creating the cluster. 

Instance Management:Instances in the cluster can be added with the addSample function. 
This function adds a new instance to the cluster's list of instances. In addition, the 
clearSamples function clears all instances belonging to the cluster and resets the list. This 
function is used to restart the cluster or delete instances. 

Center Calculation:In the K-means algorithm, the centers (centroids) of the clusters are 
updated at each iteration. The calculateCenter function calculates a new center by taking the 
average of the X and Y coordinates of all instances belonging to the cluster. If the new center 
is different from the old center, the function returns true, otherwise it returns false. This 
function dynamically updates the center by considering the location of the instances in the 
cluster. 
Access Functions:The functions that provide access to cluster information are getXofCluster, 
getYofCluster and getIDofCluster. These functions return the cluster center coordinates (X 
and Y) and the cluster ID, respectively. These access functions allow access to information 
about the cluster from outside the class. 

Print Function:The print function prints the cluster ID and center coordinates to the screen. 
This function is used to visualize cluster information and debug the analysis process. 

KMeans Class: 

The KMeans class is a class used to implement the K-means algorithm. This class divides 
the given dataset into K different clusters, classifies the samples for each cluster, updates the 
centers of the clusters, and both prints the results to the screen and saves them to a file. 

Data Members 

int K: Specifies the number of clusters in the K-means algorithm. 
string fileName: Holds the name of the input file. This file contains the sample data (for 
example, x, y coordinates and indices). 
string outputfileName: Holds the name of the output file. As a result of the K-means 
algorithm, the information about which cluster each sample belongs to will be recorded in this 
file. 

vector<Sample> samples: A vector where samples are stored. Each sample is added to this 
vector as a Sample object. These samples are read from the file and loaded and assigned to 
clusters in the K-means algorithm. 
vector<Cluster> clusters: A vector that holds clusters. Each cluster is added to this vector as 
a Cluster object. These clusters are structures where samples are grouped and their centers 
are calculated. 

Functions: 

Constructor Function; The constructor function of the KMeans class takes the file path, the 
number of clusters (K), and the name of the output file required to start the algorithm. 
 Checking the value of K: The number of clusters must be a positive number. If K is 
negative or zero, an invalid_argument error is thrown. 

 File Path and Output File: The file names are set with the corresponding setter 
functions. These functions determine the input file and the output file. 
 Loading Data: The loadSamples function reads the data from the input file and 
creates the Sample objects. 

 Creating Initial Clusters: The initialization function initializes the clusters using the first 
K samples. Each cluster is assigned an ID, and the coordinates of the samples 
corresponding to each cluster are determined as the initial centers. 
 K-means Update: The updateKM function initializes the K-means algorithm by 
updating the centers of the clusters. 

Destructor Function: The destructor function of the KMeans class is executed when the class 
object is destroyed. The printResults function prints the results of the samples and sets them 
to the screen. The SaveResultsToFile function saves the results of the samples to the 
specified file. 

Functions for Setting and Getting the File Path; getFileName and setFileName: Gets or sets 
the name of the input file. 

getOutputFileName and setOutputFileName: Gets or sets the name of the output file. 
Loading Data (loadSamples); The loadSamples function reads sample data from the 
specified file. Each sample is created as a Sample object and added to the sample vector. 
Initializing Clusters (initialize); The Initialize function is used to initialize clusters. This function 
takes the first K samples and creates a cluster for each sample. Each cluster is assigned an 
ID and the (x, y) coordinates of that sample are used as the center. These cluster objects are 
added to the cluster vector. 

Assign Samples to Clusters; The assignSamples To Clusters function assigns each sample 
to the nearest cluster. The samples in all clusters are deleted (the samples assigned in the 
previous steps are cleared). The Euclidean distance to the cluster centers is calculated for 
each sample. The sample is assigned to the nearest cluster and the sample is added to that 
cluster. 

K-means Update (updateKM); The updateKM function runs the K-means algorithm. The 
Assign Samples to Clusters function assigns the samples to the clusters. Update Cluster 
Centers: The calculateCenter function is called for each cluster and the centers are updated. 
If any centers change, the algorithm is run again. Loop: The algorithm continues as long as 
the centers do not change. When the centers do not change, the loop ends. 
Getter Functions 

getSamples: Returns the samples vector containing the samples. 
getClusters: Returns the clusters vector holding the cluster information. 
Printing Results (printResults); The printResults function prints the information of each 
sample to the screen. This information includes the index of the sample, its coordinates (x, y) 
and the cluster ID it belongs to. The printing process is done with the operator<< defined in 
the Sample class. 

Saving Results to File (saveResultsToFile); The saveResultsToFile function saves the results 
to the specified file. The output file is opened. Header lines are written to the file. The 
information of each sample is written to the file. The file is closed. If the file cannot be 
opened, an error message is printed. 

3-Conclusion 
The K-Means clustering algorithm implemented in C++ effectively grouped the data points 
into K clusters based on their proximity to each other in 2D space. The code successfully 
performed the initialization, iteration and fixation of cluster centers and displayed clear and 
accurate outputs both on the screen (Figure 1-2) and in the output file (Figure-3). 