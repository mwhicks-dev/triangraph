#include "Triangle.h"

#include <cmath>

using namespace tgr;

Triangle::Triangle(CoordinatePlane& g, grapph::vertex_t A, grapph::vertex_t B, 
        grapph::vertex_t C) : g(g) {
    // set vertices
    this->A = A;
    this->B = B;
    this->C = C;

    // find side lengths
    a = sqrt(
        pow(g.getVertexState(A).first - g.getVertexState(B).first, 2) +
        pow(g.getVertexState(A).second - g.getVertexState(B).second, 2)
    );
    
    b = sqrt(
        pow(g.getVertexState(B).first - g.getVertexState(C).first, 2) +
        pow(g.getVertexState(B).second - g.getVertexState(C).second, 2)
    );
    
    c = sqrt(
        pow(g.getVertexState(C).first - g.getVertexState(A).first, 2) +
        pow(g.getVertexState(C).second - g.getVertexState(A).second, 2)
    );
}

/// @brief https://www.cuemath.com/measurement/area-of-scalene-triangle/
float Triangle::getArea() {
    float s = (a + b + c) / 2.;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

/// @brief law of cosines
std::vector<float> Triangle::getAngles() {
    std::vector<float> angles;

    // calculate angles in radians
    angles.push_back(acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)));
    angles.push_back(acos((pow(c, 2) + pow(a, 2) - pow(b, 2)) / (2 * c * a)));
    angles.push_back(acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)));

    for (size_t i = 0; i < angles.size(); i++) { 
        angles[i] *= 180 / (4 * atan(1));
    }

    return angles;
}
