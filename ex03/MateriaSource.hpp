/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:13:51 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 19:42:39 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static int const	SIZE = 4;
	AMateria			*_materias[SIZE];
	int					_storedMaterias;
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &other);
	~MateriaSource(void);
	MateriaSource	&operator=(MateriaSource const &other);
public:
	void				learnMateria(AMateria *);
	AMateria*			createMateria(std::string const &type);
	void				listMaterias(void) const;
};

#endif
