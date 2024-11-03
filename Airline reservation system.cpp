#include <iostream>
#include <string>
using namespace std;

struct Passenger
{
    string name;
    Passenger* next;
};

struct Flight 
{
    string name;
    Passenger* passengers;
    Flight* next;
};

Flight* flights = NULL;

void initializeFlights()
{
   
    flights = new Flight;
    flights->name = "USA-01";
    flights->passengers = NULL;
    flights->next = new Flight;

    flights->next->name = "CANADA-02";
    flights->next->passengers = NULL;
    flights->next->next = new Flight;

    flights->next->next->name = "PAKISTAN-03";
    flights->next->next->passengers = NULL;
    flights->next->next->next = new Flight;

    flights->next->next->next->name = "ITALY-04";
    flights->next->next->next->passengers = NULL;
    flights->next->next->next->next = new Flight;

    flights->next->next->next->next->name = "GERMANY-05";
    flights->next->next->next->next->passengers = NULL;
    flights->next->next->next->next->next = NULL;
}
void displayFlights()
{
    Flight* f = flights;
    while (f != NULL) 
    {
        cout << f->name << endl;
        f = f->next;
    }
}

void reserveTicket()
{
    string flightName, passengerName;
    cout << "Select a flight:" << endl;
    displayFlights();
    cout << "Enter the name of the flight: ";
    cin.ignore();  
    getline(cin, flightName);  

    Flight* f = flights;
    while (f != NULL && f->name != flightName)
    {
        f = f->next;
    }

    if (f == NULL) 
    {
        cout << "Flight not found!" << endl;
        return;
    }

    cout << "Enter passenger name: ";
    cin >> passengerName;

    Passenger* p = new Passenger;
    p->name = passengerName;
    p->next = f->passengers;
    f->passengers = p;

    cout << "Ticket reserved successfully for " << passengerName << " on " << flightName << "!" << endl;
}

void cancelReservation() 
{
    string flightName, passengerName;
    cout << "Enter flight name: ";
    cin.ignore();  
    getline(cin, flightName);  
    cout << "Enter passenger name: ";
    cin >> passengerName;
    Flight* f = flights;
    while (f != NULL && f->name != flightName) 
    {
        f = f->next;
    }
    if (f == NULL) 
    {
        cout << "Flight not found!" << endl;
        return;
    }
    Passenger* p = f->passengers;
    Passenger* prev = NULL;
    while (p != NULL && p->name != passengerName)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL) 
    {
        cout << "Passenger not found!" << endl;
        return;
    }
    if (prev == NULL)
    {
        f->passengers = p->next;
    }
    else 
    {
        prev->next = p->next;
    }
    delete p;
    cout << "Reservation cancelled successfully!" << endl;
}

void checkReservation()
{
    string passengerName;
    cout << "Enter passenger name: ";
    cin.ignore();  
    getline(cin, passengerName);  
    Flight* f = flights;
    bool found = false;
    while (f != NULL)
    {
        Passenger* p = f->passengers;
        while (p != NULL) 
        {
            if (p->name == passengerName)
            {
                cout << "Passenger " << passengerName << " has a reservation on " << f->name << "." << endl;
                found = true;
                break;
            }
            p = p->next;
        }
        f = f->next;
    }
    if (!found)
    {
        cout << "Passenger not found!" << endl;
    }
}

int main() {
    initializeFlights();

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Reserve a ticket" << endl;
        cout << "2. Cancel a reservation" << endl;
        cout << "3. Check whether a ticket is reserved for a particular person" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            reserveTicket();
            break;
        case 2:
            cancelReservation();
            break;
        case 3:
            checkReservation();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);

    
    Flight* currentFlight = flights;
    while (currentFlight != NULL) {
        Passenger* currentPassenger = currentFlight->passengers;
        while (currentPassenger != NULL) {
            Passenger* nextPassenger = currentPassenger->next;
            delete currentPassenger;
            currentPassenger = nextPassenger;
        }
        Flight* nextFlight = currentFlight->next;
        delete currentFlight;
        currentFlight = nextFlight;
    }

    return 0;
}