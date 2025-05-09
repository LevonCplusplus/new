#include "employeemanagment.h"
EmployeeManager::EmployeeManager(EmployeeManager&& other) noexcept
   {
       
       m_femployees = std::move(other.m_femployees);
       m_pemployees = std::move(other.m_pemployees);
   }
   EmployeeManager& EmployeeManager:: operator=(EmployeeManager&& other)noexcept
   {
      if(this == &other)
      {
        exit(-1);
      }
      m_femployees = std::move(other.m_femployees);
      m_pemployees = std::move(other.m_pemployees);
      return *this;
   }
EmployeeManager::~EmployeeManager()
   {
    for(int i = 0 ; i < m_femployees.size() ; ++i )
    {
        delete m_femployees[i];
    }
    for(int i = 0 ; i < m_pemployees.size() ; ++i )
    {
        delete m_pemployees[i];
    }
   }
void EmployeeManager:: AddEmployee( Employee* emp)
{
    if(!emp)
    {
        exit(-1);
    }
    if( emp -> getEmploymentType() == EmploymentType::PartTime )
    {
        m_pemployees.push_back(emp);
    }
    else{
        m_femployees.push_back(emp);
    }
}
void EmployeeManager:: CalculateSalary(Employee* emp){
        if(!emp)
        {
            exit(-1);
        }
         emp -> CalculateSalary();
   } 
void EmployeeManager:: DisplayEmployeeDetails(Employee * emp)const{
    if(!emp)
    {
        exit(-1);
    }
    emp ->display();
}
void EmployeeManager:: ListAllEmployees()const{
    for(int i = 0 ; i < m_pemployees.size() ; ++i )
    {
        m_pemployees[i] -> display();
    }
    for(int i = 0 ; i < m_femployees.size() ; ++i )
    {
        m_femployees[i] -> display(); 
    }
}

// Employee* SearchEmployees(const std::string&)const{
//     for(int i = 0;i < m_interns.size(); ++i){
//         m_interns[i] -> display();
//     }
//     for(int i = 0 ; i < m_pemployees.size() ; ++i )
//     {
//         m_pemployees[i] -> display();
//     }
//     for(int i = 0 ; i < m_femployees.size() ; ++i )
//     {
//         m_femployees[i] -> display(); 
//     }
// }
Employee* EmployeeManager:: SearchEmployees(const int id)const{
    for(int i = 0 ; i < m_pemployees.size() ; ++i )
    {
        if(m_pemployees[i] -> GetEmployeeId() == id)
        {
            return m_pemployees[i];
        }
    }
    for(int i = 0 ; i < m_femployees.size() ; ++i )
    {
        if(m_femployees[i] -> GetEmployeeId() == id)
        {
            return m_femployees[i];
        }
    }
    std::cout << "no such a employee" << std::endl;
    return  nullptr;
}
void EmployeeManager:: EmployementTypeDisplay(Employee* emp)
{
    if(emp == nullptr)
        {
            exit(-1);
        }
     
    std::cout << EmploymentTypetoString(emp -> getEmploymentType()) <<std::endl;
}
void EmployeeManager:: UpdateEmployeeRole(Employee* emp ,const Role& role)
{
    if(emp == nullptr)
    {
        exit(-1);
    }
    emp -> setRole(role);
    //emp -> CalculateSalary();
}
void EmployeeManager:: RemoveEmployee(Employee * emp)
{
    if(!emp)
    {
        exit(-1);
    }
    if(emp -> getEmploymentType() == EmploymentType::PartTime){
       for(int i = 0;i < m_pemployees.size(); ++i){
            
        if(m_pemployees[i] == emp)
            {
                delete m_pemployees[i];
                m_pemployees.erase(m_pemployees.begin()+i);
            }
        }
    }
    else{

        for(int i = 0;i < m_femployees.size(); ++i){

            if(m_femployees[i] == emp)
            {
                delete m_femployees[i];
                m_femployees.erase(m_femployees.begin()+i);
            }
        }
    }
}
void EmployeeManager:: UpdateEmploymentType(Employee * emp,const EmploymentType& type)
{
    if( emp == nullptr || emp -> getEmploymentType() == type)
    {
        exit(-1);
    }
   
    if( type == EmploymentType::PartTime){
       
        Employee * employee = new PartTimeEmployee;
       *employee = std::move(*emp);
       RemoveEmployee(emp);
       employee->setEmploymentType(type);
       m_pemployees.push_back(employee);
    }
    else{
        Employee * employee = new FullTimeEmployee;
       *employee = std::move(*emp);
       RemoveEmployee(emp);
       employee->setEmploymentType(type);
       m_femployees.push_back(employee);
    }
    
   
}
