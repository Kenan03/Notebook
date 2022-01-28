
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include"Notebook.h"

#define NUMBER_LENGTH 11

int main()
{
	Notebook note;
	try 
	{
		note.load("NOTE.txt");
	}
	catch (const std::exception error)
	{
		std::cerr << "Error:" << error.what() << " in operation load in Notebook" << '\n';
	}
	try
	{
		note.add_or_replace("Kenan", +79208180788);
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation add in Notebook" << '\n';
	}
	/* 
	try
	{
		note.find(+79206660711);
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation find in Notebook" << '\n';
	}
	try
	{
		note.find(+79008180742);
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation find in Notebook" << '\n';
	}
	try
	{
		note.find(+79208165422);
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation find in Notebook" << '\n';
	}
	*/
	/* 
	try
	{
		note.add_or_replace("Kenan", +79208180711);
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation add in Notebook" << '\n';
	}
	try
	{
		note.add_or_replace("Murad", +79208165422);
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation add in Notebook" << '\n';
	}
	try
	{
		note.add_or_replace("Nikita", +79208180742);
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation add in Notebook" << '\n';
	}
	*/
	/*
	try
	{
		note.erase("Kenan");
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation erase in Notebook" << '\n';
	}
	try
	{
		note.erase("Nikita");
	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation erase in Notebook" << '\n';
	}
	*/
	try
	{
		note.save("NOTE.txt");
	}
	catch (const std::exception error)
	{
		std::cerr << "Error:" << error.what() << " in operation load in Notebook" << '\n';
	}
	std::cout << note;
	
	return 0;
	

}


















/* 
#include <iostream>
#include <vector>
#include"Notebook.h"

int main() {
	Notebook note;
	
	try
	{
		note.load("NOTE.txt");
	}
	catch (const std::exception error)
	{
		std::cerr << "Error:" << error.what() << " in operation load in Notebook" << '\n';
	}
	std::cout << note << std::endl;
	
	try
	{
		
		note.add("ass", +79208180874);

	}
	catch (std::exception& error)
	{
		std::cerr << "Error:" << error.what() << "in operation add in Notebook" << '\n';
	}
	/*
	try
	{
		note.add("Kenan", +79309876622);
		note.add("Alex", +79109821111);
	}
	catch (std::exception& error) 
	{
		std::cerr << "Error:" << error.what() << "in operation add in Notebook" << '\n';
	}
	*/
	/* 
	try
	{
		note.erase("Kenan");
	}
	catch (std::exception& error) 
	{
		std::cerr << "Error:" << error.what() << "in operation erase in Notebook" << '\n';
	}
	
	
	try
	{
		note.find(+79309876622);
	}
	catch (std::exception& error) 
	{
		std::cerr << "Error:" << error.what() << "in operation find in Notebook" << '\n';
	}
	
	
	try
	{
		note.find("ALESHA");
	}
	catch (std::exception& error) 
	{
		std::cerr << "Error:" << error.what() << "in operation find in Notebook" << '\n';
	}
	
	try
	{
		note.save("NOTE.txt");
	}
	catch (std::exception& error) 
	{
		std::cerr << "Error:" << error.what() << " in operation save in Notebook" << '\n';
	}
	
	return 0;
}
*/












































/* 
#include <iostream>
#include<string>
#include<fstream>
#include"Notebook.h"

int main()

{

	Notebook r;
	std::string name;
	unsigned phone;
	std::cout << "Enter 1 if you want add user(s): ";
	std::cout << std::endl;
	std::cout << "Enter 2 if you want look user(s): ";
	std::cout << std::endl;
	std::cout << "Enter 3 if you want erase user(s): ";
	int value;
	std::cin >> value;
	switch (value)
	{
	case 1:
		r.load("NOTE.txt");
		break;
	case 2:
		r.looking();
		break;
	case 3:
		std::cout << "Enter name that want erase: ";
		std::cin >> name;
		r.erase(name);
		break;
	default:
		break;
	}
	/* 
	std::fstream note;
	note.open("NOTE.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (!note.is_open())
	{
		std::cout << "Wrong";
	}
	else
	{
		static int i;
		int value;
		std::string name;
		unsigned phone;
		std::cout << "All Good!" << std::endl;
		std::cout << "Enter button 1 if you want to add users" << std::endl;
		std::cout << "Enter button 2 if you want to see record" << std::endl;
		std::cout << "Enter button 3 if you erase user" << std::endl;
		std::cin >> value;

		if (value == 1)
		{
			std::cout << "Enter name users: ";
			std::cin >> name;
			note << name << "\t";
			i++;
			std::cout << "Enter number users: ";
			std::cin >> phone;
			note << phone;
			note << "\n";

		}
		if (value == 2)
		{
			while (!note.eof())
			{
				name = "";
				note >> name >> phone;
				if (name == "")
				{
					break;
				}
				std::cout << name << "\t" << phone << std::endl;

			}
		}
		if (value == 3)
		{
			std::map  <std::string, std::string>  note;
			note[name] = "Kenan";     // добавляем
											   // новые
												  // значения
			std::cout << note[name];

			std::cout << std::endl;
			std::cout << "Size: " << note.size() << std::endl;

			std::map <std::string, std::string> ::iterator full_name; // создали итератор на passport

			full_name = note.find(name); // находим ячейку
			note.erase(full_name);           // удаляем
			std::cout << note[name];

			std::cout << "Size: " << note.size();

		}
	}
	note.close();
	*/
	/* 
	std::ofstream fout;
	fout.open("myFILE.txt");

	if (!fout.is_open())
	{
		std::cout << "Wrong";
	}
	else
	{
		fout << "DATWWWWWWWWA";
	}
	

	fout.close();
	
	
	std::ifstream fin;
	fin.open("myFILE.txt");
	if (!fin.is_open())
	{
		std::cout << "Wrong";
	}
	else
	{
		std::cout << "Good";
		std::cout << std::endl;
		std::string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			std::cout << str << std::endl;
		}
	}
	fin.close();
	
	*/



