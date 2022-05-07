#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class	Contact
{
	public:

	Contact();
	Contact(std::string name);
	std::string	show_name() const;
	~Contact();
	
	private:

	std::string	_name;
};

#endif
