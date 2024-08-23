#include "hospital_management.h"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<Patient> patients;

void addPatient() {
  Patient pat;
  std::cout << "Enter Patient ID: ";
  std::cin >> pat.id;
  std::cout << "Enter Patient Name: ";
  std::cin.ignore();
  std::getline(std::cin, pat.name);
  std::cout << "Enter Blood Group: ";
  std::getline(std::cin, pat.bloodGroup);
  std::cout << "Enter Medical History: ";
  std::getline(std::cin, pat.history);
  std::cout << "Enter Disease: ";
  std::getline(std::cin, pat.disease);
  std::cout << "Enter Complications: ";
  std::getline(std::cin, pat.complications);
  std::cout << "Enter Address: ";
  std::getline(std::cin, pat.address);
  std::cout << "Enter CNIC: ";
  std::getline(std::cin, pat.cnic);
  std::cout << "Enter Last Visit Date: ";
  std::getline(std::cin, pat.lastVisitDate);
  std::cout << "Enter Ward Number: ";
  std::cin >> pat.wardNumber;

  patients.push_back(pat);

  std::ofstream file("patients.txt", std::ios::app);
  file << pat.id << " " << pat.name << " " << pat.bloodGroup << " "
       << pat.history << " " << pat.disease << " " << pat.complications << " "
       << pat.address << " " << pat.cnic << " " << pat.lastVisitDate << " "
       << pat.wardNumber << "\n";
  file.close();

  std::cout << "Patient added successfully!\n";
}

void calculatePatientBill() {
  int id;
  float hours;
  std::cout << "Enter Patient ID: ";
  std::cin >> id;
  std::cout << "Enter hours spent in the hospital: ";
  std::cin >> hours;

  for (const auto &pat : patients) {
    if (pat.id == id) {
      float bill = hours * 1000; // Simple calculation, can be adjusted based on
                                 // ward and facilities
      std::cout << "Patient's Bill: " << bill << "\n";
      return;
    }
  }
  std::cout << "Patient not found!\n";
}

void showPatients() {
  std::cout << "\nList of Patients:\n";
  for (const auto &pat : patients) {
    std::cout << "ID: " << pat.id << ", Name: " << pat.name
              << ", Blood Group: " << pat.bloodGroup
              << ", Disease: " << pat.disease << "\n";
  }
}
