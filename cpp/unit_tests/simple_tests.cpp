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
}

BOOST_AUTO_TEST_SUITE_END()

