#ifndef EMPLOYEE_H
#define EMPLOYEE_H 

#include <iostream>
#include <vector>
#include <string>
#include "employeestatus.h"

class Employee{
  static inline int genid = 100; 
  int m_Employid;
  std::string m_name;
  EmploymentType m_employmentType;
  Role m_role;
  Status m_status;
protected:
  double m_salary;
  double hoursWorked;
  double hoursWage;
public:
  Employee() = default;
  Employee(const std::string&,const std::string&);
  virtual void CalculateSalary() = 0;
  virtual void promote() = 0;
  void setRole(const Role& role);
  void setEmploymentType(const EmploymentType&);
  void display()const;

  double getSalary()const{
    return m_salary;
  }
  virtual ~Employee()= default;
  const Status& getStatus();
  void setStatus(const Status& newStatus);
  int GetEmployeeId()const;
  EmploymentType getEmploymentType()const;
  Role getRole()const;
  void displayRole()const;
  Employee& operator++();
  // virtual const Employee operator++(int) = 0;
  

};
#endif