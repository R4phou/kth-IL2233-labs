#include <cmath>

// Task 1: Implement and evaluate K-means and SOM


/**
 * Implement the kMeans and SOM algorithms and evaluate their performance
 * Testing of the algorithm functions is facilitated by having the same calling interface
 * For both, we use the Euclidean distance as the distance metric
*/


double euclidean_distance(double *a, double *b, int m_features){
    double dist = 0;
    for(int i=0; i<m_features; i++){
        dist += (a[i] - b[i]) * (a[i] - b[i]);
    }
    dist = sqrt(dist);
    return dist;
}


/**
 * @param data: input data set
 * @param n_samples: number of samples
 * @param m_features: number of features
 * @param K: number of clusters
 * @param max_iter: maximum number of iterations the K-means updates
 * @param assignment: output cluster assignment for each samplegit@github.com:R4phou/kth-il2233.git as a list of integer int[n_samples]
 * 
 * The idea consists to:
 * 1. Initialize the centroids (a centroid is a mean of a cluster)
 * 2. Update the assignment of each sample to the nearest centroid
 * 3. Update the centroids
 * 4. Repeat steps 2 and 3 until convergence or here max_iter
*/
void kmeans(int* assignment, int K, int max_iter, int n_samples, int m_features, double *data){
    // Initialize the centroids
    double centroids[K][m_features]; // Initialize an array of K centroids 
    for(int i=0; i<K; i++){
        for(int j=0; j<m_features; j++){
            centroids[i][j] = data[i*m_features + j];
        }
    }

    // Initialize the assignment
    for(int i=0; i<n_samples; i++){
        assignment[i] = 0;
    }

    // Update the assignment
    for(int iter=0; iter<max_iter; iter++){


        for(int i=0; i<n_samples; i++){ // Iterating over all samples
            double min_dist = 1e9;
            for(int j=0; j<K; j++){ // Iterating over all centroids
                double dist = euclidean_distance(data + i*m_features, centroids[j], m_features);
            }
        }

        // Update the centroids - reset part
        int count[K];
        for(int i=0; i<K; i++){
            count[i] = 0;
            for(int j=0; j<m_features; j++){
                centroids[i][j] = 0;
            }
        }

        // Update the centroids - sum part
        for(int i=0; i<n_samples; i++){
            count[assignment[i]]++;
            for(int j=0; j<m_features; j++){
                centroids[assignment[i]][j] += data[i*m_features + j];
            }
        }

        // Update the centroids - average part
        for(int i=0; i<K; i++){
            for(int j=0; j<m_features; j++){
                centroids[i][j] /= count[i];
            }
        }
    }
}



struct t_pos{
    int x;
    int y;
};

/**
 * @param data: input data set
 * @param n_samples: number of samples
 * @param m_features: number of features
 * @param height: height of the SOM grid
 * @param width: width of the SOM grid
 * @param max_iter: number of iterations the SOM updates
 * @param assignment: output cluster assignment for each sample as a list of positions t_pos[n_samples]
 * @param lr: learning rate
 * @param sigma: rate that controls the weight update
*/
void SOM(t_pos *assignment, double *data, int n_samples, int m_features, int height, int width, int max_iter, float lr, float sigma){
    
}
