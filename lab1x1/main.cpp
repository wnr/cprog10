#include "main.h"
#include "matrix.h"
#include "vector.h"
#include "helper.h"

#include <iostream>
#include <cstring>


int main(int argc,char** argv){

  //Vector<bool> a;

  //a.print();
 
  
  //printing different sized matrixes
  
  /*for(int i =0;i<100;i++){
        Matrix tmp(i/10,i%10);
        std::cout << tmp << std::endl;
    }*/

    //retrieving and setting elements
   /* Matrix t1(2,2);
    std::cout << "input t1:";
    std::cin >> t1;
    int x = t1[1][1];
    t1[0][0] = 1337;
    std::cout << t1 << "<-t1" << "x=" << x << std::endl;

    Matrix t2;
    t2 = t1;
    std::cout << t2 << "<-t2";
    */

  //creating identity matrixes
  /*for( int i = 0; i<5; i++){
    Matrix tmp(i);
    std::cout << tmp << " -- -- -- " << std::endl;
    }*/


    Matrix m(3);
    Matrix m2(4);
    
    std::cout << "m(3)="<<std::endl << m << std::endl;


    std::cin >> m >> m2;
    

    std::cout << "m="<<std::endl << m << std::endl;
    std::cout << "m2="<<std::endl << m2 << std::endl;
    
    Matrix ans;
    ans = m*(-m2);

    Matrix ref_matrix;
    std::cin >> ref_matrix;

    std::cout << "m*(-m2)=" << std::endl << ans << std::endl;
   
    std::cout << "referencevalue for m*(-m2) = " << std::endl << ref_matrix << std::endl; 

    
    std::cout << "m.transpose()=" << std::endl << m.transpose() << std::endl;

    std::cout << "referencevalue for transpose() = " << std::endl << m2 /* here m2 is the reference*/ << std::endl;


    std::cin >> m;

    std::cout << " test things with the empty matrix " << std::endl;
    ans = m*m;
    std::cout << " []*[]=" << ans << std::endl;
    ans = m.transpose();
    std::cout << " [].transpose()=" <<  ans << std::endl;
    ans = -m;
    std::cout << " -[]=" << ans << std::endl;
    ans = m+m;
    std::cout << " []+[]=" << ans << std::endl;
    ans = 3*m;
    std::cout << " 3[]=" << ans << std::endl;
    
    std::cin >> m >> m2;

    ans = m*m2;
    std::cout << " [ 1 2 3 ; 3 2 1]*[ -1 ; 2 ; -3 ] = " << std::endl << ans << std::endl;
    std::cout << " reference value " << std::endl << "[ -6 ; -2 ]" << std::endl;


    Matrix m3;

    std::cin >> m >> m2 >> m3;
    ans = m*m2*m3;
    std::cout << "[ 1 0 ; 0 1 ]*[ 13 ; 37 ]*[ -2 2 ] = " << std::endl << ans << std::endl;

    std::cout << "reference value " << std::endl << "[ -26 26 ; -74 74 ]" << std::endl;


    std::cin >> m;
    ans = m.transpose();
    std::cout << "m.transpose()=" << std::endl << ans << std::endl;
    std::cout << "reference value=" << std::endl << "[ 1 3 ; 2 2 ; 3 1 ] " << std::endl;


    /*Matrix neo(2,1);
    std::cout << "enter neo:";
    std::cin >> neo;
    Matrix mor(2,1);
    std::cout << "blue or red?";
    std::cin >> mor;
    Matrix trinity;
    trinity = neo + mor;
    std::cout << neo << " + " << mor << " = " << trinity << std::endl;
    */
 /*   
    std::string m_string = "[ 1 2 -3 ; 5 6 7 ; 17 -13 37 ]";
        
    Vector<std::string> m_i = Helper::split(m_string.substr(1,m_string.size()-2),";");
    
    Vector< Vector<std::string> > m_ij;
    
    for(std::size_t index=0; index < m_i.size(); index++){
        m_ij.push_back(Helper::split(m_i[index], " "));
    }
    
    std::cout << "m.size()=" << m_ij.size() << std::endl;
    std::cout << "m0.size()=" << m_ij[0].size() << std::endl;
    std::cout << "bajsapa " << m_ij[2][2] << std::endl;
*/    
    /*Matrix m;    
    while(1){
      std::cout << "input matrix plz, be careful with spacez!" << std::endl;
        std::cin >> m;
        std::cout << "---------" << std::endl;
        std::cout << m << std::endl;
	std::cout << "m_rows:" << m.rows() << " m_cols:" << m.cols() << std::endl;
    }*/
    return 0;

}


