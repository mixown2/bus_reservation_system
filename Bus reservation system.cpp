#include <iostream>
#include <string>

using namespace std;

string buses[100],drivers_name[100],from[100],destination[100],departure_time[100],arrival_time[100];
string passanger[100][32];
string bus;
int index, seat;
string user_input;
string user_choice;


//function to add a bus
void addBus()
{

	cout << "\n\n\n"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << "\t\t\t\t\t\t\tADD BUS"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << endl;
	again:
	cout << "\t\t\t\tEnter Bus Number:-> ";
	cin >> buses[index];
	cout << endl;
	cin.ignore();
	cout << "\t\t\t\tDriver Name:->  ";
	getline(cin, drivers_name[index]);
	cout << endl;
	cout << "\t\t\t\tFrom:-> ";
	getline(cin, from[index]);
	cout <<endl;
	cout << "\t\t\t\tTo:-> ";
	getline(cin, destination[index]);
	cout << endl;
	cout << "\t\t\t\tDeparture Time:-> ";
	getline(cin, departure_time[index]);
	cout << endl;
	cout << "\t\t\t\tArrival Time:-> ";
	getline(cin, arrival_time[index]);
	cout << endl;
	cout << "\t\t\t\tBus added successfully!"<<endl;
	index++;
	cout << endl;
	cout << "\t\t\t Press 1 to Continue. Press any other key to go back to the menu... ";
	cin >> user_input;
	if (user_input == "1"){
		cout<<endl;
		goto again;
	}else {
		system("cls");
	}

}

//function for reservation
void reservation()
{
	again:
	cout << "\n\n\n"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << "\t\t\t\t\t\t\tRESERVE A SEAT"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << endl;
	cout << "\t\t\t\tEnter Bus Number:-> ";
	cin >> bus;
	cout << endl;
	int k = 0;
	sameBus:

		/*to check if there is a bus with that bus number already added if there is a bus then make reserve a seat
		else try again.
		*/

	for (int i = 0; i < 100; i++){
		if (buses[i] == bus){
			k++;
			cout << "\t\t\t\tEnter Seat(1-32):-> ";
			cin >> seat;
			cin.ignore();
			seat--;

			cout << endl;
			if (seat > 31 || seat  < 0){
				cout << "\t\t\t\tPlease Enter the correct seat number."<<endl;
				cout << endl;
				cout << "\tPress 1 to try agian. Press any key to go back to the menu... ";
				cin >> user_choice;
				if (user_choice == "1"){
					system("cls");
					goto again;
				}else {
					goto exit;
				}
			}
			if (!passanger[i][seat].empty()){
				cout << "\t\t\t\tThis seat is reserved" << endl;
				cout << endl;
				cout << "\tPress 1 to Enter another seat. Press any key to go back to the menu....";
				cin >> user_choice;
				if (user_choice == "1"){
					goto sameBus;
				}else {
					system("cls");
					goto exit;
				}
			}else {
				cout << "\t\t\t\tEnter Passenger Name:-> ";
				getline(cin, passanger[i][seat]);
				cout << endl;
			}
		}else {
			continue;
		}
	}

	if (k == 0){
		cout << "\t\t\t\tThere is no bus with this number currently!"<<endl;
		cout << endl;
		cout << "\tPress 1 to try again. Press any other key to go back to the menu... ";
		cin >> user_choice;
		if (user_choice == "1"){
			system("cls");
			goto again;
		}else{
			goto exit;
		}
	}else {
		cout  << "\tPress 1 to add a passenger on the same bus. Press 2 to add a passenger to another bus. Press any other key to go to the menu...  ";
		cin >> user_choice;
		cout << endl;
		if (user_choice == "1"){
			goto sameBus;
		}else if (user_choice == "2"){
			system("cls");
			goto again;
		}else {
			system("cls");
			goto exit;
		}
	}
	exit:
		system("cls");


}


