//File: pgm01.cpp
//Description:
//Last Update: 09/12/2016


#include<iostream>
#include <fstream>
using namespace std;

class Part
{
public:
	int partNum;
	string description;
	int quantity;
	float unitPrice;
};

void printAllParts(Part [], int);
void addPart(Part [], int&);
void fileIO();
void fileIOWrite();
void fileIORead();
void dispTotal(const Part list[], int size);
void editData(const Part list[], int size);

int main()
{
     /* this piece tell you that you can use Part to store info,
	 *  and access the info in object.variable fashion.
	 * 
	 * 
	Part p;
	p.partNum = 10;
	p.description = "This is a hammer. ";
	p.quantity = 100;
	p.unitPrice = 2.50;
	
	// lets verify we can compile and print
	cout<<"Part Number: "<<p.partNum<<endl;
	cout<<"Description: "<<p.description<<endl;
	cout<<"Quantity: "<<p.quantity<<endl;
	cout<<"Unit Price: "<<p.unitPrice<<endl;
	*/
	
	// try to read from file here.
	
	// big data structre: array of size 100
	Part arr[100];		//this is the array to hold objects.
	int count = 0 ;		// this is the cout to tell how many diff parts in array.
	
	
	// read from file and update arr[i].
	
	std::fstream file("inventory.txt", std::ios::in);
	// 	if file is good, then write to the file
	if(file)
	{	int i =0;
		int partNum = 0;
		std::string description = "";
		int quantity = 0;
		float unitPrice = 0;
		
		// use a loop to keep reading file.
		// if readinf file fails, the loop will end
		while(file >> partNum && i < 100)
		{
			
			file.ignore();
			std::getline(file, description);
			file >> quantity;
			file >> unitPrice;
			
			// copy info from local variables toa arry element var
			arr[i].partNum = partNum;
			arr[i].description = description;
			arr[i].quantity = quantity;
			arr[i].unitPrice = unitPrice;
			i++;
			count++;
		
		/*std::cout<<partNum<<std::endl;
		file << partNum<<std::endl;
		file << description<<std::endl;
		file << quantity<<std::endl; 
		file << unitPrice <<std::endl;
		
		std::cout<<"Writing file \"inventory.txt\" succeed."<<std::endl;
		* 
		* 
		*/
		
		cout<<"File read one record. "<<endl;
		}
	}

	else
	{
		std::cout<<"Error when writing to file \"inventory.txt\""<<std::endl;
	
	
	// close file when done.
	file.close();
	}
	

	
	
	
	
	//lets write a menu
	int choice = 0;
	cout<<"Welcome to Tiny Part Mgmt"<<endl;
	cout<<"**********************"<<endl;
	cout<<"1. Print the part"<<endl;
	cout<<"2. Create a new part"<<endl;
	cout<<"3. Modify a part"<<endl;
	cout<<"4. Print total"<<endl;
	cout<<"5. Exit the program"<<endl;
	cout<<"Dear user please make a choice: ";
	cin >> choice;
	while(cin.good() && choice != 5)
	{
		switch (choice){
		case 1:
			printAllParts(arr, count);
			break;
		case 2:
			cin.ignore();
			addPart(arr, count);
			break;
		case 3:
			editData(arr,count);
			break;
		case 4:
			dispTotal(arr, count);
			break;
		default:
			cout<<"Invalid choice"<<endl;
		}
		cout<<"Dear user please make a choice: ";
		cin>>choice;
	}
	
	 
	return 0;
}


void printAllParts(Part arr[], int count)
{
	if (cout == 0)
	{
		cout<<"Empty Inventory."<<endl;
		return;
	}
	
	for (int i = 0; i < count; i++){
		cout<<"Part Number: "	<< arr[i].partNum	<<endl;
		cout<<"Description: "	<<arr[i].description<<endl;
		cout<<"Quantitiy: "		<<arr[i].quantity	<<endl;
		cout<<"Unit Price: "	<<arr[i].unitPrice	<<endl;
	}
}
void addPart(Part arr[], int & count)
{
	cout<<"New part description: "<<endl;
	string desc;
	getline(cin, desc);
	
	cout<<"New part quantity: ";
	int quantity = 0;
	cin >>quantity;
	
	cout<<"New part unit price: ";
	float price =0;
	cin >> price;
	
	arr[count].partNum = count + 1;
	arr[count].description = desc;
	arr[count].quantity = quantity;
	arr[count].unitPrice = price;
	count++;
}

void editData(const Part list[], int count)
{

	cout << "
}

void dispTotal(const Part list[], int size) {
	double cost = 0;
	for (int i = 0; i < size; i++) {
	cost = cost + list[i].unitPrice * list[i].quantity;
	}
	cout << "\nTotal cost of inventory: $" << cost << endl;
}

/*void editData(const Part list[], int size) {
	Part arr[100];		//this is the array to hold objects.
	int count = 0 ;
	
	std::fstream file("inventory.txt", std::ios::in);
	// 	if file is good, then write to the file
	if(file)
	{	int i =0;
		int partNum = 0;
		std::string description = "";
		int quantity = 0;
		float unitPrice = 0;
				
		// use a loop to keep reading file.
		// if readinf file fails, the loop will end
		while(file >> partNum && i < 100)
		{
			
			file.ignore();
			std::getline(file, description);
			file >> quantity;
			file >> unitPrice;
			
			// copy info from local variables toa arry element var
			arr[i].partNum = partNum;
			arr[i].description = description;
			arr[i].quantity = quantity;
			arr[i].unitPrice = unitPrice;
			i++;
			count++;
		
		cout<<"File read one record. "<<endl;
		}
	}

	else
	{
		std::cout<<"Error when writing to file \"inventory.txt\""<<std::endl;
	
	
	// close file when done.
	file.close();
	}
*/	



