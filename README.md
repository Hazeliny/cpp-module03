# cpp-module03

继承的派生类只能访问protected和public的基类成员变量
A derived class can only access the protected and public member variables of the base class.

**虚函数 Virtual Functions**
virtual虚函数主要用于实现运行时多态，可以让程序在编译时不知道确切类型的情况下，在运行时根据实际类型选择调用正确的函数。在没有虚函数的情况下，基类指针或引用会调用基类的版本，而不是派生类的版本。虚函数允许基类的指针或引用在运行时“动态绑定”到正确的派生类版本。例如：当 Base* 类型的指针 ptr 指向 Derived 对象时，调用 ptr->show() 会执行Derived类的show()函数，而不是Base类的show()。这种运行时的多态性，就是通过virtual虚函数实现的。
The virtual keyword is primarily used to implement runtime polymorphism, allowing a program to select and call the correct function based on the actual type at runtime, even if the exact type is unknown at compile-time. Without virtual functions, a base class pointer or reference would call the base class version of a function, not the derived class version. Virtual functions enable a base class pointer or reference to "dynamically bind" to the correct derived class version at runtime. For example, when a pointer of type Base*, named ptr, points to a Derived object, calling ptr->show() will execute the show() function of the Derived class rather than that of the Base class. This runtime polymorphism is achieved through the use of virtual functions.

**什么情况下使用virtual关键字？When to Use the virtual Keyword?**
+ 当一个类设计为基类，且希望允许其他类派生并重写它的成员函数时，应在基类中将这些成员函数声明为 virtual。
+ When a class is designed to be a base class and is intended to allow other classes to derive from it and override its member functions, you should declare these member functions as virtual in the base class.
+ 析构函数通常也需要声明为虚函数，以确保通过基类指针删除派生类对象时，调用派生类的析构函数，防止内存泄漏。
+ Destructors should also generally be declared as virtual to ensure that when deleting a derived class object through a base class pointer, the derived class’s destructor is called, preventing memory leaks.

**注意：Note：**
+ 只有非静态成员函数才能是虚函数。
+ Only non-static member functions can be virtual.
+ 构造函数不能是虚函数。
+ Constructors cannot be virtual.
+ 虚函数的额外开销主要在于内存（虚表）和少量运行时性能损耗（查表调用）。
+ The overhead of virtual functions mainly includes memory usage (for the virtual table) and a small runtime performance cost (due to table lookup when calling virtual functions).

**为什么构造函数不能是虚函数？Why Constructors Cannot Be Virtual？**
构造函数在 C++ 中是不能被虚拟化的。因为当派生类的构造函数运行时，基类的部分还未完成构造，因此虚函数表（vtable）还没有完整的初始化。也就是说，没有机制可以实现基类构造函数的虚拟分发，所以也就不能根据实际的派生类动态调用不同的构造函数。
In C++, constructors cannot be virtualized. The reason is that during the construction of a derived class, the base class portion has not yet been fully constructed, meaning the virtual function table (vtable) is not completely initialized. As a result, there is no mechanism for virtual dispatch within the constructor of the base class, so the base class constructor cannot dynamically call a different constructor based on the actual derived type. In other words, polymorphic behavior is not possible in constructors because the object is not yet fully formed with all derived type information.

**菱形继承 Diamond Inheritance**
由基类ClapTrp衍生出两个派生类ScavTrap和FragTrap，再由这两个派生类共同衍生出DiamondTrap类，形成菱形继承链条。
In diamond inheritance, a base class, such as ClapTrap, has two derived classes, ScavTrap and FragTrap, and these two derived classes further derive into a final subclass, DiamondTrap, forming a diamond-shaped inheritance chain.
孙子类（DiamondTrap类）要访问祖父类（ClapTrap类）的成员变量与函数，中间衍生类（ScavTrap和FragTrap）必须对ClapTrap进行虚拟继承，即声明定义类时写成：class ScavTrap : public virtual ClapTrap。
To allow the grandchild class (DiamondTrap) to access the members and functions of the grandparent class (ClapTrap), the intermediate classes (ScavTrap and FragTrap) must use virtual inheritance. This is achieved by declaring the classes as follows: class ScavTrap : public virtual ClapTrap.

