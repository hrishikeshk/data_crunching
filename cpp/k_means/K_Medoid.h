#ifndef K_MEDOID
#define K_MEDOID

#include <vector>
#include "../TypeDefs.h"
#include "../Consts.h"

using Clustering = std::pair<std::vector<cluster_id>, std::vector<medoid_pos> >;

struct ClusteringOptions{
  Bool random_first_choice;
  Bool infer_num_clusters;
  Int32 num_iterations;
};

template <typename T>
Clustering attach_on_medoids(const std::vector<T>& points,
                                     std::vector<medoid_pos>& medoids);

template <typename T>
medoid_pos choose_medoid(const std::vector<T>& points, std::vector<medoid_pos>& cluster_point_idxs);

template <typename T>
std::pair<std::vector<cluster_id>, Bool> update_medoids(const std::vector<T>& points, const Clustering& current);

template <typename T>
Clustering make_clustering(const std::vector<T>& points, std::vector<medoid_pos>& initial, int k, int max_iterations);

#endif

