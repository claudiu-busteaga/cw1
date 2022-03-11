#include "Film.h"
#include <iomanip>

// LiveMusic constructor to for the total seats
Film::Film(int seatsFilmTotal)
{
    if (seatsFilmTotal < 0)
    {
        seatsFilmTotal = 0;
    }
    this->seatsFilmTotal = seatsFilmTotal;
    this->seatsFilmBooked = 0;
    for (int i = 0; i < this->seatsFilmTotal; i++)
    {
        this->seatsFilm.push_back(false);
    }
}
// function to get the total seats
int Film::getSeatsFilmTotal()
{
    return seatsFilmTotal;
}
// function to get the seats booked
int Film::getSeatsFilmBooked()
{
    return seatsFilmBooked;
}
int Film::remainingFilmTickets()
{
    return seatsFilmTotal - seatsFilmBooked;
}

// function to display the seats
void Film::showFilmSeats()
{
    std::cout<<"------------------";
    std::cout<<"No available seats:";
    std::cout<<"------------------";
}
