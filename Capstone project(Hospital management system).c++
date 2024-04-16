#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <cstdlib>  // For rand()
#include <conio.h>  // For getch()

using namespace std;

void showtime(); // Function declaration

int users = 0;
int count_attempt = 0;
int curr_user = 0;
string loggedin_user = "";

void showtime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "\t\t\t\t\t\t @copyassignment " << dt;
    cout << endl
         << endl;
}

void showDoctorsDetails() {
    system("cls");
    showtime();
    cout << "<==========================================================>" << endl;
    cout << "                     Dr. Waqar                              " << endl;
    cout << "           -----------Timing-----------                     " << endl;
    cout << "           Monday To Friday        9AM - 5PM                " << endl;
    cout << "           Saturday                10AM - 1PM               " << endl;
    cout << "           Sunday                  OFF                      " << endl;
    cout << "<==========================================================>" << endl;

    // Similar details for other doctors...
}

class Patient {
private:
    string name;
    int age;
    string contactNo;
    string symptoms;
    string treatment;

public:
    // Constructor to initialize patient details
    Patient(string n, int a, string c, string s, string t) : name(n), age(a), contactNo(c), symptoms(s), treatment(t) {}

    // Display patient details
    void display() {
        cout << "Patient Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact No: " << contactNo << endl;
        cout << "Symptoms: " << symptoms << endl;
        cout << "Treatment Required: " << treatment << endl;
        cout << endl;
    }
};

class user {
private:
    string username;
    string password;

public:
    void login() {
        if (curr_user == 1) {
            cout << "\t\t\t\t\t\t Already logged in";
            return;
        }
        if (count_attempt == 3) {
            cout << endl
                 << endl;
            cout << "\t\t\t\t\t\t No more attempts";
            exit(0);
        }
        cout << "Enter Username and Password to Login" << endl;
        string user_name;
        string pass_word;

        cout << "Username:";
        cin >> user_name;
        cout << "Password:";
        cin >> pass_word;
        cin.ignore();
        system("cls");

        // Check username and password (dummy check in this example)
        if (user_name == "admin" && pass_word == "password") {
            loggedin_user = user_name;
            showtime();
            cout << "\t\t\t\t\t\t Login Successful" << endl
                 << endl;
            cout << "\t\t\t===============================================================" << endl;
            cout << "\t\t\t                         Welcome Admin                         " << endl;
            cout << "\t\t\t===============================================================" << endl;
            curr_user = 1;
        } else {
            cout << "\t\t\t\t\t\t Incorrect Username or Password" << endl;
            cout << "\t\t\t\t\t\t Press Enter and Try again" << endl;
            cin.ignore();
            system("cls");
            count_attempt++;
            login();
        }
    }

    void logout() {
        cout << "Logout Successful" << endl;
        curr_user = 0;
    }
};

class hospital : public user {
public:
    void allAppointment() {
        if (loggedin_user == "") {
            cout << "\t\t\t\t\t\t Please Login" << endl;
            return;
        }

        // Fetch and display appointments (dummy output in this example)
        showtime();
        cout << "Appointments for today are" << endl
             << endl;
        cout << "Doctor: Dr. Sample" << endl;
        cout << "Patient Name: John Doe" << endl;
        cout << "Appointment Time: 10AM" << endl;
        cout << "Age: 30" << endl;
        cout << "Contact No: 1234567890" << endl;
        cout << "Symptoms: Fever" << endl;
        cout << endl;
    }

    void checkBeds() {
        if (loggedin_user == "") {
            cout << "\t\t\t\t\t\t Please Login" << endl;
            return;
        }

        system("cls");
        showtime();
        cout << endl;
        int random_no_of_beds = rand() % 200;
        cout << "Number of beds available today are: " << random_no_of_beds << endl;
    }

    void addPatient() {
        if (loggedin_user == "") {
            cout << "\t\t\t\t\t\t Please Login" << endl;
            return;
        }

        string name, contactNo, symptoms, treatment;
        int age;
        cout << "Enter patient name: ";
        cin >> name;
        cout << "Enter patient age: ";
        cin >> age;
        cout << "Enter patient contact number: ";
        cin >> contactNo;
        cout << "Enter patient symptoms: ";
        cin >> symptoms;
        cout << "Enter treatment required: ";
        cin >> treatment;

        Patient newPatient(name, age, contactNo, symptoms, treatment);
        // Here you can store the patient in a data structure or database
        // For simplicity, let's just display the patient details
        cout << "Patient added successfully!" << endl;
        newPatient.display();
    }

    void displayPatientDetails() {
        if (loggedin_user == "") {
            cout << "\t\t\t\t\t\t Please Login" << endl;
            return;
        }

        // Assuming you have a list of patients or some way to access patient details
        // For demonstration, let's create a dummy patient and display their details
        Patient dummyPatient("John Doe", 30, "1234567890", "Fever", "Medication");
        showtime();
        cout << "Displaying Patient Details:" << endl;
        dummyPatient.display();
    }
};

int main() {
    system("Color DE");
    showtime();
    cout << "\t\t\t==============================================================================" << endl;
    cout << "\t\t\t                          Hospital Management System                            " << endl;
    cout << "\t\t\t==============================================================================" << endl;
    user u1;
    int x;
    int choice = 0;
    hospital h;
    do {
        cout << endl;
        cout << "\t----------choose from below----------" << endl;
        cout << "\t1. Login" << endl;
        cout << "\t2. Available Doctors" << endl;
        cout << "\t3. Check All Appointments" << endl;
        cout << "\t4. Check no of beds available" << endl;
        cout << "\t5. Add Patient" << endl;
        cout << "\t6. Display Patient Details" << endl;
        cout << "\t7. Logout" << endl;
        cout << "\t0 to exit" << endl;
        cout << "\t-------------------------------------" << endl;
        cin >> x;
        switch (x) {
        case 1:
            u1.login();
            break;
        case 2:
            showDoctorsDetails();
            break;
        case 3:
            h.allAppointment();
            break;
        case 4:
            h.checkBeds();
            break;
        case 5:
            h.addPatient();
            break;
        case 6:
        	h.displayPatientDetails();
        	break;
        case 7:
            u1.logout();
            break;
        case 0:
            choice = 1;
            break;
        }
    } while (choice == 0);

    return 0;
}
