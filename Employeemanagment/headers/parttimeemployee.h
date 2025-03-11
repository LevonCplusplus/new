#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H
#include "employee.h"

class PartTimeEmployee:public Employee{
public:
 using Employee::Employee;
  // const PartTimeEmployee operator++(int){
  //   if(getRole()== Role::Senior){
  //     return *this;
  //   }
  //   PartTimeEmployee p (*this);
  //   setRole(static_cast<Role>(static_cast<int>(getRole())+1));
  //   return p; 
  // }
  void promote()
  {
    ++(*this);
  }
      
  void CalculateSalary(){
    m_salary = hoursWorked * hoursWage;
  }
};
#endif