//function to view reservation
void viewReservation()
{
	viewagain:
	cout << "\n\n\n"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << "\t\t\t\t\t\tVIEW RESERVATION"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << endl;
	cout << "\t\t\t\tEnter Bus Number:-> ";
	string bus;
	cin >> bus;
	cout << endl;
	cout << endl;
	int k = 0;
	int empty = 0;
	/*check if there is a bus with the same bus number if there is print reservation replace the empty sits with the string 'Empty'
	while printing.
	*/
	for(int i = 0; i<100; i++){
		if (buses[i] == bus){
			k++;
			int break_point= 0;
			cout <<"\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout <<"\t\t\t\t\t\t\t\t\tBUS "<< buses[i]<< endl;
			cout <<"\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout << "\t\t\t\t"<<"Drivers Name: "<<drivers_name[i];
			cout << "\t\t\t\t"<<"Arrival Time: "<<arrival_time[i];
			cout << "\t\t"<<"Departure Time: "<<departure_time[i];
			cout << endl;
			cout << "\t\t\t\t"<<"From: "<<from[i];
			cout<<"\t\t\t\t"<<"To: "<<destination[i]<<"\t";
			cout << endl;
			cout <<"\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout <<endl;
			for (int j =0; j<32; j++){
				if (!passanger[i][j].empty()){
					cout<< "\t\t\t"<<j+ 1 << ". " << passanger[i][j];
					cout << "    ";
				}else{
					cout<< "\t\t\t"<< j+ 1 <<". " << "Empty";
					cout << "    ";
				}
				break_point++;
				if (break_point == 4){
					cout << endl;
					break_point = 0;
				}
			}
		}else {
		}
	}
	if (k == 0){
		cout << "\t\t\t\tThere is no bus with this number currently!"<<endl;
		cout << endl;
		cout << "\t Press 1 to try again. Press any other key to go to the menu.... ";
		cin >> user_choice;
		if (user_choice == "1"){
			system("cls");
			goto viewagain;
		}else{
			system("cls");
		}
	}else {
		cout <<"\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
		cout << endl;
		for (int i =0; i<100;i++){
			if(buses[i] == bus){
				for (int j=0;j<32;j++){
					if (!passanger[i][j].empty()){
						cout << "\t\t"<< "Seat number " << j+1 << " is reserved for " << passanger[i][j]  <<"."<< endl;
					}else{
						empty++;
					}
				}
			}
		}
		for (int i = 1; i<=32; i++){
			if (i == 32){
				cout<<"\t\t" << "There are " << empty << " empty seats." << endl;
				cout << endl;
			}
		}
		cout  << "\tPress 1 to view another bus reservation. Press any other key to go to the menu...  ";
		cin >> user_choice;
		if (user_choice == "1"){
			system("cls");
			goto viewagain;
		}else {
		}
		system("cls");
	}
}


//function to view available buses
void viewAAvailableBuses()
{
	cout << "\n\n\n"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << "\t\t\t\t\t\tVIEW AVAILABLE BUSES"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << endl;
	int k = 0;

	/*search if there array buses[] is not empty if its not empty then print the available buses
	with the index of an array which is not empty.
	*/
	for (int i = 0; i< 100; i++){
		if(!buses[i].empty()){
			k++;
			cout <<"\t\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout <<"\t\t\t\t\t\t\t\t\tBUS "<< buses[i]<< endl;
			cout <<"\t\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout << "\t\t\t\t"<<"Drivers Name: "<<drivers_name[i];
			cout << "\t\t\t\t"<<"Arrival Time: "<<arrival_time[i];
			cout << "\t\t"<<"Departure Time: "<<departure_time[i];
			cout << endl;
			cout << "\t\t\t\t"<<"From: "<<from[i];
			cout<<"\t\t\t\t"<<"To: "<<destination[i]<<"\t";
			cout << endl;
			cout <<"\t\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout <<endl;
			cout << endl;
		}else {

		}
	}
	if (k == 0){
		cout << "\t\tThere is no available buses at the moment." << endl;
		cout << endl;
		cout << "\t\tPress any key to continue... ";
		cin >> user_choice;
	}else {
		cout << "\t\tPress any key to continue... ";
		cin >> user_choice;
	}
	system("cls");
}


