/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:11:07 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 19:12:36 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource
{
public:
	virtual				~IMateriaSource(void) {};
	virtual void		learnMateria(AMateria *) = 0;
	virtual AMateria*	createMateria(std::string const &type) = 0;
};

#endif
