#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>

# define FIELD_NBR			5

class	Contact
{
	public:

	Contact();
	void		show_field(int i) const;
	std::string	get_field(int i) const;
	void		add_field(int i, std::string input);
	void		show_field_name(int i) const;
	~Contact();
	
	
	private:

	std::string	_field_names[FIELD_NBR] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};
	std::string	_fields[FIELD_NBR];
};

#endif
