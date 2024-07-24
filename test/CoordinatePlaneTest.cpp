#include <gtest/gtest.h>

#include "CoordinatePlane.h"

TEST(CoordinatePlaneTest, TestVertexAdd1) {
    tgr::CoordinatePlane g;

    grapph::vertex_t v = g.addVertex({0.5, 1.5});

    std::pair<float, float> coordinates = g.getVertexState(v);

    ASSERT_FLOAT_EQ(0.5, coordinates.first);
    ASSERT_FLOAT_EQ(1.5, coordinates.second);
}

TEST(CoordinatePlaneTest, TestVertexAdd2) {
    tgr::CoordinatePlane g;

    grapph::vertex_t v1 = g.addVertex({0.5, 1.5});
    grapph::vertex_t v2 = g.addVertex({0.5, 1.5});

    std::pair<float, float> c1 = g.getVertexState(v1);
    std::pair<float, float> c2 = g.getVertexState(v2);

    ASSERT_FLOAT_EQ(c1.first, c2.first);
    ASSERT_FLOAT_EQ(c1.second, c2.second);
    ASSERT_NE(v1, v2);
}

TEST(CoordinatePlaneTest, TestVertexAdd3) {
    tgr::CoordinatePlane g;

    grapph::vertex_t v = g.addVertex(0.5, 1.5);

    std::pair<float, float> coordinates = g.getVertexState(v);

    ASSERT_FLOAT_EQ(0.5, coordinates.first);
    ASSERT_FLOAT_EQ(1.5, coordinates.second);
}

TEST(CoordinatePlaneTest, TestVertexAdd4) {
    tgr::CoordinatePlane g;

    grapph::vertex_t v1 = g.addVertex(0.5, 1.5);
    grapph::vertex_t v2 = g.addVertex(0.5, 1.5);

    std::pair<float, float> c1 = g.getVertexState(v1);
    std::pair<float, float> c2 = g.getVertexState(v2);

    ASSERT_FLOAT_EQ(c1.first, c2.first);
    ASSERT_FLOAT_EQ(c1.second, c2.second);
    ASSERT_NE(v1, v2);
}

TEST(CoordinatePlaneTest, TestEdgeAdd1) {
    tgr::CoordinatePlane g;

    grapph::vertex_t v1 = g.addVertex({0.0, 0.0});
    grapph::vertex_t v2 = g.addVertex({1., 2.5});

    grapph::edge_t e = g.addEdge(v1, v2);

    EXPECT_THROW(g.getEdgeState(e), std::invalid_argument);  // not necessary, but probably nice
    ASSERT_EQ(1, g.getNeighbors(v1).count(v2));
    ASSERT_EQ(1, g.getNeighbors(v2).count(v1));
}

TEST(CoordinatePlaneTest, TestEdgeAdd2) {
    tgr::CoordinatePlane g;

    grapph::vertex_t v1 = g.addVertex(0.0, 0.0);
    grapph::vertex_t v2 = g.addVertex(1., 2.5);

    grapph::edge_t e = g.addEdge(v1, v2);

    EXPECT_THROW(g.getEdgeState(e), std::invalid_argument);  // not necessary, but probably nice
    ASSERT_EQ(1, g.getNeighbors(v1).count(v2));
    ASSERT_EQ(1, g.getNeighbors(v2).count(v1));
}
