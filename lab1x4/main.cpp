#include <iostream>
#include "hypercube.h"

int main(){

    Hypercube<1> m1(3); //1-dim Hypercube (base case)
    Hypercube<2> m2(3); //2-dim
    Hypercube<4> m3(7); //4-dim
    m3[0][4][5][6] = 1337; //sets a element
    std::cout << m3[0][4][5][6] << std::endl; //check output
    m3[3][0][0][6] = 50;
    m2 = m3[3][0]; //acquire a subdomain of 4-dim Hypercube, one element is equal to 50, rest is 0, size of m2 will change to size of m3
    m2[5][2] = 24;
    std::cout << "m2[0][6] = "<< m2[0][6] << std::endl;
    std::cout << "m2[5][2] = "<< m2[5][2] << std::endl;
    std::cout << "m2[0][0] = "<< m2[0][0] << std::endl;

    const Hypercube<8> test;
    const Hypercube<4> cc(5);
    const Hypercube<3> smallcc = cc[0]; //copy of subdomain of const Hypercube
    Hypercube<3> smallc = cc[0];
    smallc[1][1][1] = 3;

    std::cout << "smallc[1][1][1] = "<< smallc[1][1][1] << std::endl; //0

    std::cout << "------------------[from labpek]--------------" << std::endl;

    Hypercube<3> n(7);
    Hypercube<6> m(5);
    m[1][3][2][1][4][0] = 7;
    Hypercube<3> t(5);
    t = m[1][3][2];
    t[1][4][0] = 2;
    std::cout << m[1][3][2][1][4][0] << std::endl; //7
    std::cout << t[1][4][0] << std::endl; //2


    return 0;
}
