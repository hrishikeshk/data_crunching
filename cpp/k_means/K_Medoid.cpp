#include <vector>
#include <memory>
#include <algorithm>
#include "../TypeDefs.h"
#include "../Consts.h"
#include "../Common_Funcs.h"
#include "K_Medoid.h"

template <typename T>
Clustering attach_on_medoids(const std::vector<T>& points,
                                     std::vector<medoid_pos>& medoids){
  std::vector<cluster_id> point_clusters(points.size());
  for(int i = 0; i < points.size(); ++i){
    auto min = distance(points[0], points[medoids[0]]);
    cluster_id min_pos = 0;
    for(int j = 1; j < medoids.size(); ++j){
      auto dist = distance(points[i], points[medoids[j]]);
      if(dist < min){
        min = dist;
        min_pos = j;
      }
    }
    point_clusters[i] = min_pos;
  }
  return std::make_pair(point_clusters, medoids);
}

template <typename T>
medoid_pos choose_medoid(const std::vector<T>& points, std::vector<medoid_pos>& cluster_point_idxs){
  auto num_points = cluster_point_idxs.size();
  std::vector<typename T::DistType> summed_distances(num_points, 0.0);
  for(int i = 0; i < num_points; ++i){
    for(int j = 0; j < num_points; ++j){
      summed_distances[i] += distance(points[cluster_point_idxs[i]], points[cluster_point_idxs[j]]);
    }
  }
  auto min = summed_distances[0];
  medoid_pos min_pos = 0;
  for(int i = 1; i < num_points; ++i){
    if(min > summed_distances[i]){
      min = summed_distances[i];
      min_pos = i;
    }
  }
  return cluster_point_idxs[min_pos];
}

template <typename T>
std::pair<std::vector<cluster_id>, Bool> update_medoids(const std::vector<T>& points, const Clustering& current){
  auto& point_clusters = current.first;
  auto& medoids = current.second;
  std::vector<cluster_id> new_medoids(medoids.size());
  Bool medoid_changed = false;
  for(int i = 0; i < medoids.size(); ++i){
    std::vector<medoid_pos> filtered_point_idxs;
    for(int j = 0; j < point_clusters.size(); ++j){
      if(point_clusters[j] == i)
        filtered_point_idxs.push_back(j);
    }

    new_medoids[i] = choose_medoid(points, filtered_point_idxs);
    if(new_medoids[i] != medoids[i])
      medoid_changed = true;
  }
  return std::make_pair(new_medoids, medoid_changed);
}

template <typename T>
Clustering make_clustering(const std::vector<T>& points, std::vector<medoid_pos>& initial, int k, int max_iterations){
  v_assert(k > 0, "Invalid invocation: Number of desired clusters is less than 1...");
  v_assert(k == initial.size(), 
           "Invalid invocation: Initial medoid choice not specified as equal to number of clusters...");
  auto num_points = points.size(); 
  v_assert(num_points > 0, "Invalid invocation: Choose at least one point to cluster...");

  std::for_each(initial.begin(), initial.end(), [num_points](medoid_pos mp){
    v_assert(mp >= 0 && mp < num_points, std::string("Invalid invocation: Out of range medoid position: ") +  std::to_string(mp) );
  } );

  auto iterations = 0;
  auto& medoids = initial;

  while(iterations < max_iterations){
    auto current_clustering = attach_on_medoids(points, medoids);
    auto new_medoids_info = update_medoids(points, current_clustering);
    for(int i = 0; i < k; ++i){
      medoids[i] = new_medoids_info.first[i];
    }
    if(new_medoids_info.second == false)
      break;
    ++iterations;
  }
}

