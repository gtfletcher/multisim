#include <iostream>
#include <cstdlib>
#include <cmath>
#include "circle.h"
#include <random>

using namespace std;

double getcord ( double size , std::mt19937& ran ){

  unsigned int random = ran();
  //std::cout << "ran max is :" << ran.max() << " | random number is = " << random << std::endl;
  double cord = (double) (size * random ) / (double) ran.max() ;
  return cord;

}

int main (int argc, char *argv[]) {

  // Initialise program
  double size = 100;
  unsigned int max_iter = 100000;
  double mid = size / 2. ;

  // Create and instance of Circle
  Circle circ ( mid , mid );
  cout << " Setup circle with radius : " << mid << " and center : " << mid << endl; 

  std::random_device rd;
  std::mt19937 g(rd());

  double x = 0; // private
  double y = 0; // private
  for ( unsigned int a = 0 ; a< max_iter ; a++ ){
    x = getcord( size , g);
    y = getcord( size , g);

    bool inarea = circ.InCircle( x ,y );
    if (inarea){
      circ.AddinArea();
    }
    else{
      circ.AddoutArea();
    }
  }
  circ.UpdateArea();
  cout << "Total in : " << circ.get_in_num() << "  Total out : " << circ.get_out_num() << "  Fractional Area is :" << circ.get_area()  << " Total points: " << circ.get_in_num() + circ.get_out_num() << endl;


  
  return 0;
} 




