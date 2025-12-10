/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:43:46 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 17:46:40 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
private:
	static int const	SIZE = 100;
	std::string			_ideas[SIZE];
public:
	Brain(void);
	Brain(std::string const ideas[]);
	Brain(Brain const &other);
	~Brain(void);
	Brain	&operator=(Brain const &other);
};

#endif
