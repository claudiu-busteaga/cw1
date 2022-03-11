#ifndef StandUp_H
#define StandUp_H
#include <iostream>
#include <vector>

class StandUp
{
private:
	int seatsStandUpTotal;
	int seatsStandUpBooked;
	std::vector<bool> seatsStandUp;

public:
	StandUp(int seatsStandUpTotal);
	int getSeatsStandUpTotal();
	int getSeatsStandUpBooked();
	int remainingStandUpTickets();
	void showStandUpSeats();
	bool bookStandUpSeat(int seatStandUpNumber);
	bool cancelStandUpSeat(int seatStandUpNumber);

};
#endif