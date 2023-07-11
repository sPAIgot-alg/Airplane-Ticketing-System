#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include<Windows.h>
#include <iomanip>
#include <unordered_map>

using namespace std;

const string LOGIN_DETAILS_FILE = "Login_Details.txt";
const string BOOKING_DETAILS_FILE = "Booking_Details.txt";
const string SEAT_DETAILS_FILE = "Seat_Details.txt";
const string PAYMENT_DETAILS_FILE = "Payment_Details.txt";

// Structure to hold ticket information
struct Ticket {
    string id;
    string name;
    string boardingCity;
    string destinationCity;
    string seat;
    string ticketClass;
};
void intro() {
	cout << endl << endl << endl << endl << "\t\t\t\t\t"; Sleep(900);
	cout << "\n\t\t\t\t\t         ||||       ||||||| ||||||||||  ||||      ||||||| ||||||||||  |||| |||||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t        ||  ||      ||||||| |||    |||  ||||      ||||||| ||||  ||||  |||| |||| "; Sleep(200);
	cout << "\n\t\t\t\t\t       |||  |||       |||   ||||||||||  ||||        |||   ||||  ||||  |||| ||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t      ||||||||||      |||   |||||||     ||||        |||   ||||  ||||  |||| ||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t     |||      |||   ||||||| ||| ||||    ||||||||| ||||||| ||||  ||||  |||| |||| "; Sleep(200);
	cout << "\n\t\t\t\t\t    ||||       |||| ||||||| |||  |||||  ||||||||| ||||||| ||||  |||||||||| ||||||||||"; Sleep(200);
	cout << endl << endl << "\t\t\t"; Sleep(300);
	cout << "\n\t\t\t        |||||||||| ||||||| ||||||||| ||||  |||| ||||||||||  ||||||||| |||||||||| ||||||||||  |||| |||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t        |||||||||| ||||||| ||||||||| |||| |||   ||||        ||||||||| |||||||||| ||||  ||||  |||| ||||       ||||"; Sleep(200);
	cout << "\n\t\t\t           ||||      |||   |||       |||||||    |||||||     |||          ||||    ||||  ||||  |||| ||||           "; Sleep(200);
	cout << "\n\t\t\t           ||||      |||   |||       |||||||    |||||||     |||          ||||    ||||  ||||  |||| ||||  |||||||||"; Sleep(200);
	cout << "\n\t\t\t           ||||    ||||||| ||||||||| |||| |||   ||||        |||||||||    ||||    ||||  ||||  |||| ||||  |||  ||||"; Sleep(200);
	cout << "\n\t\t\t          ||||||   ||||||| ||||||||| ||||  |||| ||||||||||  |||||||||   ||||||   ||||  |||||||||| |||||||||  ||||"; Sleep(200);
	cout << endl << endl << "\t\t\t\t\t"; Sleep(300);
	cout << "\n\t\t\t\t\t         ||||||||| ||||   |||| ||||||||| |||||||||| ||||||||||  ||||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||      ||||   |||| ||||      |||||||||| ||||        ||||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||||||| ||||||||||| |||||||||    ||||    |||||||     ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         |||||||||        |||| |||||||||    ||||    |||||||     ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t              |||| ||||   ||||      ||||    ||||    ||||        ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||||||| ||||||||||| |||||||||   ||||||   ||||||||||  ||||  ||||  ||||"; Sleep(200);
	cout << endl << endl << endl << endl << endl << "\t\t\t\t\t\t\t"; Sleep(1000);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\tProject Prepared by:"; Sleep(400);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t--------------------"; Sleep(500);
	cout << "\n\n\t\t\t\t\t\t\t\tSidharth S Pai\t\t\t\t1RN20IS160"; Sleep(1000);
	cout << "\n\n\t\t\t\t\t\t\t\tSharanya R P\t\t\t\t1RN20IS143"; Sleep(3500);
	
	system("cls");
}
// Hash table to store tickets indexed by ticket ID
unordered_map<string, Ticket> ticketIndex;
struct SeatRecord {
	string RowA;
	string RowB;
	string RowC;
};

