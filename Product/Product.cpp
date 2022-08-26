#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<utility>
#include<map>
#include<string.h>
using namespace std;

class Products {
public:
	int pN, pqty;
	char pname[50];
	float pprice;


};
class Product {

public:
	//char name[50];
	int i, counter, length;
	int head = -1, found = 0;
	fstream index;
	fstream product;

	Products d;
	void Add_Product() {
		map<int, int>k;
		product.open("product.txt", ios::out | ios::app);


		cout << " Enter the Product Name :\n ";
		cin.getline(d.pname, 50);

		cout << " Enter the Product Price :\n ";
		cin >> d.pprice;

		cout << " Enter the Quantity of Product :\n ";
		cin >> d.pqty;

		cout << " Enter the Product ID :\n ";
		cin >> d.pN;
		//strcpy(pqty, pqty + '\0');

		//Productsw();
		//map<int, int>k;
		//("product.txt", ios::out|ios::app|ios::in);
		//index.open("index.txt", ios::out | ios::app);

		//index.write((char*)&pN, sizeof(pN)); index.put('|'); index.write((char*)&length, sizeof(int));
		//product.seekg(0, ios::end);
		//length = product.tellp();
		product.seekp(0, ios::end);
		if (!product.tellp()) {

			product.write((char*)&head, sizeof(int));


		}

		// if (head != -1)
		// {

		// 	int sizer;

		// 	while (head != -1) {
				
		// 		product.seekg(head, ios::beg);
		// 		product.read((char*)&sizer, sizeof(int));
		// 		product.read((char*)&head, sizeof(int));

		// 		k[sizer] = head;

		// 	}
		// 	length = strlen(d.pname) + sizeof(d.pN) + sizeof(d.pqty) + sizeof(d.pprice);
		// 	for (auto k : k) {
		// 		if (length < k.first) {
		// 			found++;
		// 			sizer = k.first;
		// 			head = k.second;
		// 			break;
		// 		}
		// 	}
		// }
		// if (found > 0) {
		// 	index.close();
		// 	index.open("index.txt", ios::out | ios::binary);
		// 	product.seekp(0, ios::end);
		// 	i = product.tellp();
		// 	index.write((char*)&d.pN, sizeof(d.pN));
		// 	index.write((char*)&i, sizeof(int));
		// 	product.seekp(head, ios::beg);
		// 	length = strlen(d.pname) + sizeof(d.pN) + sizeof(d.pqty) + sizeof(d.pprice);
		// 	product.write((char*)&length, sizeof(int)); product.put('|');
		// 	//length = sizeof(pname());
		// 	//product.write((char*)&length, sizeof(short));
		// 	product.write((char*)&d.pN, sizeof(d.pN));
		// 	product.write((char*)&d.pname, strlen(d.pname)); product.put('|');
		// 	//length = sizeof(x);
		// 	//product.write((char*)&length, sizeof(short));

		// 	//length = sizeof(D);
		// 	//product.write((char*)&length, sizeof(short));
		// 	product.write((char*)&d.pqty, sizeof(d.pqty)); product.put('|');
		// 	//length = sizeof(A);
		// 	//product.write((char*)&length, sizeof(short));
		// 	product.write((char*)&d.pprice, sizeof(d.pprice)); product.put('|');
		// 	index.close();
		// }
		// else {
			index.close();
			index.open("index.txt", ios::out | ios::app | ios::binary);
			product.seekp(0, ios::end);
			i = product.tellp();
			index.write((char*)&d.pN, sizeof(d.pN));
			index.write((char*)&i, sizeof(i));
			length = strlen(d.pname) + sizeof(d.pN) + sizeof(d.pqty) + sizeof(d.pprice);
			product.write((char*)&length, sizeof(int)); product.put('|');
			product.write((char*)&d.pN, sizeof(d.pN));
			product.write(d.pname, strlen(d.pname)); product.put('|');

			

			product.write((char*)&d.pqty, sizeof(d.pqty)); product.put('|');

			product.write((char*)&d.pprice, sizeof(d.pprice)); product.put('|');
		
		//}
		index.close();
		product.close();

		//}

	}
	void Display_All_Products() {
		ifstream product("product.txt", ios::app | ios::in);
		index.open("index.txt", ios::in | ios::binary);
		int s = 0;
		//	char x;
		int offset;
			//char a[50], d[50], G[50], name[50], l[50];
		string  pname;
		char l;
		int id;
		//product.seekg(4, ios::beg);
		char x;
		while (1) {
			
			index.read((char*)&id, sizeof(id));
			index.read((char*)&offset, sizeof(offset));
			product.seekg(offset, ios::beg);
			
			product.read((char*)&length, sizeof(int)); product.get(x);
			

			product.read((char*)&d.pN, sizeof(d.pN));
			getline(product, pname, '|');
			product.read((char*)&d.pqty, sizeof(d.pqty)); product.get(l);
			product.read((char*)&d.pprice, sizeof(d.pprice)); product.get(l);
			
			/*
			getline(product, c, '|');
			getline(product, l, '|');
			*/

			if (product.eof() != 0 || index.eof()!=0)
				break;
			++s;
			if (x != '#')
			{
				cout<<"<<<<<<<<<<<<<<<<<<<<<<<<< Product Data No. "<< s << ">>>>>>>>>>>>>>>>>>>>>>>>>";
				cout << "\n============================================================================================================================================\n";
				cout << "the Size of Record is : " << length << "\t Product Name : " << pname << "\t Product ID : " << d.pN << "    " << "\t Quantity of Product : " << d.pqty << "\t Product Price : " << d.pprice;
				cout << "\n============================================================================================================================================\n";
			}
			

		}
		product.close();
		index.close();
	}
	void Search_Product(int number) {
		ifstream index, product;
		char l[8]; int n;
		index.open("index.txt", ios::in | ios::binary);
		product.open("product.txt", ios::in);

		int c = 0;
		char h;
		string A, N;
		do {
			index.read((char*)&d.pN, sizeof(d.pN));

			index.read((char*)&i, sizeof(i));
			cout << "the Product ID : " << d.pN << endl;
			cout << "Offset of Record : " << i << endl;
			/*
			product.read((char*)&length, sizeof(short));
			product.read((char*)&length, sizeof(short));
			product.read((char*)&name, length);
			product.read((char*)&length, sizeof(short));
			product.read((char*)&x, length);
			product.read((char*)&length, sizeof(short));
			product.read((char*)&D, length);
			product.read((char*)&length, sizeof(short));
			product.read((char*)&A, length);

			*/
			// iam delet the element name x
			cout << "The Compare Number is : " << number<<"\t\t Product ID is : "<< d.pN << endl;
			if (number == d.pN) {
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
			cout << "The Product isn't Found :(\n";
		}
		else {
			char l;
			string  pname;
			char x;

			product.seekg(i, ios::beg);
			product.read((char*)&length, sizeof(int)); product.get(x);

			product.read((char*)&d.pN, sizeof(d.pN));
			getline(product, pname, '|');

			
			product.read((char*)&d.pqty, sizeof(d.pqty)); product.get(l);
			product.read((char*)&d.pprice, sizeof(d.pprice)); product.get(l);



			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<< Product Data You Searched for >>>>>>>>>>>>>>>>>>>>>>>>>";
			cout << "\n============================================================================================================================================\n";
			cout << "the Size of Record is : " << length << "\t Product Name : " << pname << "\t Product ID : " << d.pN << "\t Quantity of Product : " << d.pqty << "\t Product Price : " << d.pprice << endl;
			cout << "\n============================================================================================================================================\n";
		}
		product.close();
		index.close();

	}


	void Update_Product(int number) {
		char l[8]; int n;
		fstream index, product;
		index.open("index.txt", ios::in | ios::binary);
		product.open("product.txt", ios::in | ios::out);
		

		int c = 0;
		char h;
		string A, N;
		while (!index.eof()) {
			index.read((char*)&d.pN, sizeof(d.pN));

			index.read((char*)&i, sizeof(i));
			cout << "the Product ID : " << d.pN << endl;
			cout << "Offset of Record : " << i << endl;

			cout << "The Compare Number is : " << number<<"\t\t Product ID is : "<< d.pN << endl;
			if (number == d.pN) {
				c++;
				break;
				//cout << name << "\t\t " << x << "\t\t " << D << "\t\t " << A << endl;
				//cout << "\n==========================================================================\n";

			}
			//	if (!index.eof())
					//break;

		}
		if (c == 0) {
			cout << "The Product isn't Found :(\n";
		}
		else {
			
			string  pname;
			char x, l;

			product.seekg(i, ios::beg);
			product.read((char*)&length, sizeof(int)); product.get(x);
			product.read((char*)&d.pN, sizeof(d.pN));
			getline(product, pname, '|');

			
			product.read((char*)&d.pqty, sizeof(d.pqty)); product.get(l);
			product.read((char*)&d.pprice, sizeof(d.pprice)); product.get(l);



			cout<<"<<<<<<<<<<<<<<<<<<<<<<<<< Product Data You Searched for >>>>>>>>>>>>>>>>>>>>>>>>>";
			cout << "\n============================================================================================================================================\n";
			cout << "the Size of Record is : " << length << "\t Product Name : " << pname << "\t Product ID : " << d.pN << "\t Quantity of Product : " << d.pqty << "\t Product Price : " << d.pprice << endl;
			cout << "\n============================================================================================================================================\n";
			int k = 9;
			int H = 0, z = 0;
	
			while (k) {

				cout << "\nEnter the Product ID you want to update please : \n\t\t [1] You want to update Product Name \n\t\t [2] You want to update Quantity of Product \n\t\t [3] you want to update the Product Price ";
				cout<<"\nEnter your choice : ";
				cin >> H;




				switch (H)
				{

				case 1:
				{
					z++;

					cin.ignore();
					cout << "Enter New Product Name : \n";
					cin.getline(d.pname, 50);
					cout << "\n\nk\n";
					break;
				}
				case 2:
				{
					cout << "Enter New Quantity of Product : ";
					z++;
					cin.ignore();
					cin >> d.pqty;
					break;
				}
				case 3:
				{
					cout << "Enter New Product Price : \n";
					z++;
					cin.ignore();
					cin >> d.pprice;
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
				
				//product.open("product.txt", ios::out);

				int newlength = strlen(d.pname) + sizeof(d.pN) + sizeof(d.pqty) + sizeof(d.pprice);  // change datatype of (Qty , price)
				cout << "New Length is : " << newlength << endl;
				//product.seekp(i, ios::beg);
				//product.close();
				 product.seekp(i, ios::beg);
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
						cout << "Product ID : " << id << "Length Of Record : " << offset << endl;
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
						cout << "Product ID : " << id << "Length Of Record : " << length << endl;
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


					//the end ofproduct file
					product.seekg(0, ios::beg);
					product.read((char*)&head, sizeof(int));
					product.seekp(i , ios::beg);
					i = product.tellp();
					product.seekp(4, ios::cur);
					product.put('#');
					product.write((char*)&head, sizeof(int));
					product.seekp(0, ios::beg);
					product.write((char*)&i, sizeof(int));
					product.seekp(0, ios::end);
					int f = product.tellp();
					index.write((char*)&id2, sizeof(int));
					index.write((char*)&f, sizeof(int));
				}
				
				
				 if(product.is_open()) {
					
					
					product.write((char*)&newlength, sizeof(int)); product.put('|');
					product.write((char*)&d.pN, sizeof(d.pN));

					product.write(d.pname, strlen(d.pname)); product.put('|');

					

					product.write((char*)&d.pqty, sizeof(d.pqty)); product.put('|');


					product.write((char*)&d.pprice, sizeof(d.pprice)); product.put('|');
					
				 }
				 else
					 cout << "the product file is changed to open mode :)\n";

			}


		}
		product.close();
		index.close();

	}
	
	void Delete_Product(int number) {
		//product.open("product.txt", ios::out);
		//index.open("index.txt", ios::in);
			//fstream index;
		
		queue<pair<int, int>>q;
		
		
		index.open("index.txt", ios::in | ios::out|ios::binary);
		product.open("product.txt", ios::in| ios::out);
		int c = 0; char h;
		
		int offset = 9;
		index.read((char*)&d.pN, sizeof(d.pN));
		index.read((char*)&offset, sizeof(offset));

		while (true) {
			if (index.eof())
				break;
			q.push(make_pair(d.pN, offset));
			cout << "Product ID : " << d.pN << "Length Of Record : " << offset << endl;
			index.read((char*)&d.pN, sizeof(d.pN));
			index.read((char*)&offset, sizeof(offset));
		} 
		remove("index.txt");
		fstream index("index.txt",ios::out);
		index.seekp(0, ios::beg);

		int a = q.size();
		for (int u = 0; u < a; u++) {
			d.pN = q.front().first;
			i = q.front().second;
			cout << "Product ID : " << d.pN << "Length Of Record : " << length << endl;
			q.pop();
			if (number == d.pN) {
				c++;
				offset=i;
				//
				//cout << name << "\t\t " << x << "\t\t " << D << "\t\t " << A << endl;
				//cout << "\n==========================================================================\n";
			}
			else {
			
				
				index.write((char*)&d.pN, sizeof(int));
				index.write((char*)&i, sizeof(i));
			}

		}

		if (c == 0) {
			cout << "The Product isn't Found :(\n";
		}
		else {
		
			product.seekg(0, ios::beg);
			product.read((char*)&head, sizeof(int));
			
			
			product.seekp(offset + 4, ios::beg);

	
			product.put('#');
			product.write((char*)&head, sizeof(int));

			product.seekp(0, ios::beg);
			product.write((char*)&offset, sizeof(int));
		}
		product.close();
		index.close();
	}



};

int main() {
	Product l;
	int r = 2;
	int m;
	//l.disindex();
	while (r) {
		cout<<"\n"<<"\t <<<<<<< Welcome to Our product Market System >>>>>>>"<<"\n\n\n";
		 cout<<"\t\t"<< " [1] Add a new product \n\n\t\t [2] Display all products of our Supermarket \n\n\t\t [3] Search about new product \n\n\t\t [4] Update an Existing product \n\n\t\t [5] Delete an Existing product \n\n\n Enter your choice please : ";
		cin >> r;
		switch (r)
		{
		case 1:
		{
			cin.ignore();
			cout << "<<<< Enter the Product Data >>>>\n";
			l.Add_Product();
			break;
		}
		case 2: {
			cout<<"\n\n";
			l.Display_All_Products();
			break;
		}
		case 3: {
			cout << "Enter the Product Number you want to search for please : \n";
			cin >> m;
			l.Search_Product(m);
			break;
		}
		case 4: {
			cout << "Enter the Product Number you want to update please : \n";
			cin >> m;
			l.Update_Product(m);
			break;
		}
		case 5: {
			cout << "Enter the Product you want to delete please : \n";
			cin >> m;
			l.Delete_Product(m);
			break;
		default :
        cout << " \n you have entered a wrong number :( \n\n\n";
		}
		}
		cout << "if you want to exit from System Enter '0'\nif you want to continue to use the system please press any number\n";
		cin >> r;
	}
}