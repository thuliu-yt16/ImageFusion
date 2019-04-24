#include "mask.h"

namespace Fusion{
    Mask::Mask(const char* fname, int _n):Image(fname, _n){
        initMask();
    }
    void Mask::initMask(){
        for(int i = 0; i < w; i ++){
            for(int j = 0; j < h; j ++){
                Color c = getPixel(i, j);
            }
        }




        field = new int*[w];
        for(int i = 0; i < w; i ++){
            field[i] = new int[h];
            for(int j = 0; j < h; j ++){
                field[i][j] = OUTER;
            }
        }
        for(int i = 0; i < w; i ++){
            for(int j = 0; j < h; j ++){
                if(isWhite(i, j)){
                    field[i][j] = INNER;
                }
            }
        }
        for(int i = 0; i < w; i ++){
            for(int j = 0; j < h; j ++){
                if(field[i][j] == INNER){
                    if(field[i - 1][j] == OUTER ||
                        field[i + 1][j] == OUTER ||
                        field[i][j - 1] == OUTER || 
                        field[i][j + 1] == OUTER){
                        field[i][j] = EDGE;
                    }
                }
            }
        }
    }

    bool Mask::isWhite(int x, int y){
        return pixel[n * (w * y + x)] == 255 &&
               pixel[n * (w * y + x) + 1] == 255 &&
               pixel[n * (w * y + x) + 2] == 255;
    }
    int Mask::state(int x, int y){
        return field[x][y];
    }
    bool Mask::in(int x, int y){
        return field[x][y] == INNER;
    }
    bool Mask::edge(int x, int y){
        return field[x][y] == EDGE;
    }
    bool Mask::out(int x, int y){
        return field[x][y] == OUTER;
    }
}