//function to search available buses by destination.
void searchBus()
{
	again:
	cout << "\n\n\n"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << "\t\t\t\t\t\tSEARCH BUS"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << endl;
	string startingPoint;
	cin.ignore();
	cout << "\t\t\t\tFrom:->  ";
	getline(cin, startingPoint);
	cout << endl;
	cout << "\t\t\t\tTo:-> ";
	string to;
	getline(cin, to);
	cout << endl;
	int k = 0;

	// search if the destination match.
	for (int i = 0; i<100; i++){
		if ( from[i] == startingPoint && destination[i] ==  to){
			k++;
			cout <<"\t\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout <<"\t\t\t\t\t\t\t\t\tBUS "<< buses[i]<< endl;
			cout <<"\t\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout << "\t\t\t\t"<<"Drivers Name: "<<drivers_name[i];
			cout << "\t\t\t\t"<<"Arrival Time: "<<arrival_time[i];
			cout << "\t\t"<<"Departure Time: "<<departure_time[i];
			cout << endl;
			cout << "\t\t\t\t"<<"From: "<<from[i] << "\t";
			cout<<"\t\t\t\t"<<"To: "<<destination[i]<<"\t";
			cout << endl;
			cout <<"\t\t\t\t----------------------------------------------------------------------------------------------------------"<<endl;
			cout <<endl;
			cout << endl;
		}else {

		}
		}
		if (k == 0){
		cout << "\t\tThere is no available bus with this destination the moment." << endl;
		cout << endl;
		cout << "\t\tPress 1 to search again.Press any key to continue... ";
		cin >> user_choice;
		if (user_choice == "1"){
			system("cls");
			goto again;
		}
	}else {
		cout << "Press any key to continue... ";
		cin >> user_choice;
	}
	system("cls");
	}


// function to cancel reservation.
void cancleReservation()
{
	again:
	cout << "\n\n\n"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << "\t\t\t\t\t\tCANCLE RESERVATION"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << endl;
	cout << "\t\t\t\tEnter Bus Number:-> ";
	string bus;
	cin >> bus;
	cout << endl;
	int seat;
	sameBus:
	int k = 0;
	/*if the bus number matches the in one of the stored data ask for a seat number if its empty indicate its empty
	else replace the passanger array with that seat with empty string.
	*/
	for (int i = 0; i <100; i++){
		if (buses[i] == bus){
			k++;
			cout << "\t\t\t\tEnter Seat(1-32):-> ";
			cin >> seat;
			seat--;
			if (!passanger[i][seat].empty()){
				cout << endl;
				cout << "\tYou sure you want to cancel this reservation? ";
				cout << endl;
				cout << endl;
				cout << "\t1 for YES. 2 for NO... ";
				cin >> user_choice;
				cout << endl;
				if (user_choice == "1"){
					passanger[i][seat] = "";
					cout << "\tReservation cancelled successfully"<< endl;
					cout << endl;
					cout << "\tPress 1 to cancel reservation on the same bus. Press 2 to cancel reservation in another bus. Press any key to go to menu... ";
					cin >> user_choice;
					if (user_choice == "1"){
						goto sameBus;
					}else if (user_choice == "2"){
						system("cls");
						goto again;
					}else {
						goto exit;
					}
				}
				}else{
					cout << endl;
					cout << "\t This seat is already empty" << endl;
					cout << endl;
					cout << "\tPress 1 to try again. Press any key to go to menu... ";
					cin >> user_choice;
					if (user_choice == "1"){
						system("cls");
						goto again;
					}else {
						goto exit;
					}

				}

		}else {
			cout << "\tThere is no bus with this number" << endl;
			cout << endl;
			cout << "\tPress 1 to try again. Press any key to go to menu... ";
			cin >> user_choice;
			if (user_choice == "1"){
				system("cls");
				goto again;
			}else{
				goto exit;
			}
		}
	}
	if (k == 0){
		cout << "\t\tThere is no available buses at the moment." <<endl;
		cout << endl;
		cout << "\t\tPress 1 to try again. Press any other key to go to menu... ";
		cin >> user_choice;
		if (user_choice == "1"){
			system("cls");
			goto again;
		}else {

		}
	} else {

	}
	exit:
	system("cls");

}


