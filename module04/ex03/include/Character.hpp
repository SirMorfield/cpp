#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
  private:
	Character();
	std::string name;
	int			equipped;
	AMateria*	inventory[4];

  public:
	Character(const std::string& name);
	Character(const Character& cp);
	virtual ~Character();
	Character&		   operator=(const Character& cp);
	const std::string& getName() const;
	void			   equip(AMateria* m);
	void			   unequip(int idx);
	void			   use(int idx, ICharacter& target);
};

#endif