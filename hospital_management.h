#ifndef HOSPITAL_MANAGEMENT_H
#define HOSPITAL_MANAGEMENT_H

#include <string>

// Doctor Structure
struct Doctor {
  std::string name;
  int id;
  float hourlyRate;
  std::string phoneNumber;
  std::string specialization;
  std::string address;
};

// Patient Structure
struct Patient {
  std::string name;
  int id;
  std::string bloodGroup;
  std::string history;
  std::string disease;
  std::string complications;
  std::string address;
  std::string cnic;
  std::string lastVisitDate;
  int wardNumber;
};

// Staff Structure
struct Staff {
  std::string name;
  int id;
  std::string jobTitle;
  float hourlyRate;
};

// Ward Structure
struct Ward {
  int wardNumber;
  int numberOfBeds;
  int availableBeds;
};

// Doctor-related functions
void addDoctor();
void calculateDoctorPay();
void showDoctors();

// Patient-related functions
void addPatient();
void calculatePatientBill();
void showPatients();

// Staff & Ward-related functions
void addStaff();
void calculateStaffPay();
void addWard();
void showWards();

#endif // HOSPITAL_MANAGEMENT_H
