#include<iostream>
#include<string>
using namespace std;

class Pancake//����
{
public:
    string description = "Basic Pancake";
    virtual string getDescription(){ return description; }
    virtual double cost() = 0;
};


class CondimentDecorator :public Pancake//װ��������
{
public:
    string getDescrition();
};

class MeatPancake :public Pancake//����
{
public:
    MeatPancake(){ description = "MeatPancake"; }
    double cost(){ return 6; }
};
class EggPancake :public Pancake//�������
{
public:
    EggPancake(){ description = "EggPancake"; }
    double cost(){ return 5; }
};

class Egg :public CondimentDecorator//����Ӽ���
{
public:
    Pancake* base;
    string getDescription(){ return base->getDescription() + ", Egg"; }
    Egg(Pancake* d){ base = d; }
    double cost(){ return base->cost() + 1.5; }
};
class Potato :public CondimentDecorator//���������
{
public:
    Pancake* base;
    string getDescription(){ return base->getDescription() + ", Potato"; }
    Potato(Pancake* d){ base = d; }
    double cost(){ return base->cost() + 1; }
};
class Bacon :public CondimentDecorator//��������
{
public:
    Pancake* base;
    string getDescription(){ return base->getDescription() + ", Bacon"; }
    Bacon(Pancake* d){ base = d; }
    double cost(){ return base->cost() + 2; }
};
int main()
{
    Pancake* pan = new EggPancake();
    pan = &Potato(pan);
    pan = &Bacon(pan);
    cout << pan->getDescription() << "  $ : " << pan->cost() << endl;
    system("pause");
    return 0;
}
