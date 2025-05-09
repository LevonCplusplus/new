#ifndef EMPLSTATUS_H
#define EMPLSTATUS_H
#include <iostream>
#include <string>
enum class Role{Intern = 1, Junior, Middle, Senior};
enum class EmploymentType{ FullTime = 1, PartTime};
enum class Status { Active = 1, OnLeave, Inactive, Retired };
inline std::string RoletoString(const Role& role){            //Converts role to a string for display.
    if(role == Role::Intern )
    {
       return  "Intern";
    }
    else if(role == Role::Junior )
    {
       return "Junior";
    }
   else if(role == Role::Middle)
    {
       return "Middle";
    }
    else 
    {
        return  "Senior";
    }
}
inline std::string StatustoString(const Status & status){              //Converts status to a string for display.
    if(status == Status::Inactive)
    {
       return  "Inactive";
    }
    else if(status == Status::OnLeave)
    {
       return "Onleave";
    }
   else if(status == Status::Active)
    {
       return "Active";
    }
    else 
    {
        return  "Retired";
    } 
  
}
inline std:: string EmploymentTypetoString(const EmploymentType& type){            //Converts employment type to a string for display.
   if(type == EmploymentType:: FullTime)
   {
    return "Fulltime";
   }
   else{
    return "PartTime";
   }

}

#endif
