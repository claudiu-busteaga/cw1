#include <iostream>
#include <fstream>
#include <string>
#include"Film.h"
#include"LiveMusic.h"
#include"StandUp.h"

int main()
{

    LiveMusic music(300); // Create an object of LiveMusic class
    StandUp standUp(200);// Create an object of StandUp class
    Film film(0);//Create an of Film class
    int option, c;
    while (1)
    {
        // display the menu
        std::cout << "Please select one of the following options:" << '\n';
        std::cout << "(1)Add a booking for an event" << '\n';
        std::cout << "(2)Cancel/refund a booking" << '\n';
        std::cout << "(3)List all events" << '\n';
        std::cout << "(4)List details and availability of a given event" << '\n';
        std::cout << "(5)Load data from a file(all events and availability)" << '\n';
        std::cout << "(6)Save data to a file (all events and availabilty)" << '\n';
        std::cout << "Press any other key to exit" << '\n';

        std::cin >> option;
        // display the  option 1 menu
        if (option == 1)
        {
            std::cout << "Select an event to book:" << '\n';
            std::cout << "(1)Live music" << '\n';
            std::cout << "(2)Stand-up comedy" << '\n';
            std::cout << "(3)Film" << '\n';

            std::cin >> c;

            if (c == 1)
            {
                std::cout << "Live music seats (standing)" << '\n';
                music.showMusicSeats(); // diplay available seats for live music event
                std::cout << "Please choose available  standing seats from above:" << '\n';
                int seatMusicNumber;
                std::cin >> seatMusicNumber;
                // check if is  a valid seat
                while (seatMusicNumber < 1 || seatMusicNumber > music.getSeatsMusicTotal())
                {
                    std::cout << "Invalid number, try again." << '\n';
                    std::cout << "Enter seat number: ";
                    std::cin >> seatMusicNumber;
                }
                // check if the seat is booked and display the appropiate message
                if (music.bookMusicSeat(seatMusicNumber))
                {
                    std::cout << "Seat Booked.\n"
                              << '\n';
                }
                else
                {
                    std::cout << "You selected an already booked seat.\n"
                              << '\n';
                }
            }

            else if (c == 2)
            {
                std::cout << "Stand-Up comedy seats available:";
                standUp.showStandUpSeats(); // display seats available for stand-up comedy;
                std::cout << "Please choose available  standing seats from above:" << '\n';
                int seatStandUpNumber;
                std::cin >> seatStandUpNumber;
                std::cout << "Enter seat number: ";
                // check if is valid seat
                while (seatStandUpNumber < 1 || seatStandUpNumber > standUp.getSeatsStandUpTotal())
                {
                    std::cout << "Invalid number, try again." << '\n';
                }
                // check if the seat is booked and display the appropiate message
                if (standUp.bookStandUpSeat(seatStandUpNumber))
                {
                    std::cout << "Seat Booked.\n"
                              << '\n';
                }
                else
                {
                    std::cout << "You selected an already booked seat.\n"
                              << '\n';
                }
            }

            else if (c == 3)
            {
                std::cout << "Film  seats available:" << '\n';
                std::cout << "Only 2D and 3D film " << '\n';
                film.showFilmSeats(); // display seats available for stand-up comedy;
                std::cout << "Please choose available  standing seats from above:" << '\n';
            }
        }
        // if the staff selects the option to cancel bookings
        else if (option == 2)
        {
            std::cout << "Select an event to cancel:" << '\n';
            std::cout << "(1)Live music" << '\n';
            std::cout << "(2)Stand-up comedy" << '\n';
            std::cout << "(3)Film" << '\n';
            std::cin >> c;
            if (c == 1)
            {
                // check if is any seat available to cancel for the live-music
                if (music.remainingMusicTickets() == 0)
                {
                    std::cout << "There is no seat to cancel" << '\n';
                }
                else
                {
                    std::cout << '\n';
                    music.showMusicSeats();
                    std::cout << "Select the seat number to cancel: ";
                    int seatMusicNumber;
                    std::cin >> seatMusicNumber;
                    while (seatMusicNumber < 1 || seatMusicNumber > music.getSeatsMusicTotal())
                    {
                        std::cout << "Invalid  seat number, try again." << '\n';
                        std::cout << "Enter seat number: ";
                        std::cin >> seatMusicNumber;
                    }
                    if (music.cancelMusicSeat(seatMusicNumber))
                    {
                        std::cout << "Seat successfully cancelled." << '\n';
                    }
                    else
                    {
                        std::cout << "You selected an unbooked seat."
                                  << '\n';
                    }
                }
            }
            // check if is any seat available to cancel for the stand-up comedy
            else if (c == 2)
            {
                if (standUp.remainingStandUpTickets() == 0)
                    std::cout << "There is no seat to cancel: "
                              << "\n";
                int seatStandUpNumber;
                std::cin >> seatStandUpNumber;
                while (seatStandUpNumber < 1 || seatStandUpNumber > standUp.getSeatsStandUpTotal())
                {
                    std::cout << "Invalid  seat number, try again." << '\n';
                    std::cout << "Enter seat number: ";
                    std::cin >> seatStandUpNumber;
                }
                if (standUp.cancelStandUpSeat(seatStandUpNumber))
                {
                    std::cout << "Seat successfully cancelled." << '\n';
                }
                else
                {
                    std::cout << "You selected an unbooked seat."
                              << '\n';
                }
            }
            // display no available seats for the film event
            else if (c == 3)
            {
                std::cout << "----------------------------------" << '\n';
                std::cout << "There  is no seat to cancel for the film event" << '\n';
                std::cout << "-----------------------------------" << '\n';
            }
        }
        else if (option == 3)
        {
            std::cout << "--Events--" << '\n';
            std::cout << "Live music" << '\n';
            std::cout << "Stand-Up Comedy" << '\n';
            std::cout << "Film  (2D or 3D)" << '\n';
            std::cout << "---------------" << '\n';
        }
        else if (option == 4)
        {
            std::cout << "Select an event:" << '\n';
            std::cout << "(1)Live music" << '\n';
            std::cout << "(2)Stand-Up Comedy" << '\n';
            std::cout << "(3)Film  (2D or 3D)" << '\n';
            std::cin >> c;
            // display the event details(seats available)
            if (c == 1)
            {
                std::cout << "The Live-Music event has the following "
                          <<"Seats available:\n"
                          << music.remainingMusicTickets()
                          << " (Standing Only)" << '\n';
                          
            }
            else if (c == 2)
            {
                std::cout << "The Stand-Up Comedy event has the following seats available:\n"
                          << standUp.remainingStandUpTickets()
                          << "(Standing Only)" << '\n';
            }
            else if (c == 3)

            {   std::cout << "----------------------------------" << '\n';
                std::cout << "There is no available seats for the Film event" << '\n';
                std::cout << "----------------------------------" << '\n';
            }
        }
        // load data from a file "events.txt" and display
        else if (option == 5)
        {
            std::ifstream File("events.txt");
            std::string str;
            std::string myText;

            while (std::getline(File, str))
            {
                myText += str;
                myText.push_back('\n');
            }
            std::cout << "All events and availabilty:" << '\n';
            std::cout << myText << '\n';
        }
        // save data to a file
        else if (option == 6)
        {
            std::ofstream file("events.txt");
            // write data(available ) to the events.txt file
            if (file.is_open())
            {
                file << "Live-Music :" << music.getSeatsMusicTotal() << '\n';
                file << "Stand-Up-Comedy:" << standUp.getSeatsStandUpTotal() << '\n';
                file << "Film_2D_or_3D:"
                     << "no seats";
            }
            else
                std::cout << "File cannot be open";
        }
        else
        {
            break;
        }
    }
    return 0;
}