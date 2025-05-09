#ifndef EMPLOYEE_MANAGM_H
#define EMPLOYEE_MANAGM_H 


#include "fulltimeemployee.h"
#include "parttimeemployee.h"
#include "employee.h"

class EmployeeManager{
   std:: vector <Employee*> m_femployees;
   std:: vector <Employee*> m_pemployees;
public:
   EmployeeManager():m_femployees(0),m_pemployees(0){}
   EmployeeManager (const EmployeeManager&) = delete;
   EmployeeManager& operator=(const EmployeeManager&) = delete;
   EmployeeManager(EmployeeManager&&)noexcept;
   EmployeeManager& operator=(EmployeeManager&&)noexcept;
  ~EmployeeManager();
   void CalculateSalary(Employee* );
   void AddEmployee(Employee*);
   void DisplayEmployeeDetails(Employee *)const;
   void ListAllEmployees()const;
   void UpdateEmployeeRole(Employee * emp, const Role& );
   void UpdateEmploymentType(Employee* emp ,const EmploymentType& );
   void EmployementTypeDisplay(Employee* emp);
   void RemoveEmployee(Employee * emp);
   Employee* SearchEmployees(const int)const;
   
};

#endif
