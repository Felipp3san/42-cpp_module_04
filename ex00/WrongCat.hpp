/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:09:59 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 23:13:16 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(std::string const &type);
	WrongCat(WrongCat const &other);
	~WrongCat(void);
	WrongCat	&operator=(WrongCat const &other);
public:
	void		makeSound(void) const;
};

#endif
