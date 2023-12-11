#include "complex.h"
#include <iostream>

using namespace std;

Complex2D::Complex2D(){
    x=0;
    y=0;
}

Complex2D::Complex2D(double _x){
    x=_x;
    y=_x;
}

Complex2D::Complex2D(double _x, double _y){
    x=_x;
    y=_y;
}

Complex2D::Complex2D(const Complex2D& c){
    x=c.x;
    y=c.y;
}

ostream& Complex2D::printOn(ostream& os) const{
    os<< x << "+" << y << "i " <<endl;
    return os;
}

void Complex2D::set_x(double _x){
    x=_x;
}

void Complex2D::set_y(double _y){
    y=_y;
}

void Complex2D::set_xy(double _x, double _y){
    x=_x;
    y=_y;
}

double Complex2D::get_x(){
    return x;
}

double Complex2D::get_y(){
    return y;
}

double Complex2D::get_radius() const{
    return sqrt(x*x+y*y);
}

void Complex2D::scale(double k){
    x*=k;
    y*=k;
}

void Complex2D::rotate(double theta){
    double x_temp=x;
    x=x*cos(theta)-y*sin(theta);
    y=x_temp*sin(theta)+y*cos(theta);
}


Complex2D operator + (const Complex2D& c1, const Complex2D& c2){
    Complex2D c3(c1.x+c2.x,c1.y+c2.y);
    return c3;
}

Complex2D operator - (const Complex2D& c1, const Complex2D& c2){
    Complex2D c3(c1.x-c2.x,c1.y-c2.y);
    return c3;
}

Complex2D operator * (const Complex2D& c1, const Complex2D& c2){
    Complex2D c3(c1.x*c2.x-c1.y*c2.y,c1.x*c2.y+c1.y*c2.x);
    return c3;
}

Complex2D operator / (const Complex2D& c1, const Complex2D& c2){
    Complex2D c3((c1.x*c2.x+c1.y*c2.y)/(c2.x*c2.x+c2.y*c2.y),(c1.y*c2.x-c1.x*c2.y)/(c2.x*c2.x+c2.y*c2.y));
    return c3;
}

Complex2D Complex2D::get_bar()const{
    Complex2D c(x,-y);
    return c;
}

Complex2D Complex2D::get_inverse()const{
    Complex2D c(x/(x*x+y*y),-y/(x*x+y*y));
    return c;
}

bool operator < (const Complex2D& c1, const Complex2D& c2){
    return c1.get_radius()<c2.get_radius();
}

bool operator > (const Complex2D& c1, const Complex2D& c2){
    return c1.get_radius()>c2.get_radius();
}