/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:52:19 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 16:39:02 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const &other);
	~Ice(void);
	Ice	&operator=(Ice const &other);
public:
	Ice*	clone();
	void	use(ICharacter &type);
};

#endif
