/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TSP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:55:50 by iltafah           #+#    #+#             */
/*   Updated: 2022/04/24 18:33:01 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TSP_HPP
# define TSP_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <vector>

using namespace std;

class TSP
{
	private:
		int num_cities;	 // number of cities
		int **distances; // distances matrix
		std::vector<bool> traversedCities;

	public:
		TSP(string); // constructor from an input file
		int get_num_cities() const;
		void print();
		int get_dist(int, int); // compute the distance between ci and cj
		int *Nearest_Neighbor(int *); // The heuristic

};

#endif