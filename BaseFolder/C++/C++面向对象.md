# 面向对象的四大特性

C++语言是一门支持面向对象特性的语言。今天我们谈谈面向对象的四大特性在C++语言中，底层是如何实现的，以及这种实现的优劣。

1. 封装
在面向对象的思维中，封装的直接目标实现了对信息和实现细节隐藏的功能，而对外通过接口来提供服务。这种特性限制了用户对实现细节的依赖和可能的非法的修改，导致对象状态的不一致。从设计原则来讲，信息和实现细节不重要，属于容易变化的部分，而接口相对稳定，外部的用户程序依赖接口而不是实现细节，这有助于提升程序的可扩展性，增强了程序抵御变化的能力。
封装，最主要的体现是在于对于变化的封装，将变化限制在某个范围内，不至于让其散落在程序的各个角落里。程序如建筑物的房间，而变化犹如活泼跳脱的兔子，如果不加以限制，他会在整个房间来回乱跳。我们应该将变化像小兔子一样关在房间的某个笼子里，而不是让其在更个房间乱窜，弄乱整个房间。

我们先看看C++对于封装的支持：

```
    // file point.h
    class Point {
    public:
    Point(_;int x = 0 ,int y = 0); // 实现放在point.cpp文件中
    ~Point(); 					 // 实现放在point.cpp文件中
    
    public:
    int getX() const; // 实现放在point.cpp文件中
    int getY() const; // 实现放在point.cpp文件中
    void setX(int x); // 实现放在point.cpp文件中
    void setY(int y); // 实现放在point.cpp文件中
    
    private:
    int x_;
    int y_;  
    }；

```

```
    // 客户端
    #include "point.h"

    void client() {
    Point point(1, 1);
    std::cout << "x = " << point.GetX() << std::endl;
    std::cout << "y = " << point.GetY() << std::endl;

    point.setX(10);
    point.setY(20);
    
    std::cout << "x = " << point.GetX() << std::endl;
    std::cout << "y = " << point.GetY() << std::endl;
    }

```

在C++中我们通过类Point隐藏了Point的实现细节。通过构造函数，我们可以获得一个Point对象，通过接口{GetX(), GetY(), setX(), setY()}接口来操作数据。用户可以不用关注接口的实现，只需知道Point类具有{GetX(), GetY(), setX(), setY()}这组接口即可。
这里我们稍微讨论下C++对封装的支持：在客户端，需要获得一个Point的对象，我们必须知道Point类的完整定义(尽管不需要知道所有成员函数的实现)，我们还是可以知道它的数据成员{x_, y_}，只是假装看不见而已。任何对于数据成员的增删，都会导致客户端程序的重新编译。所以C++语言对于封装的原生支持谈不上Perfect。在这一点上C语言就好很多，如下：

```
    // file point.h  客户依赖此文件
    void *getInstance(int x = 0, int y = 0);
    void dreleaseInstance(void *instance);
    int getX(void *instance);
    int getY(void *instance);
    void setX(void *instance, int x);
    void setY(void *instance, int y);

    // file point.c
    struct Point {
    int x, int y;
    };

    void *getInstance(int x = 0, int y = 0) {
    struct Point *ptr = (struct Point *)malloc(sizeof(Point));
    ptr->x = x;
    ptr->y = y;
    return ptr;
    }
    void dreleaseInstance(void *instance) { free(instance); }
    int getX(void *instance) { return ((struct Point *)instance)->x; }
    int getY(void *instance) { return ((struct Point *)instance)->y; }
    void setX(void *instance, int x) { ((struct Point *)instance)->x = x; }
    void setY(void *instance, int y) { ((struct Point *)instance)->y = y; }
```

```

    // 客户端
    #include "point.h"

    void client() {
    void *ptr = getInstance(1, 1);
    std::cout << "x = " << getX(ptr) << std::endl;
    std::cout << "y = " << GetY(ptr) << std::endl;

    setX(ptr, 10);
    setY(ptr, 20);

    std::cout << "x = " << GetX(ptr) << std::endl;
    std::cout << "y = " << GetY(ptr) << std::endl;

    releaseInstance(ptr);
    }
```

