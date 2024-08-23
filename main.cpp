#include "hospital_management.h"
#include <iostream>

void doctorMenu() {
  int choice;
  do {
    std::cout << "\nDoctor Management\n";
    std::cout << "1. Add Doctor\n";
    std::cout << "2. Show Doctors\n";
    std::cout << "3. Calculate Doctor's Pay\n";
    std::cout << "4. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      addDoctor();
      break;
    case 2:
      showDoctors();
      break;
    case 3:
      calculateDoctorPay();
      break;
    case 4:
      return;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  } while (true);
}

void patientMenu() {
  int choice;
  do {
    std::cout << "\nPatient Management\n";
    std::cout << "1. Add Patient\n";
    std::cout << "2. Show Patients\n";
    std::cout << "3. Calculate Patient's Bill\n";
    std::cout << "4. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      addPatient();
      break;
    case 2:
      showPatients();
      break;
    case 3:
      calculatePatientBill();
      break;
    case 4:
      return;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  } while (true);
}

void staffWardMenu() {
  int choice;
  do {
    std::cout << "\nStaff & Ward Management\n";
    std::cout << "1. Add Staff\n";
    std::cout << "2. Add Ward\n";
    std::cout << "3. Show Wards\n";
    std::cout << "4. Calculate Staff's Pay\n";
    std::cout << "5. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      addStaff();
      break;
    case 2:
      addWard();
      break;
    case 3:
      showWards();
      break;
    case 4:
      calculateStaffPay();
      break;
    case 5:
      return;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  } while (true);
}

int main() {
  int mainChoice;

  do {
    std::cout << "\n*** Hospital Management System ***\n";
    std::cout << "1. Doctor Management\n";
    std::cout << "2. Patient Management\n";
    std::cout << "3. Staff & Ward Management\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> mainChoice;

    switch (mainChoice) {
    case 1:
      doctorMenu();
      break;
    case 2:
      patientMenu();
      break;
    case 3:
      staffWardMenu();
      break;
    case 4:
      std::cout << "Exiting...\n";
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  } while (mainChoice != 4);

  return 0;
}
