#include <iostream>
#include <vector>

class Person 
{
public:
    Person* father = nullptr;
    Person* mother = nullptr;
};

bool areCousins(Person* p1, Person* p2)
{
    // ���������� ������ ��� ������ ����� ����� ������� ��� �������, �� �� �������� �� �������� �������� ��� ��������
    bool haveSameGrandparents = (p1->father->father == p2->father->father || p1->mother->mother == p2->mother->mother);
    bool parentsAreSiblings = (p1->father == p2->father || p1->mother == p2->mother);
    return haveSameGrandparents && !parentsAreSiblings;
}

bool areHalfSiblings(Person* p1, Person* p2)
{
    // ������� ������ ��� ������ ����� ������ ������ ��������
    return (p1->father == p2->father || p1->mother == p2->mother);
}

int main()
{
    system("chcp 1251");

    // ������� ����� �����
    Person* grandfather = new Person();
    Person* grandmother1 = new Person();
    Person* grandmother2 = new Person();
    Person* mother1 = new Person();
    mother1->father = grandfather;
    mother1->mother = grandmother1;

    Person* mother2 = new Person();
    mother2->father = grandfather;
    mother2->mother = grandmother2;

    Person* father1 = new Person();
    Person* father2 = new Person();

    // ������� ���� ������� ������� ��� ������
    Person* person1 = new Person();
    person1->father = father1;
    person1->mother = mother1;

    Person* person2 = new Person();
    person2->father = father1; // ��� ����� ������ ������ ����
    person2->mother = mother2; // �� �� ������ ����� ������ �������

    // ��������� �� ����������� �����
    if (areCousins(person1, person2)) {
        std::cout << "��� ���������� ������ ��� ������." << std::endl;
    }
    else if (areHalfSiblings(person1, person2)) {
        std::cout << "��� ������� ������ ��� ������." << std::endl;
    }
    else {
        std::cout << "��� �� �������� �� ����������� �������� ��� ��������, �� �������� �������� ��� ��������." << std::endl;
    }

    return 0;
}
