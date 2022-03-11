#ifndef LiveMusic_H
#define LiveMusic_H


#include <iostream>
#include <vector>

class LiveMusic
{
private:
	int seatsMusicTotal;
	int seatsMusicBooked;
	std::vector<bool> seatsMusic;

public:
	LiveMusic(int seatsMusicTotal);
	int getSeatsMusicTotal();
	int getSeatsMusicBooked();
	int remainingMusicTickets();
	void showMusicSeats();
	bool bookMusicSeat(int seatMusicNumber);
	bool cancelMusicSeat(int seatMusicNumber);

};
#endif