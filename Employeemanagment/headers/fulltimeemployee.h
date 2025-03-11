#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H
#include "employee.h"
class FullTimeEmployee final:public Employee{
public:
  using Employee::Employee;
   
  // const FullTimeEmployee operator++(int){
  //   if(getRole() == Role::Senior){
  //     return *this;
  //   }
    
  //   FullTimeEmployee p (*this);
  //   setRole(static_cast<Role>(static_cast<int>(getRole())+1));
  //   return p; 
  // }
  void promote()
  {
    ++(*this);
  }
  void CalculateSalary(){

    m_salary = 2 * hoursWorked * hoursWage;
  }
};
#endif
