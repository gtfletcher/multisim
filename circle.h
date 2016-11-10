#include <cmath>

class Circle {

private:
  double m_radius;
  double m_area;
  double m_center;
  unsigned int m_num_in_area;
  unsigned int m_num_out_area;
  
public:

  Circle( double radius , double center );
  bool InCircle( double x , double y );
  void UpdateArea();
  inline void AddinArea(){ m_num_in_area++ ; } ;
  inline void AddoutArea(){ m_num_out_area++ ; } ;

  inline unsigned int get_in_num(){ return m_num_in_area;  } ;
  inline unsigned int get_out_num(){ return m_num_out_area ; } ;
  inline double get_area() { return m_area ;} ;
};
