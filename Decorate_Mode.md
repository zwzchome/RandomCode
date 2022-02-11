# 装饰者模式

## 示例代码一

```c

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
```



## 示例代码二

```c
// 1.首先我们有一个Pen接口
public interface Pen {
  public void write();
}
// 2.Pencil类实现了Pen这个接口
public class Pencil implements Pen {
    public void write () {
        System.out.print("写");
    }
}
// 3.装饰类PencilDecorator也实现了Pen这个接口，且代理调用Pencil的方法
public class PencilDecorator implements Pen{
    Pen pen;
    public PencilDecorator(Pen pen) {
      this.pen = pen;
    }
    public void write () {
      pen.write();
    }
}
// 4.用具体装饰类继承PencilDecorator，这样就可以做扩展变化
public class BluePencilDecorator extends PencilDecorator{
    public BluePencilDecorator (Pen pen) {
        super(pen);
    }
    public void writeBlue () {
        this.write();
        System.out.println("写出来是蓝色的");
    }
}
// 同4.用具体装饰类继承PencilDecorator，这样就可以做扩展变化
public class RedPencilDecorator extends PencilDecorator{
    public RedPencilDecorator (Pen pen) {
        super(pen);
    }
    public void writeRed () {
        this.write();
        System.out.println("写出来是红色的");
    }
}
// 测试
public class Test {
    public static void main(String args []) {
       Pen pencil = new Pencil();
       RedPencilDecorator redPencil = new RedPencilDecorator(pencil);
       BluePencilDecorator bluePencil = new BluePencilDecorator(pencil);
       redPencil.writeRed();
       bluePencil.writeBlue();
    }
}
```


