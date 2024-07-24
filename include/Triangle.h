#ifndef tgr_Triangle_h
#define tgr_Triangle_h

#include "CoordinatePlane.h"

namespace tgr {

    class Triangle {

        CoordinatePlane& g;

        grapph::vertex_t A, B, C;

        float a, b, c;

    public:

        Triangle(CoordinatePlane&, 
                grapph::vertex_t, grapph::vertex_t, grapph::vertex_t);

        float getArea();

        std::vector<float> getAngles();

    };

}

#endif