// Function to load login details from file
void loadLoginDetails() {
    ifstream loginFile(LOGIN_DETAILS_FILE);
    if (loginFile) {
        // Do nothing as we are not storing the login details in a data structure
        loginFile.close();
        Sleep(3500);
        system("cls");
    }
}

// Function to register a new user
bool registerUser() {
     string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if the username already exists in the file
    ifstream loginFile(LOGIN_DETAILS_FILE);
    if (loginFile) {
        string fileUsername, filePassword;
        while (loginFile >> fileUsername >> filePassword) {
            if (fileUsername == username) {
                cout << "Username already exists. Please try again." << endl;
                loginFile.close();
                return false;
            }
        }
        loginFile.close();
    }

    // Save the login details to the file
    ofstream loginFileOut(LOGIN_DETAILS_FILE, ios::app);
    if (loginFileOut) {
        loginFileOut << username << " " << password << endl;
        loginFileOut.close();
        cout << "Registration successful!" << endl;
        Sleep(3500);
        system("cls");
        return true;
    } else {
        cout << "Error saving registration details." << endl;
        return false;
    }
}



// Function to login an existing user
bool loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
	cout << endl;
    cout << "Enter password: ";
    cin >> password;
	cout << endl;

    // Check if the username and password match any entry in the file
    ifstream loginFile(LOGIN_DETAILS_FILE);
    if (loginFile) {
        string fileUsername, filePassword;
        while (loginFile >> fileUsername >> filePassword) {
            if (fileUsername == username && filePassword == password) {
                cout << "Login successful!" << endl;
                loginFile.close();
                Sleep(3500);
                system("cls");
                return true;
            }
        }
        loginFile.close();
    }

    cout << "Invalid username or password." << endl;
    return false;
}

