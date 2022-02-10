#include<iostream>
#include<string>
using namespace std;

class Pancake//基类
{
public:
    string description = "Basic Pancake";
    virtual string getDescription(){ return description; }
    virtual double cost() = 0;
};


class CondimentDecorator :public Pancake//装饰器基类
{
public:
    string getDescrition();
};

class MeatPancake :public Pancake//肉煎饼
{
public:
    MeatPancake(){ description = "MeatPancake"; }
    double cost(){ return 6; }
};
class EggPancake :public Pancake//鸡蛋煎饼
{
public:
    EggPancake(){ description = "EggPancake"; }
    double cost(){ return 5; }
};

class Egg :public CondimentDecorator//额外加鸡蛋
{
public:
    Pancake* base;
    string getDescription(){ return base->getDescription() + ", Egg"; }
    Egg(Pancake* d){ base = d; }
    double cost(){ return base->cost() + 1.5; }
};
class Potato :public CondimentDecorator//额外加土豆
{
public:
    Pancake* base;
    string getDescription(){ return base->getDescription() + ", Potato"; }
    Potato(Pancake* d){ base = d; }
    double cost(){ return base->cost() + 1; }
};
class Bacon :public CondimentDecorator//额外加培根
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
