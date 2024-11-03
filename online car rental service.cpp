#include <iostream>
#include <string>
using namespace std;
class Car 
{
public:
    int carid;
    string carname;
    float priceperh;
    Car* next;
    Car(int id, const string& name, float price) : carid(id), carname(name), priceperh(price), next(nullptr) {}
};

class Carll
{
public:
    Car* head;
    Carll() : head(nullptr) {}
    void addCar(int id, const string& name, float price) 
    {
        Car* newCar = new Car(id, name, price);
        newCar->next = head;
        head = newCar;
    }
    void displaycars() 
    {
        Car* current = head;
        cout << "\nAvailable Cars:\n";
        while (current) {
            cout << "Car ID: " << current->carid << ", Name: " << current->carname << ", Price per Hour: $" << current->priceperh << "\n";
            current = current->next;
        }
    }
};

class Carrents
{
public:
    Carll carList;
    void initializeCars() 
    {
        carList.addCar(1, "Toyota Hilux", 25.0);
        carList.addCar(2, "BMW 3 Series", 28.0);
        carList.addCar(3, "Ford Mustang", 30.0);
        carList.addCar(4, "Honda Civic", 20.0);
        carList.addCar(5, "Tesla Model S", 30.0);
        carList.addCar(6, "Chevrolet Silverado", 25.0);
        carList.addCar(7, "Volkswagen Golf", 22.0);
        carList.addCar(8, "Mercedes-Benz C-Class", 28.0);
        carList.addCar(9, "Audi A4", 27.0);
        carList.addCar(10, "Nissan Altima", 21.0);
        carList.addCar(11, "Jeep Wrangler", 26.0);
        carList.addCar(12, "Subaru Outback", 23.0);
    }
    void mainmsg()
    {
        cout << "Welcome to the Car Rental System!\n";
        cout << "We believe in the best and less. You will find the finest cars with the best deals here.\n";
        cout << "Please provide your details to proceed.\n";
    }
    char choose() 
    {
        char option;
        cout << "Choose an option:\n";
        cout << "1. Book a Car\n";
        cout << "2. Book a Meeting\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> option;
        return option;
    }
    void getuserdets(string& name, int& age, string& email, string& idCardNumber, string& dateOfIssue, bool isCarBooking)
    {
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your email: ";
        cin >> email;
        if (isCarBooking) 
        {
            cout << "Enter the date for issuing the car (YYYY-MM-DD): ";
            cin >> dateOfIssue;
            cout << "Enter your ID card number: ";
            cin >> idCardNumber;
        }
        else 
        {
            cout << "Enter your phone number: ";
            cin >> idCardNumber;
        }
    }

    void displayTotalAmount(float hours, float pricePerHour)
    {
        float totalAmount = hours * pricePerHour;
        cout << "Total Amount for " << hours << " hours: $" << totalAmount << "\n";
    }

    void bookCar() 
    {
        carList.displaycars();
        int carId;
        cout << "Enter the Car ID you want to book: ";
        cin >> carId;

        float hours;
        cout << "Enter how many hours you want to rent the car: ";
        cin >> hours;

        Car* selectedCar = findCarById(carId);
        if (selectedCar) 
        {
            displayTotalAmount(hours, selectedCar->priceperh);

            string confirmation;
            cout << "Do you want to proceed with the booking? (yes/no): ";
            cin >> confirmation;

            if (confirmation == "yes" || confirmation == "Yes")
            {
                cout << "Car with the car ID: " << carId << " booked successfully\n" << "Please visit the showroom for submitting your ID card copy and depositing money.\n";
                string pickupTime;
                cout << "Enter the time for picking up the car on the given date (HH:MM AM/PM): ";
                cin.ignore();
                getline(cin, pickupTime);
                cout << "Thank you for using our car rental service!\n";
            }
            else 
            {
                cout << "Booking canceled.\n";
            }
        }
        else 
        {
            cout << "Invalid Car ID. Booking cancelled.\n";
        }
    }

    void bookmeeting()
    {
        string meetingDate;
        cout << "Enter the date for the meeting (YYYY-MM-DD): ";
        cin >> meetingDate;
        cout << "Meeting booked successfully on " << meetingDate << " at ";
        srand(time(0));
        int hour = rand() % 12 + 1;
        int minute = rand() % 60;
        if (rand() % 2 == 0) 
        {
            cout << hour << ":" << (minute < 10 ? "0" : "") << minute << " AM\n";
        }
        else
        {
            cout << hour << ":" << (minute < 10 ? "0" : "") << minute << " PM\n";
        }
        cout << "Thank you for scheduling a meeting with us!\nLooking forward to meet you tomorrow";
    }
    Car* findCarById(int id) 
    {
        Car* current = carList.head;
        while (current)
        {
            if (current->carid == id) 
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

int main() 
{
    Carrents rs;
    rs.initializeCars();

    rs.mainmsg();

    char option = rs.choose();

    string name, email, idCardNumber, dateOfIssue;
    int age;

    if (option == '1')
    {
        rs.getuserdets(name, age, email, idCardNumber, dateOfIssue);
        rs.bookCar();
    }
    else if (option == '2') 
    {
        rs.getuserdets(name, age, email, idCardNumber, dateOfIssue);
        rs.bookmeeting();
    }
    else
    {
        cout << "Invalid .\n";
    }
    return 0;
}