// Function to generate a unique ticket ID
string generateTicketID() {
    // Generate a random 4-digit number
    srand(time(nullptr));
    int randomNum = rand() % 9000 + 1000; // Generates a random number between 1000 and 9999

    // Convert the random number to string format
    string ticketID = to_string(randomNum);

    return ticketID;
}
void Payment()
{
	string name, lname, cc, cvv;

	cout << endl << endl;
	system("cls");
	cout << "\nEnter Payment Details:" << endl;

	cout << "\nEnter First Name: ";
	cin >> name;

	cout << "\nEnter Last Name: ";
	cin >> lname;


check:
	cout << "\nEnter Credit/Debit Card Number (16 digits): ";
	cin >> cc;
	if (cc.length() != 16)
	{
		cout << "\nCC number must have a length of 16 only! \n";
		goto check;
	}
	else
		check2:
	cout << "\nEnter CVV (3 digits): ";
	for (int i = 0; i > -1; i++)
	{
		char temp;
		temp = _getch();
		if (temp != 13 && temp != 8)
		{
			_putch('*');
		}
		if (temp == 13)
		{
			break;
		}
		if (temp == 8 || temp == 127 && !cvv.empty())
		{
			cout << "\b \b";
			cvv.erase(cvv.size() - 1);
		}
		else
			cvv += temp;
	}
	if (cvv.length() != 3)
	{
		cout << "\n\nCVV number must have a length of 3 only! \n";
		cvv = "";
		goto check2;
	}
	else
	{
		
		cout << "\n\nYour payment is successfully processed!";
		
		fstream payfile;
		payfile.open("Payment_Details.txt", payfile.app);
		payfile << name << "-" << lname << "-" << cc << "-" << cvv << "\n";
		payfile.close();
	}
	cout << "\n\n";
	system("pause");
}
// Function to create a new ticket
void createTicket() {
    Ticket ticket;
    cout << "Enter passenger name: ";
    cin.ignore();
    getline(cin, ticket.name);
    cout << "Enter boarding city: ";
    getline(cin, ticket.boardingCity);
    cout << "Enter destination city: ";
    getline(cin, ticket.destinationCity);
    cout << "\n1) Economy\n2) Business\n\nPick class (1-2): ";
	string x;
	int y;

	for (int i = 0; i > -1; i++)
	{
		cin >> x;
		if (x == "1") {
			ticket.ticketClass += "Economy";
			y = 1;
			break;
		}
		else if (x == "2") {
			ticket.ticketClass += "Business";
			y = 2;
			break;
		}
		else
		{
			cout << "\n\nInvalid input! Please enter again (1-2): ";
		}
	}


	//Function to Select Payment:
	Payment();
	
	//Generating Flight No.
	system("cls");

    // Generate a unique ticket ID
    ticket.id = generateTicketID();

    // Check if the ticket ID already exists
    if (ticketIndex.find(ticket.id) != ticketIndex.end()) {
        cout << "Ticket already exists. Please try again." << endl;
        return;
    }

    // Show available seats and let the user select a seat
    // You can implement the seat selection logic based on your requirements
    // For simplicity, we are skipping the seat selection process in this example.
    //cout << "Available seats: ..." << endl;
    //cout << "Please select a seat: ";
    //cin >> ticket.seat;
fstream Seat;
	int count = 0, delimit = 0;
	string line;
	SeatRecord Seats[10];
	Seat.open("Seat_Details.txt");
	while (getline(Seat, line))
	{
		count++;
	}
	Seat.close();
	Seat.open("Seat_Details.txt");
	for (int j = 0; j < count; j++)
	{
		string line1;
		getline(Seat, line1);
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowA += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowB += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowC += temp;
		}
	}
	Seat.close();
	string RowName, SeatNum, FinalSeatNum;
	bool Flag = false;
	cout << "\n\nA" << "\t" << " B" << "\t" << " C" << "\t\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "\n\n" << Seats[i].RowA << "\t" << Seats[i].RowB << "\t" << Seats[i].RowC << "\t\n";
	}

	
	for (int x = 0; x > -1; x++)
	{
		cout << "\n\nEnter the row name that you chose: ";
		cin >> RowName;
		if (RowName != "A" && RowName != "B" && RowName != "C")
		{
			cout << "\n\nInvalid row, please try again. ";
		}
		else
			break;
	}
	for (int x = 0; x > -1; x++)
	{
		check7:
		cout << "\nEnter the seat number that you chose: ";
		cin >> SeatNum;
		if (SeatNum == "XX")
		{
			cout << "\n\nInvalid seat, please try again! \n";
			goto check7;
		}
		for (int i = 0; i < 10; i++)
		{
			if (RowName == "A")
			{
				if (SeatNum == Seats[i].RowA)
				{
					Seats[i].RowA = "XX";
					Flag = true;
					break;
				}
			}
			else if (RowName == "B")
			{
				if (SeatNum == Seats[i].RowB)
				{
					Seats[i].RowB = "XX";
					Flag = true;
					break;
				}
			}
			else if (RowName == "C")
			{
				if (SeatNum == Seats[i].RowC)
				{
					Seats[i].RowC = "XX";
					Flag = true;
					break;
				}
			}
		}


		if (Flag == false)
		{
			cout << "\n\nSeat number not found, please try again. \n";
		}
		else
			break;
	}
		FinalSeatNum = RowName + SeatNum;
		ofstream Del;
		Del.open("Seat_Details.txt", ios::trunc);
		Del.close();
		Del.open("Seat_Details.txt", ios::trunc);
		for (int i = 0; i < 10; i++)
		{
			Del << Seats[i].RowA << "-" << Seats[i].RowB << "-" << Seats[i].RowC << "-\n";
		}
		Del.close();
        ticket.seat=FinalSeatNum;
    // Add the ticket to the hash table
    ticketIndex[ticket.id] = ticket;

    // Save the ticket details to the file
    ofstream bookingFile(BOOKING_DETAILS_FILE, ios::app);
    if (bookingFile) {
        bookingFile << ticket.id << " " << ticket.name << " " << ticket.boardingCity << " "
                    << ticket.destinationCity << " " << ticket.seat << endl;
        bookingFile.close();
        cout << "Ticket created successfully!" << endl;
        Sleep(3500);
        system("cls");
    } else {
        cout << "Error saving ticket details." << endl;
    }
}

