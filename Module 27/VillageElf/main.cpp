#include <iostream>
#include <vector>

class Village
        {
    std::vector <int> branch;

        public:

    struct BRANCH
    {
        std::string *nameElf;
        std::vector <int> bigBranch;
        std::vector <int> middleBranch;
    };

            static void elfHome ()
            {
                BRANCH branch1;

              for (int i = 0; i < 5; i++)
              {
                  branch1.bigBranch.push_back(3 + rand() % (6 - 3));

                  for (int k = 0; k < branch1.bigBranch[i]; k++)
                    branch1.middleBranch.push_back(2 + rand() % (4 - 2));
              }
              for (int j = 0; j < 5; j++)
              {
                  std::cout << branch1.bigBranch[j] << " / " ;

                  for (int h = 0; h < branch1.bigBranch[j]; h++)
                    std:: cout << branch1.middleBranch[j] << " ";
                  std::cout << std::endl;
              }
            }
        };

int main() {
    Village::elfHome();
    return 0;
}
