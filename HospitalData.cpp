/*
  Name: Nicholas Garcia
  Date: 07-19-2020
  Class: COSC 1437
  Used Bruce Gooch's example.
  Also used: https://www.geeksforgeeks.org/inheritance-in-c/
  https://www.programiz.com/cpp-programming/inheritance

*/

#include<iostream>
#include<string>

using namespace std;

class personType 
{
    public:
        void print() const;
        //Function to output the first name and last name
        //in the form firstName lastName.

        void setName(string first, string last);
        //Function to set firstName and lastName according
        //to the parameters.
        //Postcondition: firstName = first; lastName = last

        string getFirstName() const;
        //Function to return the first name.
        //Postcondition: The value of the data member firstName
        //               is returned.

        string getLastName() const;
        //Function to return the last name.
        //Postcondition: The value of the data member lastName
        //               is returned.

        personType(string first = "", string last = "", int age = 0);
        //constructor
        //Sets firstName and lastName according to the parameters.
        //The default values of the parameters are empty strings.
        //Postcondition: firstName = first; lastName = last

    private:
        string firstName;  //variable to store the first name
        string lastName;   //variable to store the last name
        int age;
};

class doctorType: public personType
{
    private:
        string specialty;
    
    public:
        doctorType(string first = "", string last = "", string specialty = "", int age = 0); //constructor
        void setSpecialty(string specialty);
        string getSpecialty();
        void setAge(int age);
        int getAge();
        //Function to return the doctors specialty.
    
};

doctorType::doctorType(string first, string last ,string doctor_speciality, int age_)
{
    setName(first,last);
   specialty=doctor_speciality;
}
void doctorType::setSpecialty(string doctor_speciality)
{
   specialty=doctor_speciality;
}
string doctorType::getSpecialty()
{
   return specialty;
}

//date functions
class dateType
{
    public:
        void setDate(int month, int day, int year);
        //Function to set the date.

        int getDay() const;
        //Function to return the day.

        int getMonth() const;
        //Function to return the month.

        int getYear() const;
        //Function to return the year.   

        void printDate() const;
        //Function to output the date in the form mm-dd-yyyy.

        dateType(int month = 1, int day = 1, int year = 1900);
        //Constructor to set the date
    private:
        int currMonth; //variable to store the month
        int currDay;   //variable to store the day
        int currYear; //variable to store the year
};

void dateType::setDate(int month, int day, int year)
{
    currMonth = month;
    currDay = day;
    currYear = year;
}
int dateType::getDay() const
{
    return currDay;
}
int dateType::getMonth() const
{
    return currMonth;
}
int dateType::getYear() const
{
    return currYear;
}
void dateType::printDate() const
{
    cout << currMonth << "-" << currDay << "-" << currYear;
}

//Constructor with parameters
dateType::dateType(int month, int day, int year)
{
    currMonth = month;
    currDay = day;
    currYear = year;
}

//subclass patientType inherits from personType
//also got help from https://www.tutorialspoint.com/nested-classes-in-cplusplus#:~:text=A%20nested%20class%20is%20a,members%20of%20a%20nested%20class.
class patientType :public personType
{
    private :
        int patientID;
        int age;
        dateType DOB;
        dateType admitDate;
        dateType dischargeDate;
        doctorType doctor;
    //public members functions of class
    public:
        patientType(string first, string last,int age,int patientID, dateType DOB,dateType admitDate,dateType dischargeDate,doctorType doctor);
        void setPatientID(int id);
        int getPatientID();
        void setAge(int age);
        int getAge();
        void setDOB(dateType DOB);
        dateType getDOB();
        void setAdmitDate(dateType admitDate);
        dateType getAdmitDate();
        void setDischargeDate(dateType dischargeDate);
        dateType getDischargeDate();
        void setdoctorName(doctorType doctor);
        string getdoctorName();
};