// Function to edit a reserved ticket
void editTicket() {
    string ticketID;
    cout << "Enter ticket ID: ";
    cin >> ticketID;
    

    // Check if the ticket ID exists
    if (ticketIndex.find(ticketID) != ticketIndex.end()) {
        Ticket& ticket = ticketIndex[ticketID];

        cout << "Enter new passenger name: ";
        cin.ignore();
        getline(cin, ticket.name);
        cout << "Enter new boarding city: ";
        getline(cin, ticket.boardingCity);
        cout << "Enter new destination city: ";
        getline(cin, ticket.destinationCity);

        // Show available seats and let the user select a seat
        // You can implement the seat selection logic based on your requirements
        // For simplicity, we are skipping the seat selection process in this example.
        // cout << "Available seats: ..." << endl;
        // cout << "Please select a seat: ";
        // cin >> ticket.seat;
fstream Seat;
	int count = 0, delimit = 0;
	string line;
	SeatRecord Seats[10];
	Seat.open("Seat_Details.txt");
	while (getline(Seat, line))
	{
		count++;
	}
	Seat.close();
	Seat.open("Seat_Details.txt");
	for (int j = 0; j < count; j++)
	{
		string line1;
		getline(Seat, line1);
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowA += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowB += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowC += temp;
		}
	}
	Seat.close();
	string RowName, SeatNum, FinalSeatNum;
	bool Flag = false;
	cout << "\n\nA" << "\t" << " B" << "\t" << " C" << "\t\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "\n\n" << Seats[i].RowA << "\t" << Seats[i].RowB << "\t" << Seats[i].RowC << "\t\n";
	}

	cout << "\n\n======================================\n";
	for (int x = 0; x > -1; x++)
	{
		cout << "\n\nEnter the row name that you chose: ";
		cin >> RowName;
		if (RowName != "A" && RowName != "B" && RowName != "C")
		{
			cout << "\n\nInvalid row, please try again. ";
		}
		else
			break;
	}
	for (int x = 0; x > -1; x++)
	{
		check7:
		cout << "\n\nEnter the seat number that you chose: ";
		cin >> SeatNum;
		if (SeatNum == "XX")
		{
			cout << "\n\nInvalid seat, please try again! \n";
			goto check7;
		}
		for (int i = 0; i < 10; i++)
		{
			if (RowName == "A")
			{
				if (SeatNum == Seats[i].RowA)
				{
					Seats[i].RowA = "XX";
					Flag = true;
					break;
				}
			}
			else if (RowName == "B")
			{
				if (SeatNum == Seats[i].RowB)
				{
					Seats[i].RowB = "XX";
					Flag = true;
					break;
				}
			}
			else if (RowName == "C")
			{
				if (SeatNum == Seats[i].RowC)
				{
					Seats[i].RowC = "XX";
					Flag = true;
					break;
				}
			}
		}


		if (Flag == false)
		{
			cout << "\nSeat number not found, please try again. \n";
		}
		else
			break;
	}
		FinalSeatNum = RowName + SeatNum;
		ofstream Del;
		Del.open("Seat_Details.txt", ios::trunc);
		Del.close();
		Del.open("Seat_Details.txt", ios::trunc);
		for (int i = 0; i < 10; i++)
		{
			Del << Seats[i].RowA << "-" << Seats[i].RowB << "-" << Seats[i].RowC << "-\n";
		}
		Del.close();
        // Update the ticket details in the file
        ofstream bookingFile(BOOKING_DETAILS_FILE);
        if (bookingFile) {
            for (const auto& pair : ticketIndex) {
                const Ticket& t = pair.second;
                bookingFile << t.id << " " << t.name << " " << t.boardingCity << " "
                            << t.destinationCity << " " << t.seat << endl;
            }
            bookingFile.close();
            cout << "Ticket updated successfully!" << endl;
            Sleep(3500);
            system("cls");
        } else {
            cout << "Error saving ticket details." << endl;
        }
    } else {
        cout << "Ticket not found." << endl;
    }
}

