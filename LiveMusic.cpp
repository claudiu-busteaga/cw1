#include "LiveMusic.h"
#include <iomanip>

// LiveMusic constructor to for the total seats
LiveMusic::LiveMusic(int seatsMusicTotal)
{
    if (seatsMusicTotal < 0)
    {
        seatsMusicTotal = 0;
    }
    this->seatsMusicTotal = seatsMusicTotal;
    this->seatsMusicBooked = 0;
    for (int i = 0; i < this->seatsMusicTotal; i++)
    {
        this->seatsMusic.push_back(false);
    }
}
// function to get the total seats
int LiveMusic::getSeatsMusicTotal()
{
    return seatsMusicTotal;
}
// function to get the seats booked
int LiveMusic::getSeatsMusicBooked()
{
    return seatsMusicBooked;
}
int LiveMusic::remainingMusicTickets()
{
    return seatsMusicTotal - seatsMusicBooked;
}

// function to display the seats
void LiveMusic::showMusicSeats()
{
    for (int i = 0; i < seatsMusicTotal; i++)
    {
        std::cout << "[" << (seatsMusic[i] ? char(251) : ' ') << " " << std::setw(3) << i + 1 << "] ";
        if ((i + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }
}
//function to book seats
bool LiveMusic::bookMusicSeat(int seatMusicNumber)
{

    if (seatMusicNumber >= 1 && seatMusicNumber <= seatsMusicTotal && seatsMusic[seatMusicNumber - 1] == false)
    {
        seatsMusic[seatMusicNumber - 1] = true;
        seatsMusicBooked++;
        return true;
    }
    else
    {
        return false;
    }
}
//function to cancel seats
bool LiveMusic::cancelMusicSeat(int seatMusicNumber){

if (seatMusicNumber >= 1 && seatMusicNumber <= seatsMusicTotal && seatsMusic[seatMusicNumber - 1] == true)
	{
		seatsMusic[seatMusicNumber - 1] = false;
		seatsMusicBooked--;
		return true;
	}
	else
	{
		return false;
	}

}
