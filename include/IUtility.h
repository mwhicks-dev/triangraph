#ifndef tgr_Utility_h
#define tgr_Utility_h

#include "Triangle.h"

#include <vector>

namespace tgr {

    /// @brief core utilities interface
    class IUtility {

    public:

        /// @brief check if two edges intersect
        /// @return true if edges intersect, false otherwise
        virtual bool doEdgesIntersect(grapph::edge_t, grapph::edge_t) = 0;

        /// @brief given a vertex, return triangles it neighbors
        /// @return vector of Triangles
        virtual std::vector<Triangle> getTrianglesAboutVertex(grapph::vertex_t) = 0;

        /// @brief given an edge, return triangles it neighbors
        /// @return vectir of Triangles
        virtual std::vector<Triangle> getTrianglesAboutEdge(grapph::edge_t) = 0;

    };

};

#endif