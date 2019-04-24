#include "image.h"
#include "mask.h"
#include "matrix.h"
using namespace Fusion;
#define DN (4)
#define DX2 (142)
#define DY2 (146)
#define DX1 (-68)
#define DY1 (-99)
int getPos(vector<pair<int, int> >& set, int x, int y){
    int n = set.size();
    for(int i = 0; i < n; i ++){
        if(set[i].first == x && set[i].second == y){
            return i;
        }
    }
    assert(false);
}
int main(){
    Mask* mask = new Mask("assets/test1_mask1.png", 3);
    int mask_w = mask -> w;
    int mask_h = mask -> h;
    cout << mask_w << ' ' << mask_h << endl;
    Image* src = new Image("assets/test1_src.jpg", 3);
    Image* tgt = new Image("assets/test1_target.jpg", 3);
    int deltax = DX1;
    int deltay = DY1;

    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};

    vector<pair<int, int> > innerPos;
    vector<pair<int, int> > edgePos;
    vector<double> r, g, b;

    for(int i = 0; i < mask_w; i ++){
        for(int j = 0; j < mask_h; j ++){
            if(mask -> in(i, j)){
                innerPos.push_back(make_pair(i, j));
            }
        }
    }
    int in = innerPos.size();
    for(int i = 0; i < mask_w; i ++){
        for(int j = 0; j < mask_h; j ++){
            if(mask -> edge(i, j)){
                innerPos.push_back(make_pair(i, j));
            }
        }
    }
    int en = innerPos.size() - in;
    int n = in + en;
    vector<double> sr, sg, sb;
    sr.resize(n);
    sg.resize(n);
    sb.resize(n);
    Matrix m(n, n);
    for(int i = 0; i < in; i ++){
        pair<int, int> p = innerPos[i];
        Color c = Color(0, 0, 0);
        Color thisc = src -> getPixel(p.first, p.second);
        for(int d = 0; d < 4; d ++){
            int x = p.first + dx[d];
            int y = p.second + dy[d];
            c += thisc - src -> getPixel(x, y);
            int pos = getPos(innerPos, x, y);
            m.add(i, pos, -1);
        }
        m.add(i, i, 4);
        r.push_back(c.r);
        g.push_back(c.g);
        b.push_back(c.b);
        sr[i] = 0;
        sg[i] = 0;
        sb[i] = 0;
    }
    for(int i = in; i < n; i ++){
        pair<int, int> p = innerPos[i];
        Color edgec = tgt -> getPixel(p.first + deltax, p.second + deltay);
        m.add(i, i, 1);
        sr[i] = edgec.r;
        sg[i] = edgec.g;
        sb[i] = edgec.b;
        r.push_back(edgec.r);
        g.push_back(edgec.g);
        b.push_back(edgec.b);
    }
    m.solve(r, sr);
    m.solve(g, sg);
    m.solve(b, sb);
    for(int i = 0; i < in; i ++){
        int x = innerPos[i].first + deltax;
        int y = innerPos[i].second + deltay;
        tgt -> drawPixel(x, y, Color(sr[i], sg[i], sb[i]));
    }
    tgt -> save_jpg("assets/test1_result.jpg");
    return 0;
}