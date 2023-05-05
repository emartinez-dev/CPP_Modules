/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:39:39 by franmart          #+#    #+#             */
/*   Updated: 2023/05/05 13:34:54 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>

# define STR_DEBUG "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-"\
	"triple-pickle-specialketchup burger. I really do!"
# define STR_INFO  "[INFO]\nI cannot believe adding extra bacon costs more "\
	"money. You didn't put enough bacon in my burger! If you did, I wouldn't "\
	"be asking for more!"
# define STR_WARNING "[WARNING]\nI think I deserve to have some extra bacon "\
	"for free. I've been coming for years whereas you started working here "\
	"since last month."
# define STR_ERROR "[ERROR]\nThis is unacceptable! "\
	"I want to speak to the manager now."

# define TYPE_DEBUG 0
# define TYPE_INFO 7
# define TYPE_WARNING 13
# define TYPE_ERROR 22

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
