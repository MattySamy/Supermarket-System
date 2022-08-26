#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<utility>
#include<map>
#include<string.h>
using namespace std;
class Customers {
public:
	int Customer_ID, Customer_Age;
	char Customer_Name[50];
	float Number_of_Purchased_Products;
};
class Customer {
public:
	//char name[50];
	int i, counter, length;
	int head = -1, found = 0;
	fstream index;
	fstream Customer;

	Customers d;
	void Add_Customer() {
		map<int, int>k;
		Customer.open("Customer.txt", ios::out | ios::app);


		cout << " Enter the Customer Name :\n ";
		cin.getline(d.Customer_Name, 50);

		cout << " Enter Number of purchased products :\n ";
		cin >> d.Number_of_Purchased_Products;

		cout << " Enter Customer Age :\n ";
		cin >> d.Customer_Age;

		cout << " Enter Customer ID :\n ";
		cin >> d.Customer_ID;
		//strcpy(Customer_Age, Customer_Age + '\0');

		//Customersw();
		//map<int, int>k;
		//("Customer.txt", ios::out|ios::app|ios::in);
		//index.open("index.txt", ios::out | ios::app);

		//index.write((char*)&Customer_ID, sizeof(Customer_ID)); index.put('|'); index.write((char*)&length, sizeof(int));
		//Customer.seekg(0, ios::end);
		//length = Customer.tellp();
		Customer.seekp(0, ios::end);
		if (!Customer.tellp()) {

			Customer.write((char*)&head, sizeof(int));


		}

		/*
		if (head != -1)
		{

			int sizer;

			while (head != -1) {
				
				Customer.seekg(head, ios::beg);
				Customer.read((char*)&sizer, sizeof(int));
				Customer.read((char*)&head, sizeof(int));

				k[sizer] = head;

			}
			length = strlen(d.Customer_Name) + sizeof(d.Customer_ID) + sizeof(d.Customer_Age) + sizeof(d.Number_of_Purchased_Products);
			for (auto k : k) {
				if (length < k.first) {
					found++;
					sizer = k.first;
					head = k.second;
					break;
				}
			}
		}*/
		/*if (found > 0) {
			index.close();
			index.open("index.txt", ios::out | ios::binary);
			Customer.seekp(0, ios::end);
			i = Customer.tellp();
			index.write((char*)&d.Customer_ID, sizeof(d.Customer_ID));
			index.write((char*)&i, sizeof(int));
			Customer.seekp(head, ios::beg);
			length = strlen(d.Customer_Name) + sizeof(d.Customer_ID) + sizeof(d.Customer_Age) + sizeof(d.Number_of_Purchased_Products);
			Customer.write((char*)&length, sizeof(int)); Customer.put('|');
			//length = sizeof(Customer_Name());
			//Customer.write((char*)&length, sizeof(short));
			Customer.write((char*)&d.Customer_ID, sizeof(d.Customer_ID));
			Customer.write((char*)&d.Customer_Name, strlen(d.Customer_Name)); Customer.put('|');
			//length = sizeof(x);
			//Customer.write((char*)&length, sizeof(short));

			//length = sizeof(D);
			//Customer.write((char*)&length, sizeof(short));
			Customer.write((char*)&d.Customer_Age, sizeof(d.Customer_Age)); Customer.put('|');
			//length = sizeof(A);
			//Customer.write((char*)&length, sizeof(short));
			Customer.write((char*)&d.Number_of_Purchased_Products, sizeof(d.Number_of_Purchased_Products)); Customer.put('|');
			index.close();
		}*/
		//else {
			index.close();
			index.open("index.txt", ios::out | ios::app | ios::binary);
			Customer.seekp(0, ios::end);
			i = Customer.tellp();
			index.write((char*)&d.Customer_ID, sizeof(d.Customer_ID));
			index.write((char*)&i, sizeof(i));
			length = strlen(d.Customer_Name) + sizeof(d.Customer_ID) + sizeof(d.Customer_Age) + sizeof(d.Number_of_Purchased_Products);
			Customer.write((char*)&length, sizeof(int)); Customer.put('|');
			Customer.write((char*)&d.Customer_ID, sizeof(d.Customer_ID));
			Customer.write(d.Customer_Name, strlen(d.Customer_Name)); Customer.put('|');

			

			Customer.write((char*)&d.Customer_Age, sizeof(d.Customer_Age)); Customer.put('|');

			Customer.write((char*)&d.Number_of_Purchased_Products, sizeof(d.Number_of_Purchased_Products)); Customer.put('|');
		
		//}
		index.close();
		Customer.close();

		//}

	}
	void Display_All_Customers() {
		ifstream Customer("Customer.txt", ios::app | ios::in);
		index.open("index.txt", ios::in | ios::binary);
		int s = 0;
		//	char x;
		int offset;
			//char a[50], d[50], G[50], name[50], l[50];
		string  Customer_Name;
		char l;
		int id;
		//Customer.seekg(4, ios::beg);
		char x;
		while (1) {
			
			index.read((char*)&id, sizeof(id));
			index.read((char*)&offset, sizeof(offset));
			Customer.seekg(offset, ios::beg);
			
			Customer.read((char*)&length, sizeof(int)); Customer.get(x);
			

			Customer.read((char*)&d.Customer_ID, sizeof(d.Customer_ID));
			getline(Customer, Customer_Name, '|');
			Customer.read((char*)&d.Customer_Age, sizeof(d.Customer_Age)); Customer.get(l);
			Customer.read((char*)&d.Number_of_Purchased_Products, sizeof(d.Number_of_Purchased_Products)); Customer.get(l);
			
			/*
			getline(Customer, c, '|');
			getline(Customer, l, '|');
			*/

			if (Customer.eof() != 0 || index.eof()!=0)
				break;
			++s;
			if (x != '#')
			{
				cout<<"<<<<<<<<<<<<<<<<<<<<<<<<< Customer Data No. "<< s << ">>>>>>>>>>>>>>>>>>>>>>>>>";
				cout << "\n============================================================================================================================================\n";
				cout << "the Size of Record is : " << length << "\t Customer Name : " << Customer_Name << "\t Customer ID : " << d.Customer_ID << "    " << "\t Customer Age : " << d.Customer_Age << "\t Number of Purchased Products : " << d.Number_of_Purchased_Products;
				cout << "\n============================================================================================================================================\n";
			}
			

		}
		Customer.close();
		index.close();
	}
	void Search_Customer(int number) {
		ifstream index, Customer;
		char l[8]; int n;
		index.open("index.txt", ios::in | ios::binary);
		Customer.open("Customer.txt", ios::in);

		int c = 0;
		char h;
		string A, N;
		do {
			index.read((char*)&d.Customer_ID, sizeof(d.Customer_ID));

			index.read((char*)&i, sizeof(i));
			cout << "the Customer ID : " << d.Customer_ID << endl;
			cout << "Offset of Record : " << i << endl;
			/*
			Customer.read((char*)&length, sizeof(short));
			Customer.read((char*)&length, sizeof(short));
			Customer.read((char*)&name, length);
			Customer.read((char*)&length, sizeof(short));
			Customer.read((char*)&x, length);
			Customer.read((char*)&length, sizeof(short));
			Customer.read((char*)&D, length);
			Customer.read((char*)&length, sizeof(short));
			Customer.read((char*)&A, length);

			*/
			// iam delet the element name x
			cout << "The Compare Number is : " << number<<"\t\t Customer ID is : "<< d.Customer_ID << endl;
			if (number == d.Customer_ID) {
				c++;
				break;
				//cout << name << "\t\t " << x << "\t\t " << D << "\t\t " << A << endl;
				//cout << "\n==========================================================================\n";

			}
			//	if (!index.eof())
					//break;

		} while (index.good());

		index.close();
		if (c == 0) {
			cout << "The Customer isn't Found :(\n";
		}
		else {
			char l;
			string  Customer_Name;
			char x;

			Customer.seekg(i, ios::beg);
			Customer.read((char*)&length, sizeof(int)); Customer.get(x);

			Customer.read((char*)&d.Customer_ID, sizeof(d.Customer_ID));
			getline(Customer, Customer_Name, '|');

			
			Customer.read((char*)&d.Customer_Age, sizeof(d.Customer_Age)); Customer.get(l);
			Customer.read((char*)&d.Number_of_Purchased_Products, sizeof(d.Number_of_Purchased_Products)); Customer.get(l);



			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<< Customer Data You Searched for >>>>>>>>>>>>>>>>>>>>>>>>>";
			cout << "\n============================================================================================================================================\n";
			cout << "the Size of Record is : " << length << "\t Customer Name : " << Customer_Name << "\t Customer ID : " << d.Customer_ID << "\t Customer Age : " << d.Customer_Age << "\t Number of Puchased Products : " << d.Number_of_Purchased_Products << endl;
			cout << "\n============================================================================================================================================\n";
		}
		Customer.close();
		index.close();

	}


