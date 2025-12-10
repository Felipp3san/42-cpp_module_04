/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:07:02 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 23:20:59 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal(void);
	WrongAnimal(std::string const &type);
	WrongAnimal(WrongAnimal const &other);
	virtual ~WrongAnimal(void);
	WrongAnimal	&operator=(WrongAnimal const &other);
public:
	void				makeSound(void) const;
	std::string	const	&getType(void) const;
};

#endif
