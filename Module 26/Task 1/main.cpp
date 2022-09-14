#include <iostream>
#include <vector>

class TrackList
{
public:
    std::vector <std::vector<std::string>> track {{"Demons Protected by Angels", "9 Sep 2022", "1:22"},
                                                  {"Esperanza","11 Sep 2022","3:42"},
                                                  {"Woke Up In Love","9 Sep 2022","4:15"},
                                                  {"BREAK MY SOUL", "June 20, 2022", "4:38"}};

    void showTrack(int count){

        while (true)
        {
            for (int j = 0; j < track.size(); j++)
            {
                if (j == 0)
                {
                    std::cout << "Name track: " << track[count][j] << std::endl;
                }
                else if (j == 1)
                {
                    std::cout << "Date create track: " << track[count][j] << std::endl;
                }
                else if (j == 2)
                {
                    std::cout << "Duration track: " << track[count][j] << std::endl;
                }
            }
            std::cout << std::endl;
            break;
        }
    }
};

class Player
{
    int count = 0;
    TrackList *track = new TrackList();

public:

        void play() const
        {
            std::cout << "Playback" << std::endl;
            track -> showTrack(count);
        }
        void pause() const
        {
            std::cout << "On pause" << std::endl;
            track -> showTrack(count);
        }
        void next()
        {
            std::cout << "Next track" << std::endl;
            count = rand() % track -> track.size();
            track -> showTrack(count);
        }
        void stop() const
        {
            std::cout << "On stop" << std::endl;
            track -> showTrack(count);
        }
};

int main() {
    std::string command;
    auto* player = new Player();
    while (command != "exit")
    {
        std::cout << "Input command: (play/pause/next/stop/exit)" << std::endl;
        std::cin >> command;
        std::cout << std::endl;
        if (command == "play")
        {
            player -> play();
        }
        else if (command == "pause")
        {
            player -> pause();
        }
        else if (command == "next")
        {
            player -> next();
        }
        else if (command == "stop")
        {
            player -> stop();
        }
        else if (command != "exit")
        {
            std::cerr << "Error input!" << std::endl;
        }
    }
    std::cout << "The program is completed!" << std::endl;
    return 0;
}