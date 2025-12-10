/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:45:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 22:42:29 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string	_type;
public:
	Animal(void);
	Animal(const std::string &type);
	Animal(Animal const &other);
	virtual	~Animal(void);
	Animal	&operator=(Animal const &other);
public:
	virtual void		makeSound(void) const;
	std::string	const	&getType(void) const;
};

#endif
