 #include "employee.h"
Employee:: Employee(const std::string& name,const std::string& Role):m_name(name){
    if(Role == "intern")
    {
        m_role = Role::Intern;
        m_salary = 200000;
    }
    else if(Role == "junior")
    {
        m_role = Role::Junior;
        m_salary = 300000;
    }
    else if(Role == "middle")
    {
        m_role = Role::Middle;
        m_salary = 400000;
    }
    else if(Role == "senior")
    {
        m_role = Role::Senior;
        m_salary = 7000000;
    }
    m_Employid = genid++;
}
int Employee:: GetEmployeeId()const{
    return m_Employid;
}

   
EmploymentType Employee:: getEmploymentType()const{
    return m_employmentType;
}
void Employee:: setRole(const Role& role){
    m_role = role;
    if(m_role == Role::Intern )
    {
       m_salary = 200000;
    }
    else if(m_role == Role::Junior )
    {
       m_salary = 300000;
    }
   else if(m_role == Role::Middle)
    {
       m_salary = 400000;
    }
    else 
    {
        m_salary = 700000;
    }
}
void Employee:: setEmploymentType(const EmploymentType & type){
   m_employmentType = type;
   
}
Role Employee:: getRole()const{
   
   return m_role; 
     
}
void Employee:: displayRole()const
{
    std::cout << RoletoString(m_role);
}


const Status& Employee:: getStatus()
{
    return m_status;
}
void Employee:: setStatus(const Status& newStatus)
{
    m_status = newStatus;
}



void Employee:: display()const{
   std::cout << "Name: " << m_name << "\tSalary: " << m_salary<<"\t";displayRole(); 
}
Employee& Employee:: operator++(){
    if(m_role == Role::Senior)
    {
        return *this;
    }
    m_role = static_cast<Role>(static_cast<int>(m_role)+1);
    return *this;
}

