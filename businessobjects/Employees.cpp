#include "Employees.h"

Employees::Employees(){
}
Employees::Employees(int EmployeeId,string  LastName,string  FirstName,string  BirthDate,string  Photo, string Notes ){
    this->EmployeeId=EmployeeId;
    this->LastName=LastName;
    this->FirstName=FirstName;
    this->BirthDate=BirthDate;
    this->Photo=Photo;
    this->Notes=Notes;
}
string Employees::ToString(){
    string s;
    s += "{";
    s += to_string(EmployeeId) + ", ";
    s += LastName + ", ";
    s += FirstName + ", ";
    s += BirthDate + ", ";
    s += Photo+ ", ";
    s += Notes;
    s += "}";
    return s;
}

/** @brief Function converts this object to json object.
 *  
 *  Function converts this object to json object.1  	Davolio  	Nancy  	12/8/1968  	EmpID1.pic  	Education includes a BA in psychology from Colorado State University. She also completed (The Art of the Cold Call). Nancy is a member of 'Toastmasters International'. 
 *  @return a json object;
 *  Example: Employees p(1, "Davolio", "Nancy", "12/8/1968", "EmpID1.pic", "Education includes a BA in psychology from Colorado State University. She also completed (The Art of the Cold Call). Nancy is a member of 'Toastmasters International'. ") -> {"EmployeeId":1,"LastName":"Nancy","FirstName":"Davolio","BirthDate":"12/8/1968","Photo":1,"Notes":"bottle"}
 */
json Employees::ToJson(){
    json j;
    j["EmployeeId"] = EmployeeId;
    j["LastName"] = LastName;
    j["FirstName"] = FirstName;
    j["BirthDate"] = BirthDate;
    j["Photo"] = Photo;
    j["Notes"] = Notes;
    return j;
}