	void Update_Customer(int number) {
		char l[8]; int n;
		fstream index, Customer;
		index.open("index.txt", ios::in | ios::binary);
		Customer.open("Customer.txt", ios::in | ios::out);
		

		int c = 0;
		char h;
		string A, N;
		while (!index.eof()) {
			index.read((char*)&d.Customer_ID, sizeof(d.Customer_ID));

			index.read((char*)&i, sizeof(i));
			cout << "the Customer ID : " << d.Customer_ID << endl;
			cout << "Offset of Record : " << i << endl;

			cout << "The Compare Number is : " << number<<"\t\t Customer ID is : "<< d.Customer_ID << endl;
			if (number == d.Customer_ID) {
				c++;
				break;
				//cout << name << "\t\t " << x << "\t\t " << D << "\t\t " << A << endl;
				//cout << "\n==========================================================================\n";

			}
			//	if (!index.eof())
					//break;

		}
		if (c == 0) {
			cout << "The Customer isn't Found :(\n";
		}
		else {
			
			string  Customer_Name;
			char x, l;

			Customer.seekg(i, ios::beg);
			Customer.read((char*)&length, sizeof(int)); Customer.get(x);
			Customer.read((char*)&d.Customer_ID, sizeof(d.Customer_ID));
			getline(Customer, Customer_Name, '|');

			
			Customer.read((char*)&d.Customer_Age, sizeof(d.Customer_Age)); Customer.get(l);
			Customer.read((char*)&d.Number_of_Purchased_Products, sizeof(d.Number_of_Purchased_Products)); Customer.get(l);



			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<< Customer Data You Searched for >>>>>>>>>>>>>>>>>>>>>>>>>";
			cout << "\n============================================================================================================================================\n";
			cout << "the Size of Record is : " << length << "\t Customer Name : " << Customer_Name << "\t Customer ID : " << d.Customer_ID << "\t Customer Age : " << d.Customer_Age << "\t Customer Price : " << d.Number_of_Purchased_Products << endl;
			cout << "\n============================================================================================================================================\n";
			int k = 9;
			int H = 0, z = 0;
	
			while (k) {

				cout << "\nEnter the Customer ID you want to update please : \n\t\t [1] You want to update Customer Name \n\t\t [2] You want to update Customer Age \n\t\t [3] you want to update the Number of Purchased Products ";
				cout<<"\n"<<"Enter Your Choice : ";
				cin >> H;




				switch (H)
				{

				case 1:
				{
					z++;

					cin.ignore();
					cout << "Enter new Customer Name : \n";
					cin.getline(d.Customer_Name, 50);
					cout << "\n\nk\n";
					break;
				}
				case 2:
				{
					cout << "Enter New Customer Age : ";
					z++;
					cin.ignore();
					cin >> d.Customer_Age;
					break;
				}
				case 3:
				{
					cout << "Enter New Number of purchased products : \n";
					z++;
					cin.ignore();
					cin >> d.Number_of_Purchased_Products;
					break;
				}
				default:
					cout << "I don't understand you please enter right number :(\n";


				}


				cout << "\nIf You want to Exit from Our System Enter '0' \nIf you want to update another thing enter any number please :) \n";
				cin >> k;
			}
			if (z > 0)
			{
				
				//Customer.open("Customer.txt", ios::out);

				int newlength = strlen(d.Customer_Name) + sizeof(d.Customer_ID) + sizeof(d.Customer_Age) + sizeof(d.Number_of_Purchased_Products);  // change datatype of (Qty , price)
				cout << "New Length is : " << newlength << endl;
				//Customer.seekp(i, ios::beg);
				//Customer.close();
				 Customer.seekp(i, ios::beg);
				// new leght  <= old  new  => 
				if (length < newlength) {
					int offset,id;
					int id2;
					queue<pair<int, int>>q;
					//the stert index file
					index.seekg(0, ios::beg);
					index.read((char*)&id, sizeof(id));
					index.read((char*)&offset, sizeof(offset));

					while (true) {
						if (index.eof())
							break;
						q.push(make_pair(id, offset));
						cout << "Customer ID : " << id << "Length Of Record : " << offset << endl;
						index.read((char*)&id, sizeof(id));
						index.read((char*)&offset, sizeof(offset));
					}
					remove("index.txt");
					//fstream index("index.txt", ios::out | ios::binary );
					index.close();
					index.open("index.txt", ios::out | ios::binary);
					index.seekp(0, ios::beg);

					int a = q.size();
					for (int u = 0; u < a; u++) {
						id = q.front().first;
						offset = q.front().second;
						cout << "Customer ID : " << id << "Length Of Record : " << length << endl;
						q.pop();
						if (number != id) {
							
							index.write((char*)&id, sizeof(int));
							index.write((char*)&offset, sizeof(offset));
							//cout << name << "\t\t " << x << "\t\t " << D << "\t\t " << A << endl;
							//cout << "\n==========================================================================\n";
						}
						else {
							 id2 = id;
						}

					}


					//the end ofCustomer file
					Customer.seekg(0, ios::beg);
					Customer.read((char*)&head, sizeof(int));
					Customer.seekp(i , ios::beg);
					i = Customer.tellp();
					Customer.seekp(4, ios::cur);
					Customer.put('#');
					Customer.write((char*)&head, sizeof(int));
					Customer.seekp(0, ios::beg);
					Customer.write((char*)&i, sizeof(int));
					Customer.seekp(0, ios::end);
					int f = Customer.tellp();
					index.write((char*)&id2, sizeof(int));
					index.write((char*)&f, sizeof(int));
				}
				
				
				 if(Customer.is_open()) {
					
					
					Customer.write((char*)&newlength, sizeof(int)); Customer.put('|');
					Customer.write((char*)&d.Customer_ID, sizeof(d.Customer_ID));

					Customer.write(d.Customer_Name, strlen(d.Customer_Name)); Customer.put('|');

					

					Customer.write((char*)&d.Customer_Age, sizeof(d.Customer_Age)); Customer.put('|');


					Customer.write((char*)&d.Number_of_Purchased_Products, sizeof(d.Number_of_Purchased_Products)); Customer.put('|');
					
				 }
				 else
					 cout << "the Customer file is changed to open mode :)\n";

			}


		}
		Customer.close();
		index.close();

	}
	
