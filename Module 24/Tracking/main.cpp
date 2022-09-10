#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
#include <vector>

std::string check_time(std::string time_save){
  char buffer[80];
  std::time_t t = std::time(nullptr);
	std::tm local = *std::localtime(&t);
  std::ostringstream oss;
  oss << std::put_time(&local, "%Y/%m/%d %H:%M:%S");
  time_save = oss.str();
  return time_save;
}

void print_t (){
  for (int i = 0; i < 20; i++)
      std::cout << "-";
  std::cout << std::endl;
}

void input_comand (){
  std::string input;
  std::string inputTask;
  std::string time_now;
  std::vector <std::string> iMap;
  bool startStat = true;
  std::string taskEnd;
  std::time_t startTime = 0, endTime = 0;
  std::multimap <std::string, std::vector<std::string>> localMap;
  while (input != "exit"){
    std::vector <std::string> iMap;
    std::cout << "Input comand:(begin, end, status, exit)" << std::endl;
    std::cin >> input;
    print_t();

    if (input == "begin"){
      std::cout << "Input task name:" << std::endl;
      std::cin >> inputTask;
      print_t();

        if (startStat == false){
          time_now = check_time(time_now);
          std::time (&endTime);
          int num_sec = std::difftime(endTime, startTime);
          std::string sec = "The time spent on the task is " + std::to_string(num_sec) + " seconds!";
          iMap.push_back(sec);
          iMap.push_back("Task: " + taskEnd);
          iMap.push_back("Status: end");
          localMap.emplace(time_now, iMap);
          startStat = true;

          iMap.clear();

        }

        if (startStat == true){
          time_now = check_time(time_now);
          std::time (&startTime);
          iMap.push_back("Task: " + inputTask);
          iMap.push_back("Status: start");
          localMap.emplace(time_now, iMap);
          startStat = false;
          taskEnd = inputTask;
        }

    }
    else if (input == "status"){
      if (!localMap.empty()) {
        for (auto &it : localMap){
          std::cout << it.first << std::endl;
          for (auto itVec : it.second){
            std::cout << itVec << std::endl;
          }
        std::cout << std::endl;
        }
        print_t();
      } else {
        std::cout << "The task list is empty" << std::endl;
      }
    }
    else if (input == "end"){
      if (!localMap.empty()){
        time_now = check_time(time_now);
        std::time (&endTime);
        int num_sec = std::difftime(endTime, startTime);
        std::string sec = "The time spent on the task is " + std::to_string(num_sec) + " seconds!";
        iMap.push_back(sec);
        iMap.push_back("Task: " + taskEnd);
        iMap.push_back("Status: end");
        localMap.emplace(time_now, iMap);
        startStat = true;
        iMap.clear();
        std::cout << "Task the closed!" << std::endl;
      } else {
        std::cout << "The task list is empty" << std::endl;
      }
    }
    else if (input != "exit"){
      std::cout << "Error input!" << std::endl;
    }
  }
  std::cout << "You have exited the program!" << std::endl;
}

int main() {
  input_comand();
  return 0;
}