对比C++，C语言的封装就接近Perfect，任何对于Point的实现变动，都不会导致客户端程序的重新编译，解决了编译时依赖问题，使得Point和Point的使用者可以独立开发，独立部署。

2. 继承
继承的首要目的是为了实现数据和功能的复用，是为了提升软件复用性而存在的技术。继承关系常称为父子关系，而这种称谓，会导致很多勿用，在实际编程中会出现一些奇怪的继承现象。比如鸟和鸵鸟，矩形和正方形，是否可以用继承来建模？我觉得不可以。
继承常常被夸大其功能，但我们应该记住继承是解决软件复用问题的一种方案，而不是唯一方案，更不是银弹。
继承是一种类–类之间的静态结合关系，是编译时的依赖，可扩展性差。在实体和实体之间的继承，可以转化为组合关系来实现软件复用，比如工人和人的关系，是继承好还是组合好？ Worker -- Person
继承这种技术手段在多种静态语言中，如C++ JAVA C#中也是用来实现多态的手段。继承和虚函数结合的时候能够将依赖关系控制在一个抽象的层次，能够将实现与抽象解耦，在代码层面对于创造松耦合的软件系统具有关键作用。在C++中， class A : public B {}即表示A继承B,也表示A实现B。而在JAVA中，继承和实现是通过不同语法机制实现的。如 class A extends B{ }叫继承或扩展；而class A implements B{ }叫做实现，对应于C++中的对抽象类的继承。

C++中通过继承来实现类的数据和功能复用，这在底层是如何实现的呢？
我们仍然以Point类为例，但做了简化。我想定义一个3D的Point3D，在C语言中是否可以复用Point类的实现呢？

```

    // file point.h
    struct Point {
    int getX() const; // 实现放在point.cpp文件中
    int getY() const; // 实现放在point.cpp文件中
    void setX(int x); // 实现放在point.cpp文件中
    void setY(int y); // 实现放在point.cpp文件中
    
    int x_;
    int y_;
    };

    struct Point3D {
    int x_;
    int y_;
    int z_;
    
    int getZ() const; // 实现放在point.cpp文件中
    void setZ(int z); // 实现放在point.cpp文件中
    };

```


```

    // 客户端
    void client() {
    Point p3{1, 2, 3};

    // 模拟继承
    point* ptr = (point*)(p3);
    ptr->getX(); // 成功获得 1
    ptr->getY(); // 成功获得 2
    ptr->getZ(); // 失败
    p3->getZ(); //  成功获得 3
    }

```

上述两个类在字段上有公有部分。在C语言中，没有显示的语法机制将类Point 和 Point3D联系起来，但是我们可以通过强制类型转换(如上客户端所示)使二者产生联系 — 静态联系，进而复用Point代码。
类 Point3D对象的内存布局是在类Point的对象后面多追加了一个int的空间。
如下：

类Point2D对象	内存布局	内容

x_	            4字节	    1

y_	            4字节	    2

类Point3D对象	内存布局	内容

x_	            4字节	    1

y_	            4字节	    2

z_	            4字节	    3

在C++中，我们可以通过class Point3d: public　Point {...}来产生相同的内存模型。在Ｃ++中继承的实现就是通过在派生类的前半部分，添加一个父类对象来实现复用的。这种简洁的语法机制，相比C语言强制类型转换的野路子有助于提高程序的安全性，可读性。

C++中的继承关系类图如下，内存模型如上表:

Point

Point3D


