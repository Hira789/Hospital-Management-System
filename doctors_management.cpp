#include "hospital_management.h"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<Doctor> doctors;

void addDoctor() {
  Doctor doc;
  std::cout << "Enter Doctor ID: ";
  std::cin >> doc.id;
  std::cout << "Enter Doctor Name: ";
  std::cin.ignore();
  std::getline(std::cin, doc.name);
  std::cout << "Enter Phone Number: ";
  std::getline(std::cin, doc.phoneNumber);
  std::cout << "Enter Specialization: ";
  std::getline(std::cin, doc.specialization);
  std::cout << "Enter Address: ";
  std::getline(std::cin, doc.address);
  std::cout << "Enter Hourly Rate: ";
  std::cin >> doc.hourlyRate;

  doctors.push_back(doc);

  std::ofstream file("doctors.txt", std::ios::app);
  file << doc.id << " " << doc.name << " " << doc.phoneNumber << " "
       << doc.specialization << " " << doc.address << " " << doc.hourlyRate
       << "\n";
  file.close();

  std::cout << "Doctor added successfully!\n";
}

void calculateDoctorPay() {
  int id;
  float hours;
  std::cout << "Enter Doctor ID: ";
  std::cin >> id;
  std::cout << "Enter hours worked: ";
  std::cin >> hours;

  for (const auto &doc : doctors) {
    if (doc.id == id) {
      float pay = hours * doc.hourlyRate;
      std::cout << "Doctor's Pay: " << pay << "\n";
      return;
    }
  }
  std::cout << "Doctor not found!\n";
}

void showDoctors() {
  std::cout << "\nList of Doctors:\n";
  for (const auto &doc : doctors) {
    std::cout << "ID: " << doc.id << ", Name: " << doc.name
              << ", Phone: " << doc.phoneNumber
              << ", Specialization: " << doc.specialization
              << ", Address: " << doc.address << ", Hourly Rate: $"
              << doc.hourlyRate << "\n";
  }
}