**菱形继承缺陷 Diamond Inheritance Issues**
菱形多重继承结构在对从基类继承来的变量赋值时发生覆盖，覆盖后的最终结果取决于最底层衍生类在声明定义时继承多个父类调用它们的构造函数的顺序，在C++中，虚拟继承的初始化顺序依赖于构造函数初始化列表中的顺序，例如class DiamondTrap : public ScavTrap, public FragTrap / class DiamondTrap : public FragTrap, public ScavTrap。
The diamond structure in multiple inheritance can lead to complications, especially with variable assignments inherited from the base class, where values may be overridden. The final result of these assignments depends on the order in which the most derived class (e.g., DiamondTrap) inherits and calls the constructors of multiple parent classes. In C++, the initialization order of virtually inherited classes is determined by the constructor’s initializer list order. For example, if DiamondTrap is declared as *class DiamondTrap : public ScavTrap, public FragTrap* or *class DiamondTrap : public FragTrap, public ScavTrap*, the order of inheritance will impact which base class constructor is called first.
原因是：在使用虚拟继承时，派生类会共享一个基类实例，因此在派生类的构造过程中，不论是哪一个虚拟派生类访问该共享基类成员，最终获得的值来自于该唯一的实例。这意味着如果在最终派生类（DiamondTrap）构造函数中直接设置了基类成员变量，那么它们会在构造顺序结束后覆盖先前的设置。虚拟继承带来的基类唯一性使得最下层派生类（如 DiamondTrap）中会看到最终构造的直接基类的值，导致之前的基类初始化值被覆盖。
The reason behind this complexity is that with virtual inheritance, derived classes share a single instance of the base class. This means that during the construction of the derived class, no matter which virtual base class accesses shared base class members, they will refer to this single instance. Consequently, if the final derived class (DiamondTrap) directly sets base class member variables in its constructor, these values will override any previously set values once the construction sequence completes. The unique base class instance created by virtual inheritance allows the final derived class (DiamondTrap) to see only the latest values from the directly constructed base class members, often leading to earlier base class initializations being overwritten.

**解决菱形继承问题的思路 Solution to Diamond Inheritance Problem**
避免多层派生类间的共享基类（替代设计）。
To address the complexities of diamond inheritance, it is often advisable to avoid shared base classes across multiple layers of derived classes by considering alternative designs.
在设计上，通过组合或其他方法来避免“钻石继承”（即，多个派生类继承同一个基类，然后被再次继承），从而减少复杂度。例如，将ScavTrap和FragTrap的共同部分放在新的类中，再在DiamondTrap中组合这些类。这种设计可以避免多层次的初始化和覆盖问题。
Instead of creating a diamond structure where multiple derived classes inherit from the same base class and are then further inherited, consider using composition or other methods to reduce the complexity. For instance, if ScavTrap and FragTrap share common functionality, you can create a new class encapsulating these shared elements, which can then be included as components within DiamondTrap. This approach helps prevent the multi-level initialization and override issues associated with diamond inheritance.

**虚拟继承 Virtual Inheritance**
ClapTrap 被虚拟继承，例如：class ScavTrap : public virtual ClapTrap。在构造 DiamondTrap 对象时，ClapTrap 的拷贝构造函数和赋值运算符只会被调用一次。这就是虚拟继承的特性，确保基类 ClapTrap 只构造一次并且不会被重复赋值。虚拟继承使最终派生类中的基类只实例化一次，在最终衍生类DiamondTrap中只产生一个ClapTrap基类的subobject。
When ClapTrap is virtually inherited (e.g., class ScavTrap : public virtual ClapTrap), constructing a DiamondTrap object results in ClapTrap's constructor and assignment operator being called only once. Virtual inheritance ensures that the base class (ClapTrap) is constructed only once, preventing redundant assignments or duplicate instances. This is due to virtual inheritance's unique feature: in the final derived class (DiamondTrap), the base class ClapTrap exists as only a single subobject, thereby avoiding multiple instantiations.

**-Wshadow** 
它是一个 GCC 和 Clang 编译器的警告选项，用于检测在 C++ 代码中定义了“遮蔽”其他变量的局部变量。
The -Wshadow compiler flag, available in GCC and Clang, is a warning option used to identify situations in C++ code where a local variable “shadows” or hides another variable with the same name, typically one in an outer scope. This helps avoid unintentional variable masking, which can lead to difficult-to-find bugs.
