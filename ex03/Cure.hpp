/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:52:55 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 16:39:04 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const &other);
	~Cure(void);
	Cure	&operator=(Cure const &other);
public:
	Cure	*clone();
	void	use(ICharacter &type);
};

#endif
