#include "circle.h"
#include <iostream>
// constructor 
Circle::Circle( double radius , double center ):
  m_radius(radius),
  m_center(center)
{
 m_area=0.;
 m_num_in_area=0;
 m_num_out_area=0;
}

bool Circle::InCircle( double x , double y ){

  if ( (x-m_center)*(x-m_center) + (y-m_center)*(y-m_center)  < (m_radius*m_radius) ){
    return true;
  }
  else{
    return false;
  }

  return false;
}

void Circle::UpdateArea(){

  if (m_num_in_area < 1 && m_num_out_area < 1){
    std::cout << "Warning >>> There are no points registered! cannot update area!"<< std::endl;
    return;
  }
  m_area = (double) m_num_in_area / (double) ( m_num_in_area + m_num_out_area );
  
  return;
}

