#ifndef tgr_CoordinatePlane_h
#define tgr_CoordinatePlane_h

#include <grapph/include/FeatureGraph.h>

#include <stdexcept>

namespace tgr {

    /// @brief embedded graph with vertex coordinates
    class CoordinatePlane 
            : public grapph::FeatureGraph<std::pair<float, float>, char> {

        static char coordinatePlaneEdgeState(grapph::edge_t uw) { return '\0'; }

    public:

        CoordinatePlane() { setEdgeAutoState(coordinatePlaneEdgeState); }

        char getEdgeState(grapph::edge_t edge) {
            throw std::invalid_argument("Edges have no state");
        }

        grapph::vertex_t addVertex(std::pair<float, float> coordinates) { 
            return grapph::FeatureGraph<std::pair<float, float>, char>
                    ::addVertex(coordinates);
        }

        grapph::vertex_t addVertex(float x, float y) { 
            return grapph::FeatureGraph<std::pair<float, float>, char>
                    ::addVertex({x, y});
        }

    };

}

#endif