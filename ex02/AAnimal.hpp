/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:45:16 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 20:00:08 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string	_type;
public:
	AAnimal(void);
	AAnimal(const std::string &type);
	AAnimal(AAnimal const &other);
	virtual	~AAnimal(void);
	AAnimal	&operator=(AAnimal const &other);
public:
	virtual void		makeSound(void) const = 0;
	std::string	const	&getType(void) const;
};

#endif
