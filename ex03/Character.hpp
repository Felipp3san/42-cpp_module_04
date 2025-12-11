/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:20:17 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 17:44:47 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	static int const	INV_SIZE = 4;
	static int const	FLOOR_SIZE = 100;
	std::string			_name;
	AMateria			*_inventory[INV_SIZE];
	int					_slotsInUse;
	AMateria			*_floor[FLOOR_SIZE];
	int					_discarded;
public:
	Character(void);
	Character(std::string const &name);
	Character(Character const &other);
	~Character(void);
	Character	&operator=(Character const &other);
public:
	std::string	const	getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
	void				listEquipments(void) const;
};

#endif
