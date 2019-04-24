#ifndef MASK_H
#define MASK_H
#include "vector3.h"
#include "image.h"
namespace Fusion{
    #define OUTER 0
    #define EDGE 1
    #define INNER 2
    class Mask: public Image{
    public:
        Mask(const char* fname, int _n);
        bool isTransfer();
        int state(int x, int y);
        bool in(int x, int y);
        bool edge(int x, int y);
        bool out(int x, int y);
    private:
        int** field;
        void initMask();
        bool isWhite(int x, int y);
    };
}

#endif