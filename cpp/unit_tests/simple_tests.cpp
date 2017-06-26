#define BOOST_TEST_MODULE test_suite1
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "k_means/Point2D.h"
#include "k_means/K_Medoid.h"

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE ( test_suite1 )

BOOST_AUTO_TEST_CASE( simple_cluster1 ){
  Point2D p0(1.0, 2.0);
  Point2D p1(2.0, 1.0);
  std::vector<Point2D> points;
  points.push_back(p0);
  points.push_back(p1);

  std::vector<medoid_pos> initial(1, 0);
  auto clustering = make_clustering(points, initial, 1, 10);

  BOOST_REQUIRE(clustering.first[0] == 0);
  BOOST_REQUIRE(clustering.first[1] == 0);
  BOOST_REQUIRE(clustering.second[0] == 0);
}

BOOST_AUTO_TEST_CASE( simple_cluster2by2 ){
  Point2D p0(1.0, 2.0);
  Point2D p1(2.0, 1.0);

  Point2D p2(10.0, 2.0);
  Point2D p3(10.0, 1.0);
  std::vector<Point2D> points;
  points.push_back(p0);
  points.push_back(p1);
  points.push_back(p2);
  points.push_back(p3);

  std::vector<medoid_pos> initial(2, 0);
  initial[1] = 2;
  auto clustering = make_clustering(points, initial, 2, 10);

  BOOST_REQUIRE(clustering.first[0] == 0);
  BOOST_REQUIRE(clustering.first[1] == 0);

  BOOST_REQUIRE(clustering.first[2] == 1);
  BOOST_REQUIRE(clustering.first[3] == 1);

  BOOST_REQUIRE(clustering.second[0] == 0);
  BOOST_REQUIRE(clustering.second[1] == 2);

  initial[0] = 1; // with bad choice of initial medoids...
  initial[1] = 0;

  auto clustering2 = make_clustering(points, initial, 2, 10);

  BOOST_REQUIRE(clustering.first[0] == 0);
  BOOST_REQUIRE(clustering.first[1] == 0);

  BOOST_REQUIRE(clustering.first[2] == 1);
  BOOST_REQUIRE(clustering.first[3] == 1);

  BOOST_REQUIRE(clustering.second[0] == 0);
  BOOST_REQUIRE(clustering.second[1] == 2);
}

BOOST_AUTO_TEST_SUITE_END()

