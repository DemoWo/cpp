#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    int remainsMilk = 0, remainsWater = 0;
    int water, milk;
    int limit = 1;

    std::cout << "������� ���������� ���� � ����������: ";
    std::cin >> water;
    std::cout << "������� ���������� ������ � ����������: ";
    std::cin >> milk;

    std::string kofe;
    std::cout << "����� ���� �� ������? ��������� ��� �����: ";
    std::cin >> kofe;

    for (int waterInKofe = 0; water >= 270; waterInKofe = water) {

        for (int milkInKofe = 0; milk >= 30; milkInKofe = milk) {

            if (kofe == "�����" && milk >= 30 && water >= 270) {
                milk = milk - 30;
                water = water - 270;
                std::cout << "��� ������� �����.\n";
                std::cout << "������ � ����������� " << water << " ��. ����.\n";
                std::cout << "������ � ����������� " << milk << " ��. ������.\n";
            }
            if (kofe == "���������" && water >= 300) {
                water = water - 300;
                std::cout << "��� ������� �����.\n";
                std::cout << "������ � ����������� " << water << " ��. ����.\n";
                std::cout << "������ � ����������� " << milk << " ��. ������.\n";
            }
            if (water < 270 || water < 300) {
                std::cout << "�� ������� ����.\n";
                std::cout << "������ � ����������� " << water << " ��. ����.\n";
                break;
            }
            if (milk < 30) {
                std::cout << "�� ������� ������.\n";
                std::cout << "������ � ����������� " << milk << " ��. ������.\n";
                break;
            }
            std::cout << "��������� �������. ����� ���� �� ������? ��������� ��� �����: ";
            std::cin >> kofe;
            limit++;
        }
        std::cout << "����� ���� ������������ " << limit << " ��. ����.\n";
    }
    return 0;
}