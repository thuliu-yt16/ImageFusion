#ifndef MATRIX_H
#define MATRIX_H
#include "defs.h"
namespace Fusion{
    class Matrix{
    public:
        vector<vector<pair<int, double> > > a;
        int m, n;
        Matrix(int m, int n);
        void add(int i, int j, double e);
        vector<double> dot(const vector<double>& x);
        void dot(const vector<double>& x, vector<double>& y);
        void solve(const vector<double>& b, vector<double>& x);
        void print();
    private:
        void init();
        double dist(const vector<double>& v1, const vector<double>& v2);
    };
}
#endif