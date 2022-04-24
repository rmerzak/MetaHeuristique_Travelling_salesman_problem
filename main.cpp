/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:55:52 by iltafah           #+#    #+#             */
/*   Updated: 2022/04/24 18:32:55 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./TSP.hpp"

int main()
{
	try
	{
		size_t departureCity;
		std::string fileName;

		std::cout << "Enter the input file name : ";
		std::cin >> fileName;

		TSP obj(fileName);
		obj.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}