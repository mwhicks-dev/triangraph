#include <gtest/gtest.h>

#include "Triangle.h"

#include <cmath>

float tolerance = 0.001;

TEST(TriangleTest, TestEquilateral1) {
    tgr::CoordinatePlane g;

    grapph::vertex_t A = g.addVertex(0, 0);
    grapph::vertex_t B = g.addVertex(1, 0);
    grapph::vertex_t C = g.addVertex(0.5, sqrt(3) / 2.);

    tgr::Triangle t(g, A, B, C);


    std::vector<float> angles = t.getAngles();

    std::vector<float> expectedAngles = {60., 60., 60.};
    ASSERT_TRUE(abs(.43301 - t.getArea()) < tolerance);

    for (float angle : angles) {
        for (size_t i = 0; i < expectedAngles.size(); i++) {
            float expected = expectedAngles[i];
            if (abs(angle - expected) < tolerance) {
                expectedAngles.erase(expectedAngles.begin() + i);
                break;
            }
        }
    }

    ASSERT_EQ(0, expectedAngles.size());
}

TEST(TriangleTest, TestEquilateral2) {
    tgr::CoordinatePlane g;

    grapph::vertex_t A = g.addVertex(33.2, 115.);
    grapph::vertex_t B = g.addVertex(37.9, 115.);
    grapph::vertex_t C = g.addVertex(35.55, 115. + 4.7 * sqrt(3) / 2.);

    tgr::Triangle t(g, A, B, C);


    std::vector<float> angles = t.getAngles();

    std::vector<float> expectedAngles = {60., 60., 60.};

    ASSERT_TRUE(abs(9.56525 - t.getArea()) < tolerance);

    for (float angle : angles) {
        for (size_t i = 0; i < expectedAngles.size(); i++) {
            float expected = expectedAngles[i];
            if (abs(angle - expected) < tolerance) {
                expectedAngles.erase(expectedAngles.begin() + i);
                break;
            }
        }
    }

    ASSERT_EQ(0, expectedAngles.size());
}