3. 抽象
有人不认为抽象是面向对象的特性。诚然，抽象不止是面向对象独有的特性。计算机系统中总是存在着抽象，比如指令集是对硬件的复杂的指令系统的运行过程进行抽象建模，提供给人一个简洁线性的模型，这种模型并不是实际系统，但是基于它，思考起来负担不会过重，而且依据这个模型，得到的思维产物，也不会错，至少能解决实际中大多数问题。
在C++语言中，只含有数据的类或称聚合类就是抽象的一种体现，是对数据的抽象。比如{age,sex ,name, ...}这个属性集合可以用Person这个类来抽象，这种抽象提供了更高层的语义，形成了人的概念，而不再是一堆数据。为了说明这个问题，这里我们做了一个假设{age,sex ,name}这个属性集合完全描述了Person这个概念的属性。
C++语言中还有别的抽象，比如对行为的抽象，行为的集合叫做接口，在C++语言中是abstract class，比如{open, read, wirite, release, ...}这个行为集合完全阐释了文件或设备的操作，故形成了file_operations文件和设备操作的接口；再比如{update, move, think, speak, ...}形成了Person的完整行为，可作为Person的接口。
在C语言，linux系统中，同样存在抽象。比如C语言的结构体；linux系统的file_operations结构体，抽象了对文件、设备的访问。提供了统一的{open, read, wirite, release, ...}接口供外界依赖和使用，这虽然不具备面向对象之名，却具有面向对象之实。

```
    struct file_operations {
       ssize_t (*read) (int fd, char* buffer, size_t size_to_read);
       ssize_t (*write) (int fd, const char * buffer, size_t size_to_write);
       int (*open) (char* file_name, int mode);
	   void (*release) ();
    };
```

抽象和分解是通用的思维方式和手段。抽象是归纳和总结，将对象的通用行为和属性抽象出来，忽略个体差异，进行统一思考和管理；分解是化整为零，降低思维难度，逐个击破，分而治之，最终完成对整个大问题的求解。

类定义本身就是一种抽象：数据抽象

```

    class AbstractDataType { ... };

```


另一种抽象是行为抽象

```
    // cpp语言 抽象类或叫行为集合
    class Iterface {
    public:
    virtual void action1() = 0; 
    virtual void action2() = 0; 
    virtual void action3() = 0; 
    };

```

```
// java语言 抽象类或叫行为集合
public interface Iterface {
   void action1(); 
   void action2(); 
   void action3(); 
 };
```


行为抽象要和多态特性结合或者说依赖多态特性才能发挥作用。


4. 多态
多态特性是一种形式，多种表现。行为和行为实现分离，是建立在抽象的基础上。比如{动物}和{人， 鱼，燕子}，这是一般与个体，抽象和具体的关系。动物都具有行走的能力，额… 不太正确，因为鱼不能走，那怎么办，因为行走这个行为不够抽象，我们应该换成更有哲学意味的说法，叫做动物都具有能够移动自己身体的行为或动物具有能够与周遭环境发生物理作用而改变自己的空间位置的行为特性。
all animals can move; humans can walk, fish can swim, birds can fly.
{move} —> {walk, swim, fly}这是一般与个体，抽象和具体的关系。人通过walk；鱼通过swim；燕子通过fly这些具体的行为实现了move的抽象行为; 抽象层面的描述动物能移动还是没法具体知道他能如何行走的；直到具体到了[人能walk，鱼能swim；燕子可以fly]才能使得这个描述具有真正的具体层面的行为意义。
这种基于 animals can move级别的编程而不是humans can walk, fish can swim, birds can fly的编程层次能够极大提高系统的可扩展性，可维护性。
编程和做人一样都不能太实在。把话说死或把事做死，就没有回旋的余地了。

linux中字符设备驱动数据结构file_operations记录了设备和文件的操作接口。不同的设备和文件具有不同的实现。比如[串口] 可以有自己的{open read write ...}实现，[a.txt]磁盘文件也有自己的{open read write ...}实现。但都可以通过同样的接口{open read write ...}来操作，这是怎么做到的呢？

```
    // file file_operations.h
    struct file_operations {
    ssize_t (*read)(int fd, char *buffer, size_t size_to_read);
    ssize_t (*write)(int fd, const char *buffer, size_t size_to_write);
    int (*open)(char *file_name, int mode);
    void (*release)();
    };

```

