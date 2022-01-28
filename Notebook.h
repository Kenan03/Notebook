
#include <iostream>
#include <map>
#include <fstream>
#include <string>

#define NUMBER_LENGTH 11


class Notebook
{
private:
	std::map<std::string, unsigned long long> note;
public:
	Notebook();
	~Notebook();
	size_t size() const;
	void add_or_replace(const std::string& name, const unsigned long long phone);
	void erase(const std::string& name);
	std::string& find(const unsigned long long phone);
	std::string find(const std::string& name);
	void load(const std::string& filename);
	void save(const std::string& filename);
	friend std::ostream& operator<<(std::ostream& os, const Notebook& notex);
};






















