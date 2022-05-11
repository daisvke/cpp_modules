#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie
{
	public:
	
	Zombie();
	Zombie(std::string name);
	void	announce(void);
	~Zombie();

	private:

	std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
