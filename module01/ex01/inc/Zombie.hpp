#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie
{
	public:
	
	Zombie();
	Zombie(std::string name);
	void	set_name(std::string name);
	void	announce(void);
	~Zombie();

	private:

	std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
