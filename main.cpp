#include "complex.h"
#include <iostream>
#include <numbers>
#include <cmath>


int main(){
    Complex2D c1 = Complex2D();

    cout <<"complexe c1 :";
    c1.printOn(std::cout);

    Complex2D c2 = Complex2D(1.0);
    cout << "\n complexe c2 :";
    c2.printOn(std::cout);

    Complex2D c3 = Complex2D(1.0,2.0);
    cout << "\n complexe c3 :";
    c3.printOn(std::cout);

    Complex2D c4 = Complex2D(c3);
    cout << "\n complexe c4 :";
    c4.printOn(std::cout);

    c4.set_x(3.0);
    cout << "\n complexe c4 :";
    c4.printOn(std::cout);

    c4.set_y(4.0);
    cout << "\n complexe c4 :";
    c4.printOn(std::cout);

    c4.set_xy(5.0,6.0);
    cout << "\n complexe c4 :";
    c4.printOn(std::cout);

    cout << "\n c4.get_x() : " << c4.get_x() << endl;
    cout << "\n c4.get_y() : " << c4.get_y() << endl;

    cout << "\n c4.get_radius() : " << c4.get_radius() << endl;

    c3.scale(4.0);
    cout << "\n complexe c3 :";
    c3.printOn(std::cout);

    c3.rotate(M_PI);
    cout << "\n complexe c3 :";
    c3.printOn(std::cout);

    cout << "\n c3.get_bar() : ";
    c3.get_bar().printOn(std::cout);

    cout << "\n c2.get_inverse() : ";
    c2.get_inverse().printOn(std::cout);

    //test operateur +
    Complex2D c5 = c3+c4;
    cout << "\n Addition entre c3 et c4 :";
    c3.printOn(std::cout);
    cout << " + ";
    c4.printOn(std::cout);
    cout << " = ";
    c5.printOn(std::cout);

    //test operateur -
    Complex2D c6 = c3-c4;
    cout << "\n Soustraction entre c3 et c4 :";
    c3.printOn(std::cout);
    cout << " - ";
    c4.printOn(std::cout);
    cout << " = ";
    c6.printOn(std::cout);

    //test operateur *
    Complex2D c7 = c3*c4;
    cout << "\n Multiplication entre c3 et c4 :";
    c3.printOn(std::cout);
    cout << " * ";
    c4.printOn(std::cout);
    cout << " = ";
    c7.printOn(std::cout);

    //test operateur /
    Complex2D c8 = c3/c4;
    cout << "\n Division entre c3 et c4 :";
    c3.printOn(std::cout);
    cout << " / ";
    c4.printOn(std::cout);
    cout << " = ";
    c8.printOn(std::cout);

    //test operateur <

    cout << "\n c3 < c4 : " << (c3<c4) << endl;

    //test operateur >

    cout << "\n c3 > c4 : " << (c3>c4) << endl;





    return 0;
}