	void Delete_Customer(int number) {
		//Customer.open("Customer.txt", ios::out);
		//index.open("index.txt", ios::in);
			//fstream index;
		
		queue<pair<int, int>>q;
		
		
		index.open("index.txt", ios::in | ios::out|ios::binary);
		Customer.open("Customer.txt", ios::in| ios::out);
		int c = 0; char h;
		
		int offset = 9;
		index.read((char*)&d.Customer_ID, sizeof(d.Customer_ID));
		index.read((char*)&offset, sizeof(offset));

		while (true) {
			if (index.eof())
				break;
			q.push(make_pair(d.Customer_ID, offset));
			cout << "Customer ID : " << d.Customer_ID << "Length Of Record : " << offset << endl;
			index.read((char*)&d.Customer_ID, sizeof(d.Customer_ID));
			index.read((char*)&offset, sizeof(offset));
		} 
		remove("index.txt");
		fstream index("index.txt",ios::out);
		index.seekp(0, ios::beg);

		int a = q.size();
		for (int u = 0; u < a; u++) {
			d.Customer_ID = q.front().first;
			i = q.front().second;
			cout << "Customer ID : " << d.Customer_ID << "Length Of Record : " << length << endl;
			q.pop();
			if (number == d.Customer_ID) {
				c++;
				offset=i;
				//
				//cout << name << "\t\t " << x << "\t\t " << D << "\t\t " << A << endl;
				//cout << "\n==========================================================================\n";
			}
			else {
			
				
				index.write((char*)&d.Customer_ID, sizeof(int));
				index.write((char*)&i, sizeof(i));
			}

		}

		if (c == 0) {
			cout << "The Customer isn't Found :(\n";
		}
		else {
		
			Customer.seekg(0, ios::beg);
			Customer.read((char*)&head, sizeof(int));
			
			
			Customer.seekp(offset + 4, ios::beg);

	
			Customer.put('#');
			Customer.write((char*)&head, sizeof(int));

			Customer.seekp(0, ios::beg);
			Customer.write((char*)&offset, sizeof(int));
		}
		Customer.close();
		index.close();
	}



};

