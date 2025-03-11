#include "employeemanagment.h"
int main(){
  
   EmployeeManager poxos;
   Employee* levon = new PartTimeEmployee("Levon","intern");
   poxos.AddEmployee(levon);
   poxos.ListAllEmployees();
   poxos.UpdateEmployeeRole(levon,Role::Junior);
   poxos.ListAllEmployees();
   return 0;
 
}
