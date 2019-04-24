#ifndef IMAGE_H
#define IMAGE_H
#include "vector3.h"
namespace Fusion{
    class Image{
    public:
        int w;
        int h;
        int n;
        unsigned char* pixel;
        Image(int _w, int _h);
        Image(const char* fname, int _n);
        void save_png(const char* fname) const;
        void save_jpg(const char* fname) const;
        void drawPixel(int x,int y,Color color);
        // void show(const char* fname) const;
        Color getPixel(int x,int y) const;
        // ~Image();
        // void drawLine(double x0, double y0, double x1, double y1, Color color);
        void drawLine(int x0, int y0, int x1, int y1, Color color);
        bool isContour(int x0, int y0);
    private:
        void line(int x0, int y0, int x1, int y1, Color color);
    };
}
#endif