int main() {
	Customer l;
	int r = 2;
	int m;
	//l.disindex();
	while (r) {
		cout<<"\n"<<"\t <<<<<<< Welcome to Our Customer Market System >>>>>>>"<<"\n\n\n";
		 cout<<"\t\t"<< " [1] Add a new Customer \n\n\t\t [2] Display all Customers of our Supermarket \n\n\t\t [3] Search about new Customer \n\n\t\t [4] Update an Existing Customer \n\n\t\t [5] Delete an Existing Customer \n\n\n Enter your choice please : ";
		cin >> r;
		switch (r)
		{
		case 1:
		{
			cin.ignore();
			cout << "<<<< Enter the Customer Data >>>>\n";
			l.Add_Customer();
			break;
		}
		case 2: {
			cout<<"\n\n";
			l.Display_All_Customers();
			break;
		}
		case 3: {
			cout << "Enter the Customer ID you want to search for please : \n";
			cin >> m;
			l.Search_Customer(m);
			break;
		}
		case 4: {
			cout << "Enter the Customer ID you want to update please : \n";
			cin >> m;
			l.Update_Customer(m);
			break;
		}
		case 5: {
			cout << "Enter the Customer ID you want to delete please : \n";
			cin >> m;
			l.Delete_Customer(m);
			break;
		default :
        cout << " \n you have entered a wrong number :( \n\n\n";
		}
		}
		cout << "if you want to exit from System Enter '0'\nif you want to continue to use the system please press any number\n";
		cin >> r;
	}
}