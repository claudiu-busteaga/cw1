#ifndef Film_H
#define Film_H
#include <iostream>
#include <vector>
// create a class film 
class Film
{
private:
	int seatsFilmTotal;
	int seatsFilmBooked;
	std::vector<bool> seatsFilm;

public:
	Film(int seatsFilmTotal);
	int getSeatsFilmTotal();
	int getSeatsFilmBooked();
	int remainingFilmTickets();
	void showFilmSeats();
	
};
#endif