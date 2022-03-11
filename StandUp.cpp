#include "StandUp.h"
#include <iomanip>

// StandUp constructor to for the total seats
StandUp::StandUp(int seatsStandUpTotal)
{
    if (seatsStandUpTotal < 0)
    {
        seatsStandUpTotal = 0;
    }
    this->seatsStandUpTotal = seatsStandUpTotal;
    this->seatsStandUpBooked = 0;
    for (int i = 0; i < this->seatsStandUpTotal; i++)
    {
        this->seatsStandUp.push_back(false);
    }
}
// function to get the total seats
int StandUp::getSeatsStandUpTotal()
{
    return seatsStandUpTotal;
}
// function to get the seats booked
int StandUp::getSeatsStandUpBooked()
{
    return seatsStandUpBooked;
}
int StandUp::remainingStandUpTickets()
{
    return seatsStandUpTotal - seatsStandUpBooked;
}

// function to display the seats
void StandUp::showStandUpSeats()
{
   for (int i = 0; i < seatsStandUpTotal; i++)
    {
        std::cout << "[" << (seatsStandUp[i] ? char(251) : ' ') << " " << std::setw(3) << i + 1 << "] ";
        if ((i + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }
}
//function to book seats
bool StandUp::bookStandUpSeat(int seatStandUpNumber)
{

    if (seatStandUpNumber >= 1 && seatStandUpNumber <= seatsStandUpTotal && seatsStandUp[seatStandUpNumber - 1] == false)
    {
        seatsStandUp[seatStandUpNumber - 1] = true;
        seatsStandUpBooked++;
        return true;
    }
    else
    {
        return false;
    }
}
//function to cancel seats
bool StandUp::cancelStandUpSeat(int seatStandUpNumber){

if (seatStandUpNumber >= 1 && seatStandUpNumber <= seatsStandUpTotal && seatsStandUp[seatStandUpNumber - 1] == true)
	{
		seatsStandUp[seatStandUpNumber - 1] = false;
		seatsStandUpBooked--;
		return true;
	}
	else
	{
		return false;
	}

}

