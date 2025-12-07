#include <iostream>
#include <vector> 
#include <string>
using namespace std;
int pid;
int did;


class Patient{
public:
    string name;
    int age;
    string gender;
    int ID;
    Patient(string n, int a, string g) {
        ID = pid;
        pid++;
        name = n;
        age = a;
        gender = g;
    }
};


class Doctor{
public:
    string name;
    int age;
    string gender;
    int ID;
    Doctor(string n, int a, string g){
        ID = did;
        did++;
        name = n;
        age = a;
        gender = g;
    }
};


class Appointment{
public:
    int patientID;
    int doctorID;
    string Date;
    Appointment(int pID, int dID, string date){
        patientID = pID;
        doctorID = dID;
        Date = date;
    }
};


vector<Patient> patients;
vector<Doctor> doctors;
vector<Appointment> appointments;

bool isdoctoravailable(int doctorID, string date){

    for (const auto &appointment : appointments)  // will check check in the vector through loop. We can use ....for (int i = 0; i < appointments.size(); i++)... 
    {
        if (appointment.doctorID == doctorID && appointment.Date == date)
        {
            return false;
        }
    }
    return true;
}


bool doespatientexists(int patientID){


    for (const auto &patient : patients)
    {
        if (patient.ID == patientID)
        {
            return true;
        }
    }
    return false;
}


bool doesdoctorexists(int doctorID){

    for (const auto &doctor : doctors)
    {
        if (doctor.ID == doctorID)
        {
            return true;
        }
    }
    return false;
}

void addpatient(){

    string n;
    int a;
    string g;
    cout << "Enter Patient Name(First Name only): " << endl;
    cin >> n;
    cout << "Enter Patient Age: " << endl;
    cin >> a;
    cout << "Enter the patient Gender(Male, Female or Others): " << endl;
    cin >> g;
    patients.push_back(Patient(n, a, g));
}

void adddoctor(){

    string n;
    int a;
    string g;
    cout << "Enter Doctor Name(First Name only): " << endl;
    (cin >> n);
    cout << "Enter Doctor Age: " << endl;
    cin >> a;
    cout << "Enter the Doctor Gender(Male, Female or Others): " << endl;
    cin >> g;
    doctors.push_back(Doctor(n, a, g));
}


void scheduleappointment(){

    int patientID;
    int doctorID;
    string Date;

    cout << "Enter Appointment Date in DD-MM-YYYY format: " << endl;
    cin >> Date;
    cout << "Enter Patient ID(Enter id from 1): " << endl;
    cin >> patientID;
    cout << "Enter Doctor ID(Enter id from 1): " << endl;
    cin >> doctorID;
    if (!doespatientexists(patientID))
    {
        cout << "Patient with ID " << patientID << " does not exist." << endl;
        return;
    }

    if (!doesdoctorexists(doctorID))
    {
        cout << "Doctor with ID " << doctorID << " does not exist." << endl;
        return;
    }

    if (!isdoctoravailable(doctorID, Date))
    {
        cout << "Doctor with ID " << doctorID << " is not available on " << Date << "." << endl;
        return;
    }

    Appointment newAppointment(patientID, doctorID, Date);
    appointments.push_back(newAppointment);
}

void viewpatients(){

    cout << "List of Patients: " << endl;
    for (const auto &patient : patients)
    {
        cout << "ID: " << patient.ID << ", Name: " << patient.name << ", Age: " << patient.age << ", Gender: " << patient.gender << endl;
    }
}


void viewdoctors(){

    cout << "List of Doctors: " << endl;
    for (const auto &doctor : doctors)
    {
        cout << "ID: " << doctor.ID << ", Name: " << doctor.name << ", Age: " << doctor.age << ", Gender: " << doctor.gender << endl;
    }
}

void viewappointments(){

    cout << "List of Appointments: " << endl;
    for (const auto &appointment : appointments)
    {
        cout << "Patient ID: " << appointment.patientID << ", Doctor ID: " << appointment.doctorID << ", Date: " << appointment.Date << endl;
    }
}


int main(){

    pid = 1;
    did = 1;
    int choice;

    do
    {
        cout << "\n1. Add Patient" << endl;
        cout << "2. Add doctors" << endl;
        cout << "3. Schedule Appointments" << endl;
        cout << "4. View Patients" << endl;
        cout << "5. View Doctors" << endl;
        cout << "6. View Appointments" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addpatient();
            break;
        case 2:
            adddoctor();
            break;
        case 3:
            scheduleappointment();
            break;
        case 4:
            viewpatients();
            break;
        case 5:
            viewdoctors();
            break;
        case 6:
            viewappointments();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cout << endl;
            cout << endl;
            break;
        }
    }
    while (choice != 0);

    return 0;
}