// function to delete bus
void deleteBus()
{
	again:
	cout << "\n\n\n"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << "\t\t\t\t\t\tDELETE BUS"<<endl;
	cout << "\t\t\t\t========================================================" <<endl;
	cout << endl;
	cout << "\t\t\t\tEnter Bus Number:-> ";
	string bus;
	cin >> bus;
	cout << endl;
	int k = 0;
	for (int i = 0; i< 100; i++){
		if (buses[i] == bus ){
			k++;
			cout << "\tYou sure you want to Delete this Bus? ";
			cout << endl;
			cout << endl;
			cout <<"\t1 for YES, 2 for NO... ";
			cin >> user_choice;
			if (user_choice == "1"){
				buses[i] = "";
				cout << endl;
				cout << "\tBus deleted successfully!"<<endl;
				cout << endl;
				cout << "\t Press 1 to delete another bus. Press any other key to go to menu...  ";
				cin >> user_choice;
				if (user_choice == "1"){
					system("cls");
					goto again;
				}else {
					goto exit;
				}
			}else if (user_choice == "2"){
				system("cls");
				goto again;
			}else {

			}
		}
	}
	if (k == 0){
		cout << "\t\tThere is no bus with this number." <<endl;
		cout << endl;
		cout << "\t\tPress 1 to try again. Press any other key to go to menu... ";
		cin >> user_choice;
		if (user_choice == "1"){
			system("cls");
			goto again;
		}else {

		}
	} else {

	}
	exit:
	system("cls");

}

//main function.

int main()
{
	menu:
	cout <<"\n\n\n"<<endl;
	cout << "\t\t\t\t*******************************************************"<<endl;
	cout << "\t\t\t\t*\t    Anbessa Bus reservation system\t      *" << endl;
	cout << "\t\t\t\t*\t\t\t\t\t\t      *"<<endl;
	cout << "\t\t\t\t*******************************************************"<<endl;
	cout <<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << "\t\t\t\t|    1. Add Bus\t\t\t\t\t      |"<<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << "\t\t\t\t|    2. Reservation\t\t\t\t      |"<<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << "\t\t\t\t|    3. View Reservation\t\t\t      |"<<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << "\t\t\t\t|    4. View Available Buses\t\t\t      |"<<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << "\t\t\t\t|    5. Search Buses By Destination\t\t      |"<<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << "\t\t\t\t|    6. Cancel Reservation\t\t\t      |"<<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << "\t\t\t\t|    7. Delete Bus\t\t\t\t      |"<<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << "\t\t\t\t|    8. Exit\t\t\t\t\t      |"<<endl;
	cout << "\t\t\t\t-------------------------------------------------------"<<endl;
	cout << endl;
	cout << "\t\t\t\tEnter your Choice:-> ";
	cin >> user_choice;

	if (user_choice == "1"){
		system("cls");
		addBus();
		goto menu;
    }else if (user_choice == "2") {
    	system("cls");
    	reservation();
    	goto menu;
	}else if (user_choice == "3") {
		system("cls");
		viewReservation();
		goto menu;
	}else if (user_choice == "4") {
		system("cls");
		viewAAvailableBuses();
		goto menu;
	} else if (user_choice == "5"){
		system("cls");
		searchBus();
		goto menu;
	}else if (user_choice == "6"){
		system("cls");
		cancleReservation();
		goto menu;
	}else if (user_choice == "7"){
		system("cls");
		deleteBus();
		goto menu;
	}else if (user_choice == "8"){
		cout << endl;
		cout << "\t\t You Sure you want to exit the program?"<<endl;
		cout << endl;
		cout << "\t\t 1 for YES. 2 for NO... ";
		cin >> user_choice;
		if (user_choice == "1"){
			exit(1);
		}else {
			system("cls");
			goto menu;
		}
	}else {
		cout << endl;
		cout << "\t\t Please enter the correct input." << endl;
		cout << endl;
		cout << "\t\t Press any key to continue... ";
		cin >> user_choice;
		system("cls");
		goto menu;
	}
	cout << "mike Contribution" << endl;	
	return 0;
}