// Function to delete a reserved ticket
void deleteTicket() {
    string ticketID;
    cout << "Enter ticket ID: ";
    cin >> ticketID;

    // Check if the ticket ID exists
    if (ticketIndex.find(ticketID) != ticketIndex.end()) {
        // Remove the ticket from the hash table
        ticketIndex.erase(ticketID);

        // Update the ticket details in the file
        ofstream bookingFile(BOOKING_DETAILS_FILE);
        if (bookingFile) {
            for (const auto& pair : ticketIndex) {
                const Ticket& ticket = pair.second;
                bookingFile << ticket.id << " " << ticket.name << " " << ticket.boardingCity << " "
                            << ticket.destinationCity << " " << ticket.seat << endl;
            }
            bookingFile.close();
            cout << "Ticket deleted successfully!" << endl;
            Sleep(3500);
            system("cls");
        } else {
            cout << "Error saving ticket details." << endl;
        }
    } else {
        cout << "Ticket not found." << endl;
    }
}

// Function to print all booked tickets
void printBookedTickets() {
    cout << "List of booked tickets:" << endl;
    for (const auto& pair : ticketIndex) {
        const Ticket& ticket = pair.second;
        cout << "Ticket ID: " << ticket.id << endl;
        cout << "Passenger Name: " << ticket.name << endl;
        cout << "Boarding City: " << ticket.boardingCity << endl;
        cout << "Destination City: " << ticket.destinationCity << endl;
        cout << "Seat: " << ticket.seat << endl;
        cout << "-------------------" << endl;
        Sleep(5000);
        system("cls");
    }
}
/*void showTicketIndex() {
    cout << "Ticket Index:" << endl;
    for (const auto& entry : ticketIndex) {
        const string& username = entry.first;
        const Ticket& ticket = entry.second;
        cout << "Username: " << username << endl;
        cout << "Ticket ID: " << ticket.id << endl;
        cout << "Passenger Name: " << ticket.name << endl;
        cout << "Boarding City: " << ticket.boardingCity << endl;
        cout << "Destination City: " << ticket.destinationCity << endl;
        cout << "Seat: " << ticket.seat << endl;
        cout << "Ticket Class: " << ticket.ticketClass << endl;
        cout << "----------------------" << endl;
		Sleep(5000);
		system("cls");
    }
}*/
// Function to display the main menu and handle user choices
void displayMainMenu() {
    int choice;
     while (true) {
        cout << "\n\t\t\t\t\t\t\t\t\t\tAirline Reservation System\n" << endl;
        cout << "1. Create a New Ticket" << endl;
        cout << "2. Edit Reserved Ticket" << endl;
        cout << "3. Delete Reserved Ticket" << endl;
        cout << "4. Print Booked Tickets" << endl;
        cout << "5. Exit" << endl;
		//cout<<"6. Print Hash table\n"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
		cout<<endl;
        

        switch (choice) {
            case 1:
                createTicket();
                break;
            case 2:
                editTicket();
                break;
            case 3:
                deleteTicket();
                break;
            case 4:
                printBookedTickets();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                exit(0);
			//case 6:
			//showTicketIndex();
			break;
            default:
                cout << "Invalid choice. Please try again." << endl;
				Sleep(1500);
				system("cls");
        }
    }
    Sleep(3500);
        system("cls");
}


int main() {
    // Load login details and initialize the ticket index
    intro();
    loadLoginDetails();

    int loginChoice;
    while (true) {
        cout << "\t\t\t\t\t\t\t\t\t\tAirline Reservation System" << endl;
        cout << "1. Registration" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> loginChoice;
		cout<<endl;
        

        switch (loginChoice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    displayMainMenu();
                }
                break;
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
				Sleep(2500);
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
				Sleep(2500);
				system("cls");
        }
    }
    Sleep(3500);

system("cls");
    return 0;
}
