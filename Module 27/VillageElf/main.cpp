#include <iostream>
#include <vector>

class Tree
{
  std::string name = "Empty";
  std::vector <Tree> branchs;

public:

void createTree(int maxBigBr,int minBigBr,int maxMidBr,int minMiBr)
{
  std::srand((unsigned int)time(nullptr));
        int countBigBranch = std::rand() % (maxBigBr - minBigBr + 1) + minBigBr;
        branchs.resize(countBigBranch);
        for (int i = 0; i < countBigBranch; i++)
        {
            std::cout << "Enter elf name on " << i + 1 << " big branch: ";
            std::cin >> branchs[i].name;
            int countMidBranch = std::rand() % (maxMidBr - minMiBr + 1) + minMiBr;
            branchs[i].branchs.resize(countMidBranch);
            for (int j = 0; j < countMidBranch; j++)
            {
                std::cout << "Enter elf name on " << i + 1 << " big branch " << j + 1 << " middle branch: ";
                std::cin >> branchs[i].branchs[j].name;
            }
        }
}

void createVillage (int countTree)
{
  branchs.resize(countTree);
  for (int i = 0; i < countTree; i++)
    {
      int maxBigBr = 5;
      int minBigBr = 3;
      int maxMidBr = 3;
      int minMiBr = 2;
      std::cout << i + 1 << " tree" << std::endl;
      createTree(maxBigBr, minBigBr, maxMidBr,  minMiBr);
    }
}

  void findElf(const std::string& fName, int countTree)
  {
    bool find = false;
    for (int k = 0; k < countTree; k++)
      {

        for (auto & branch : branchs)
        {
            int result = 0;
            if (branch.name == fName)
            {
                find = true;
            } else
            {
                if (branch.name != "None")
                {
                    ++result;
                }
            }
            for (auto & j : branch.branchs)
            {
                if (j.name == fName)
                {
                    find = true;
                }

                if (j.name != "None" && j.name != fName)
                {
                    ++result;
                }
            }
           if (find)
           {
                std::cout << fName << " found! This elf has " << result << " neighbors" << std::endl;
                return;
            }
        }
        std::cout << "On " << k + 1 << " tree. " << fName << " not found!" << std::endl;
      }
    }
};

int main()
{
  auto* tr = new Tree();
  std::string fName;
  int countTree = 1;
  tr -> createVillage(countTree);
  std::cout << "FIND. Enter name: ";
  std::cin >> fName;
  tr -> findElf(fName, countTree);
  return 0;
}