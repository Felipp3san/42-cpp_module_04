/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:47:05 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 19:59:41 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*_ideas;
public:
	Cat(void);
	Cat(std::string const ideas[]);
	Cat(std::string const &type, std::string const ideas[]);
	Cat(Cat const &other);
	~Cat(void);
	Cat	&operator=(Cat const &other);
public:
	void		makeSound(void) const;
};

#endif
