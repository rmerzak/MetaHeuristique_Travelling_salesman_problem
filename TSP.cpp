/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:55:48 by iltafah           #+#    #+#             */
/*   Updated: 2022/04/24 18:33:18 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./TSP.hpp"

TSP::TSP(string fileName) : num_cities(0), distances(NULL)
{
	ifstream file(fileName);

	if (file.is_open() == false)
	{
		throw (runtime_error("file `" + fileName + "` couldn't be opened"));
	}

	file >> num_cities; // get num of cities from the file

	//allocate table of distances
	distances = new int*[num_cities];
	for (int i = 0; i < num_cities; i++)
		distances[i] = new int[num_cities];

	//read file and store distances in their appropriate spots
	for (int i = 0; i < num_cities; i++)
	{
		//the distance between a `city[i]` and `city[i]` is 0
		distances[i][i] = 0;

		//take the distances that have been already read and stored
		for (int j = 0; j < i; j++)
			distances[i][j] = distances[j][i];

		//read the new distances of the new city
		for (int k = i + 1; k < num_cities; k++)
			file >> distances[i][k];
	}

	//no need to close the file, since file is an object of ifstream, so the opened file will be closed in its destructor
	file.close();

	//vector of cities that `salesman` has traversed, I'll need it later
	traversedCities.assign(num_cities, false);
}

int TSP::get_num_cities() const
{
	return (num_cities);
}

int TSP::get_dist(int ci, int cj)
{
	return (distances[ci][cj]);
}

int* TSP::Nearest_Neighbor(int *givenCityindex)
{
	size_t	minDistance = 9999999; // must fix this shit
	int		indexOfMinDistance = 0;

	for (int i = 0; i < num_cities; i++)
	{
		if (distances[*givenCityindex][i] < minDistance && traversedCities[i] == false)
		{
			minDistance = distances[*givenCityindex][i];
			indexOfMinDistance = i;
		}
	}
	*givenCityindex = indexOfMinDistance;
	return (distances[indexOfMinDistance]);
}


void TSP::print()
{
	/**********************************************************************************************/
	std::cout << "Number of cities : " << get_num_cities() << std::endl;
	/**********************************************************************************************/

	
	/**********************************************************************************************/
	std::cout << "Matrix of distances between cities :" << std::endl;
	for (int j = 0; j < num_cities; j++)
	{
		for (int i = 0; i < num_cities; i++)
			std::cout << distances[j][i] << "\t";
		std::cout << std::endl;
	}
	/**********************************************************************************************/

	
	/**********************************************************************************************/
	size_t departureCity;
	std::cout << "Choose a departure city : ";
	std::cin >> departureCity;
	/**********************************************************************************************/


	/**********************************************************************************************/
	std::cout << "The tower obtained is :" << std::endl;

	std::cout << departureCity << "-->";
	traversedCities[departureCity] = true;
	
	int DistancesSum = 0;
	int currCityIndex = departureCity;
	int prevCityIndex;
	for (int i = 0; i < num_cities - 1; i++)
	{
		prevCityIndex = currCityIndex;
		Nearest_Neighbor(&currCityIndex);
		if (currCityIndex == departureCity)
			continue ;
		traversedCities[currCityIndex] = true;
		std::cout << currCityIndex << "-->";
		DistancesSum += get_dist(prevCityIndex, currCityIndex);
	}
	std::cout << departureCity << std::endl;
	/**********************************************************************************************/


	/**********************************************************************************************/
	DistancesSum += get_dist(currCityIndex, departureCity);
	std::cout << "It's cost is : " << DistancesSum << std::endl;
	/**********************************************************************************************/
}
