

#include"Notebook.h"

Notebook::Notebook() {
}

Notebook::~Notebook() {
	note.clear();
}

void Notebook::add_or_replace(const std::string& name, unsigned long long phone)
{
	auto it = note.find(name);
	if (it != note.end())
	{
		if (it->second == phone)
		{
			throw std::exception(" This name already exist");
		}
		std::string phone_1;
		phone_1 = phone;
		it->second = phone;
	}
	else
	{
		note.insert(make_pair(name, phone));
	}

}
void Notebook:: erase(const std::string& name)
{
	auto it = note.find(name);
	if (it != note.end())
	{
		note.erase(name);
	}
	else
	{
		throw std::exception(" This name does not exist");
	}

}

std::string& Notebook::find(unsigned long long phone)
{

	int flag = 1;
	std::string name;
	name = "names";
	auto it = note.find(name);
	if (it == note.end())
	{
		for (auto& item : note)
		{
			if (item.second == phone)
			{
				std::cout << "Contact is fined: ";
				std::cout << item.first << " " << item.second << std::endl;
				flag = 0;

			}
		}
	}
	if(flag == 1)
	throw std::exception(" This phone number does not exist");
	return name;

}


std::string Notebook::find(const std::string& name) {

	auto it = note.find(name);
	if (it != note.end())
	{
		std::cout << "Contact is fined: ";
		std::cout << it->first << " " << it->second << std::endl;
	}
	else
	{
		throw std::exception(" This name does not exist");
	}

}

size_t Notebook::size() const {
	return note.size();
}


void Notebook::load(const std::string& filename) {
	std::ifstream f1;
	char c;
	std::string buf1;
	std::string buf2;
	std::string* it;
	unsigned long long phone;
	f1.open(filename, std::ios_base::in);
	c = f1.get();
	while (!f1.eof()) {
		while (c != '\0' && !f1.eof()) {
			buf1.push_back(c);
			c = f1.get();
		}
		if (c = f1.get() != '+') {
			throw std::exception(" Number in load file is out of format");
		}
		c = f1.get();
		while (c != '\n' && !f1.eof()) {
			buf2.push_back(c);
			c = f1.get();
		}
		c = f1.get();
		if (buf2.size() != NUMBER_LENGTH) {
			throw std::exception(" Number in load file is out of format");
		}
		phone = std::stoull(buf2);
		if (log10(phone) < 10 || log10(phone) > 11) {
			throw std::exception(" Number in load file is out of format");
		}
		if (phone == NULL) {
			throw std::exception(" Number in load file is out of format");
		}
		add_or_replace(buf1, phone);
		buf1.clear();
		buf2.clear();
	}
	f1.close();
}

void Notebook::save(const std::string& filename) {
	std::ofstream f1;
	f1.open(filename, std::ios_base::trunc);
	for (auto& item : note) {
		f1 << item.first << '\0' << '+' << item.second << "\n";
	}
	f1.close();
}



std::ostream& operator<<(std::ostream& os, const Notebook& notex)
{
	std::map<std::string, unsigned long long> :: const_iterator it = notex.note.begin();

	while (it != notex.note.end())
	{
		os << it->first << " " << it->second << std::endl;
		it++;
	}
	return os;
}
