#ifndef tgr_Triangle_h
#define tgr_Triangle_h

#include "CoordinatePlane.h"

namespace tgr {

    class Triangle {

        CoordinatePlane& g;

        grapph::vertex_t A;

        grapph::vertex_t B;

        grapph::vertex_t C;

    public:

        Triangle(CoordinatePlane&, 
                grapph::vertex_t, grapph::vertex_t, grapph::vertex_t);

        float getArea();

        float getAngle(grapph::vertex_t);

    };

}

#endif