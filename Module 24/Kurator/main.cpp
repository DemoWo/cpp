#include <iostream>
#include <ctime>
#include <iomanip>

void time (){
  std::time_t t = std::time(nullptr);
	std::tm* local = std::localtime(&t);
  std::cout << std::asctime(local) << std::endl;
	std::cout << std::put_time(local, "%Y/%m/%d %H:%M:%S") << std::endl;
}

void input_time(){
  std::time_t t = std::time(nullptr);
  std::tm local = *std::localtime(&t);
  std::cin >> std::get_time(&local, "%H:%M");
  std::cout << asctime(&local) << std::endl;
}

void diff_time(){
  std::time_t a = std::time(nullptr);
  int foo;
  std::cin >> foo;
  std::time_t b = std::time(nullptr);

  double d = std::difftime(a,b);
  std::time_t f = b + (std::time_t)d;
  std::tm* local_future = std::localtime(&f);
  std::cout << std::asctime(local_future) << std::endl;
  local_future -> tm_sec += 12;
}

int main() {
  //вывод времени и даты
	time();
  //ввод времени и даты
  input_time();
  //разница во времени
  diff_time();
  return 0;
}