```
    //
    // ******************串口实现***********************
    //
    ssize_t serial_read(int fd, char *buffer, size_t size_to_read) {
    // 串口读操作实现
    }

    ssize_t serial_write(int fd, const char *buffer, size_t size_to_write) {
    // 串口写操作实现
    }

    int serial_open(char *file_name, int mode) {
    // 串口打开操作实现
    }

    void serial_release() {
    // 串口关闭操作实现
    }

    // 定义在内核空间中，注册内核
    extern file_operations *serial_ops;
    // 填充表格
    serial_ops->open = serial_open;
    serial_ops->read = serial_read;
    serial_ops->write = serial_write;
    serial_ops->release = serial_release;

```

```
    //
    // ******************磁盘文件实现***********************
    //
    ssize_t file_read(int fd, char *buffer, size_t size_to_read) {
    // 磁盘文件读操作实现
    }

    ssize_t file_write(int fd, const char *buffer, size_t size_to_write) {
    // 磁盘文件写操作实现
    }

    int file_open(char *file_name, int mode) {
    // 磁盘文件打开操作实现
    }

    void file_release() {
    // 磁盘文件关闭操作实现
    }

    // 定义在内核空间中，注册内核
    extern file_operations *file_ops;
    // 填充表格
    file_ops->open = file_open;
    file_ops->read = file_read;
    file_ops->write = file_write;
    file_ops->release = file_release;
```

```
    // 客户端
    extern file_operations *serial_ops, file_ops;
    void client() {
    // 多态指针
    file_operations *device = file_ops; // 指向了对象 file
    device->open("a.txt", 1 | 2 | 4);   // 打开磁盘文件  -- 多态调用

    device = serial_ops;                     // 指向了对象 serialPort
    device->open("/dev/ttyUSB0", 1 | 2 | 4); // 打开串口设备  -- 多态调用
    }

```

这里的file_operations相当于虚表，每个类[serialPort, file]都具有一个虚表，device相当于基类指针。用C++来翻译上述代码就是：

```
    // 虚基类定义
    class Device {
    public:
    virtual ssize_t read(int fd, char *buffer, size_t size_to_read) = 0;
    virtual ssize_t write(int fd, const char *buffer, size_t size_to_write) = 0;
    virtual int open(char *file_name, int mode) = 0;
    virtual void release() = 0;
    };
```

```
    // 串口类实现定义
    class SerialPort : public Device {
    public:
    ssize_t read(int fd, char *buffer, size_t size_to_read) override {
        serial_read();
    }
    ssize_t write(int fd, const char *buffer, size_t size_to_write) override {
        serial_write();
    }
    int open(char *file_name, int mode) override { serial_open(); }
    void release() override { serial_release(); }

    private:
    void serial_open() {}
    void serial_read() {}
    void serial_write() {}
    void serial_release() {}
    };

```

```
// 磁盘文件类实现定义
class File : public Device {
public:
  ssize_t read(int fd, char *buffer, size_t size_to_read) override {
    file_read();
  }
  ssize_t write(int fd, const char *buffer, size_t size_to_write) override {
    file_write();
  }
  int open(char *file_name, int mode) override { file_open(); }
  void release() override { file_release(); }

private:
  void file_open() {}
  void file_read() {}
  void file_write() {}
  void file_release() {}
};

```

```
    // 客户端
    void client() {
    // 多态指针
    Device* device = new File(); // 指向了对象 file
    device->open("a.txt", 1 | 2 | 4);   // 打开磁盘文件  -- 多态调用

    device = new SerialPort();  // 指向了对象 serialPort
    device->open("/dev/ttyUSB0", 1 | 2 | 4); // 打开串口设备  -- 多态调用
```
多态是通过虚函数+虚表实现的。虚函数可以类比linux字符设备驱动file_operations中的函数指针，虚表是与具体实现类关联的登记表。虚函数和虚表中的某项具有相同的原型，即虚函数可以指向虚表中的某个项目。
C++从语言实现层面给多态给予了支持，将很多工作交给了编译器去做，省去程序员自己去管理函数指针的工作。比C的函数指针的方式更安全，友好。
多态引入了一层间接性(虚函数表)，会在运行时有些许性能损失，但带来了程序极大的灵活性和可扩展性，很多设计原则[SOLID]和大部分[设计模式]都是运用了多态特性。


