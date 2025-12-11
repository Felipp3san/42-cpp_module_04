/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:48:15 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 16:50:13 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(AMateria const &other);
	virtual ~AMateria(void);
	AMateria	&operator=(AMateria const &other);
public:
	std::string const	&getType(void) const;
	virtual	AMateria*	clone() = 0;
	virtual void		use(ICharacter &type);
};

#endif
