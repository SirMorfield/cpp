#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
  public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	ScavTrap(const ScavTrap& cp);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& cp);
	void	  guardGate();
};