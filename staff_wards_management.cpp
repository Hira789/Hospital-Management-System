#include "hospital_management.h"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<Staff> staffList;
std::vector<Ward> wards;

void addStaff() {
  Staff staff;
  std::cout << "Enter Staff ID: ";
  std::cin >> staff.id;
  std::cout << "Enter Staff Name: ";
  std::cin.ignore();
  std::getline(std::cin, staff.name);
  std::cout << "Enter Job Title: ";
  std::getline(std::cin, staff.jobTitle);
  std::cout << "Enter Hourly Rate: ";
  std::cin >> staff.hourlyRate;

  staffList.push_back(staff);

  std::ofstream file("staff.txt", std::ios::app);
  file << staff.id << " " << staff.name << " " << staff.jobTitle << " "
       << staff.hourlyRate << "\n";
  file.close();

  std::cout << "Staff added successfully!\n";
}

void calculateStaffPay() {
  int id;
  float hours;
  std::cout << "Enter Staff ID: ";
  std::cin >> id;
  std::cout << "Enter hours worked: ";
  std::cin >> hours;

  for (const auto &staff : staffList) {
    if (staff.id == id) {
      float pay = hours * staff.hourlyRate;
      std::cout << "Staff's Pay: " << pay << "\n";
      return;
    }
  }
  std::cout << "Staff not found!\n";
}

void addWard() {
  Ward ward;
  std::cout << "Enter Ward Number: ";
  std::cin >> ward.wardNumber;
  std::cout << "Enter Total Number of Beds: ";
  std::cin >> ward.numberOfBeds;
  std::cout << "Enter Number of Available Beds: ";
  std::cin >> ward.availableBeds;

  wards.push_back(ward);

  std::ofstream file("wards.txt", std::ios::app);
  file << ward.wardNumber << " " << ward.numberOfBeds << " "
       << ward.availableBeds << "\n";
  file.close();

  std::cout << "Ward added successfully!\n";
}

void showWards() {
  std::cout << "\nList of Wards:\n";
  for (const auto &ward : wards) {
    std::cout << "Ward Number: " << ward.wardNumber
              << ", Total Beds: " << ward.numberOfBeds
              << ", Available Beds: " << ward.availableBeds << "\n";
  }
}
