#include "matrix.h"

namespace Fusion{
    Matrix::Matrix(int m, int n):m(m), n(n){
        init();
    }
    void Matrix::init(){
        for(int i = 0; i < m; i ++){
            a.push_back(vector<pair<int, double> >());
        }
    }
    void Matrix::add(int i, int j, double e){
        a[i].push_back(make_pair(j, e));
    }
    void Matrix::dot(const vector<double>& x, vector<double>& y){
        assert(x.size() == n);
        y.resize(m);
        for(int i = 0; i < m; i ++){
            double sum = 0;
            for(auto p: a[i]){
                sum += x[p.first] * p.second;
            }
            y[i] = sum;
        }
    }
    vector<double> Matrix::dot(const vector<double>& x){
        assert(x.size() == n);
        vector<double> y;
        y.clear();
        for(int i = 0; i < m; i ++){
            double sum = 0;
            for(auto p: a[i]){
                sum += x[p.first] * p.second;
            }
            y.push_back(sum);
        }
        return y;
    }
    double Matrix::dist(const vector<double>& v1, const vector<double>& v2){
        int size = v1.size();
        assert(size == v2.size());
        double sum = 0;
        for(int i = 0; i < size; i ++){
            sum += (v1[i] - v2[i]) * (v1[i] - v2[i]);
        }
        return sum;
    }
    void Matrix::solve(const vector<double>& b, vector<double>& x){
        assert(m == n);
        assert(x.size() == n);
        assert(b.size() == n);
        vector<double> last;
        do{
            last = x;
            for(int i = 0; i < n; i ++){
                double d = 0;
                double sum = b[i];
                for(auto p: a[i]){
                    if(p.first == i) d = p.second;
                    else{
                        sum -= last[p.first] * p.second;
                    }
                }
                x[i] = sum / d;
            }
        }while(dist(last, x) > EPS);
    }
    void Matrix::print(){
        for(int i = 0; i < m; i ++){
            for(auto p: a[i]){
                printf("(%d, %d): %.1f\n", i, p.first, p.second);
            }
        }
    }
}