//constructor to set up patientType
patientType::patientType(string first, string last,int id,int patient_age, dateType dob,dateType admit_Date,dateType discharge_Date,doctorType doctor_)
{
    setName(first,last);
    age=patient_age;
    patientID=id;
    DOB=dob;
    admitDate=admit_Date;
    dischargeDate=discharge_Date;
    doctor=doctor_;

}
//inializes the functions
void patientType::setPatientID(int id)
{
    patientID=id;
}
void patientType::setAge(int age_)
{
    age=age_;
}
void patientType::setDOB(dateType dob)
{
    DOB=dob;
}
void patientType::setAdmitDate(dateType admit_Date)
{
    admitDate=admit_Date;
}
void patientType::setDischargeDate(dateType discharge_Date)
{
    dischargeDate=discharge_Date;
}
void patientType:: setdoctorName(doctorType doctor_)
{
    doctor=doctor_;
}

//gets data and return to function
int patientType::getPatientID()
{
    return patientID;
}
int patientType::getAge()
{
    return age;
}
dateType patientType::getDOB()
{
    return DOB;
}
dateType patientType::getAdmitDate()
{
    return admitDate;
}
dateType patientType::getDischargeDate()
{
    return dischargeDate;
}
string patientType::getdoctorName()
{
    return doctor.getFirstName().append(" "+doctor.getLastName());
}

//billType.h written
class billType
{
    private :
        int patientID;
        double medicineCharges;
        double doctorFee;
        double roomCharges;
    public:
        billType(int patientID=0,double medicineCharges=0,double doctorFee=0,double roomCharges=0 );
        void setMedicineCharges(double medicineCharges);
        double getMedicineCharges() const;
        void setDoctorFee(double doctorFee);
        double getDoctorFee() const;
        void setRoomCharges(double roomCharges);
        double getRoomCharges() const;
};
//constructor to set up billType
billType::billType(int id,double medicine,double doctor_fee,double room_Charge )
{
    patientID=id;
    medicineCharges=medicine;
    doctorFee=doctor_fee;
    roomCharges=room_Charge;

}
void billType::setMedicineCharges(double medicine)
{
    medicineCharges=medicine;
}
double billType::getMedicineCharges() const
{
    return medicineCharges;
}
void billType::setDoctorFee(double doctor_fee)
{
    doctorFee=doctor_fee;
}
double billType::getDoctorFee() const
{
    return doctorFee;
}
void billType::setRoomCharges(double room_Charges)
{
    roomCharges=room_Charges;
}
double billType::getRoomCharges() const
{
    return roomCharges;
}
//personType.cpp
void personType::print() const {
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last) {
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const {
    return firstName;
}

string personType::getLastName() const {
    return lastName;
}

//constructor
personType::personType(string first, string last, int a) {
    firstName = first;
    lastName = last;
    age = a;
}

//Main driver to call/test functions
int main()
{
    doctorType doctor("Devin","Oliver","Physician",63);
    cout<<"Doctor Info"<<endl;
    cout<<"Name: "<<doctor.getFirstName()<<" "<<doctor.getLastName()<<endl;
    cout<<"Speciality: "<<doctor.getSpecialty();

    dateType DOB(9,28,1999);
    dateType admitDate(10,2,2007);
    dateType dischargeDate(12,2,2020);
    patientType patient("Nicholas","Garcia",21,604363, DOB,admitDate,dischargeDate,doctor);
    cout<<"Patient Info"<<endl;
    cout<<"Name: "<<patient.getFirstName()<<" "<<patient.getLastName()<<endl;
    cout<<"Patient ID :"<<patient.getPatientID()<<endl;
    cout<<"Age: "<<patient.getAge()<<endl;
    cout<<"Date Of Birth: ";
    
    patient.getDOB().printDate();
    cout<<"\nDate Of Admission: ";

    patient.getAdmitDate().printDate();
    cout<<"\nDate Of Discharge: ";

    patient.getDischargeDate().printDate();
    cout<<"\nDoctor Name: "<<patient.getdoctorName()<<endl;

    billType patientBill(600,12000,1000,850);
    cout<<"Patient Bill"<<endl;
    cout<<"Medicine Cost: "<<patientBill.getMedicineCharges()<<endl;
    cout<<"Doctor Fee: "<<patientBill.getDoctorFee()<<endl;
    cout<<"Room Charges: "<<patientBill.getRoomCharges()<<endl;
    cout<<"Total pay: "<<patientBill.getMedicineCharges()+patientBill.getDoctorFee()+patientBill.getRoomCharges()<<endl;

    return 0;
}