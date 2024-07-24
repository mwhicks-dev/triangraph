#ifndef triangraph_CoordinatePlane_h
#define triangraph_CoordinatePlane_h

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

    };

}

#endif