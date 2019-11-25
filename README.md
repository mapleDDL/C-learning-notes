

### C++笔记

只对Python比较熟好像不太好找工作的样子，所以从零开始，复习（学习！）C++，刷刷LeetCode，把一些基础或者重要的干货记录下来！脚踏实地，世界永远不够。
附：基本参考菜鸟教程 https://www.runoob.com/cplusplus/cpp-tutorial.html 与 c++ Primer Plus(中文第六版)

##### 常用数据类型：

int，char，float， double

在函数内，局部变量的值会覆盖全局变量的值

定义常量常用的两种方法，将常量用大写字母表示是很好的习惯

```c++
#define LENGTH 10  
#define WIDTH  5
#define NEWLINE '\n'
const int  LENGTH = 10;
const int  WIDTH  = 5;
const char NEWLINE = '\n';
```

修饰符 **signed、unsigned、long 和 short** 可应用于整型，**signed** 和 **unsigned** 可应用于字符型，**long** 可应用于双精度型

**register** 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。寄存器只用于需要快速访问的变量，比如计数器

```c++
register int  miles;
```

**static** 存储类指示编译器在程序的生命周期内保持**局部变量**的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值

static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内

```c++
#include <iostream>
 
// 函数声明 
void func(void);
 
static int count = 10; /* 全局变量 */
 
int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}
// 函数定义
void func( void )
{
    static int i = 5; // 局部静态变量
    i++;
    std::cout << "变量 i 为 " << i ;
    std::cout << " , 变量 count 为 " << count << std::endl;
}
```

上述代码在多次调用fun()函数时，i的值得到了保持

------

##### 位运算符

^ 为异或预算，~为补码运算符，具有"翻转"位效果，即0变成1，1变成0

<< 为二进制左移运算符，左操作数的值向左移动右操作数指定的位数

\>> 为二进制右移运算符。左操作数的值向右移动右操作数指定的位数

杂项运算符

| sizeof                | sizeof 运算符返回变量的大小。例如，sizeof(a) 将返回 4，其中 a 是整数。 |
| --------------------- | ------------------------------------------------------------ |
| Condition ? X : Y     | 条件运算符。如果 Condition 为真 ? 则值为 X : 否则值为 Y。    |
| ,                     | 逗号运算符会顺序执行一系列运算。整个逗号表达式的值是以逗号分隔的列表中的最后一个表达式的值。 |
| .（点）和  ->（箭头） | 成员运算符用于引用类、结构和共用体的成员。                   |
| Cast                  | 强制转换运算符把一种数据类型转换为另一种数据类型。例如，int(2.2000) 将返回 2。 |
| &                     | 指针运算符 & 返回变量的地址。例如 &a; 将给出变量的实际地址。 |
| *                     | 指针运算符 * 指向一个变量。例如，*var; 将指向变量 var。      |

------

##### 循环与条件语句

while，for，do...while

循环控制语句

break，continue

无限循环

while（1）

for( ; ; )

条件判断语句

if else

switch

Exp1 ? Exp2 : Exp3;

------

##### 函数

函数是一组一起执行一个任务的语句。每个 C++ 程序都至少有一个函数，即主函数 **main()** ，所有简单的程序都可以定义其他额外的函数。

C++ 中的函数定义的一般形式如下：

```c++
return_type function_name( parameter list )
{
   body of the function
}

int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
```

一个函数可以返回一个值。return_type 是函数返回的值的数据类型。有些函数执行所需的操作而不返回值，在这种情况下，return_type 是关键字 **void**。

向函数传递参数的**传值调用**方法，把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数不会影响实际参数。

向函数传递参数的**指针调用**方法，把参数的地址复制给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。

向函数传递参数的**引用调用**方法，把引用的地址复制给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。

------

##### 数字

使用内置的数学函数，需要引用数学头文件 \<cmath\>。

```c++
#include <iostream>
#include <cmath>
using namespace std;
 
int main ()
{
   // 数字定义
   short  s = 10;
   int    i = -1000;
   long   l = 100000;
   float  f = 230.47;
   double d = 200.374;
 
   // 数学运算
   cout << "sin(d) :" << sin(d) << endl;
   cout << "abs(i)  :" << abs(i) << endl;
   cout << "floor(d) :" << floor(d) << endl;
   cout << "sqrt(f) :" << sqrt(f) << endl;
   cout << "pow( d, 2) :" << pow(d, 2) << endl;
 
   return 0;
}
```

随机数

```c++
#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
int main ()
{
   int i,j;
 
   // 用时间戳来设置种子
   srand( (unsigned)time( NULL ) );
 
   /* 生成 10 个随机数 */
   for( i = 0; i < 10; i++ )
   {
      // 生成实际的随机数
      j= rand();
      cout <<"随机数： " << j << endl;
   }
 
   return 0;
}
```

其中#include \<cstdlib\>中是一些常用的函数，但是又不知道把它们放到哪里合适，因此就都放到了stdlib.h这个头文件中，rand()与srand()就是其中的函数。

------

##### 数组

声明方法：type arrayName [ arraySize ];

```c++
double balance[10];
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
```

多维数组：

```c++
int a[3][4] = {  
 {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
 {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
 {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
};
int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
```

指向数组的指针

```c++
double *p;
double balance[10];

p = balance;
```

使用数组名作为常量指针是合法的，反之亦然。因此，\*(balance + 4) 是一种访问 balance[4] 数据的合法方式。一旦把第一个元素的地址存储在 p 中，您就可以使用\*p、\*(p+1)、\*(p+2) 等来访问数组元素。

传递数组给函数

C++  传数组给一个函数，数组类型自动转换为指针类型，因而传的实际是地址。如果想要在函数中传递一个一维数组作为参数，必须以下面三种方式来声明函数形式参数，这三种声明方式的结果是一样的，因为每种方式都会告诉编译器将要接收一个整型指针。

```c++
void myFunction(int *param) //形式参数是一个指针
{
.
.
}
void myFunction(int param[10]) //形式参数是一个已定义大小的数组
{
.
.
}
void myFunction(int param[]) //形式参数是一个未定义大小的数组
{
.
.
}
```

从函数返回数组

C++ 不允许返回一个完整的数组作为函数的参数。可以通过指定不带索引的数组名来返回一个指向数组的指针。另外，C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 **static** 变量。

```c++
#include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
// 要生成和返回随机数的函数
int * getRandom( )
{
  static int  r[10];
 
  // 设置种子
  srand( (unsigned)time( NULL ) );
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }
 
  return r;
}
 
// 要调用上面定义函数的主函数
int main ()
{
   // 一个指向整数的指针
   int *p;
 
   p = getRandom();
   for ( int i = 0; i < 10; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }
 
   return 0;
}
```

------

##### 字符串

C++ 提供了以下两种类型的字符串表示形式：

- C 风格字符串
- C++ 引入的 string 类类型

C 风格的字符实际上是使用 **null** 字符 '\0' 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。下面的声明和初始化创建了一个 "Hello" 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。

```c++
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char greeting[] = "Hello";
```

C++ 中有大量的函数用来操作以 null 结尾的字符串：

| 函数            | 作用                                                         |
| --------------- | ------------------------------------------------------------ |
| strcat(s1, s2); | 连接字符串 s2 到字符串 s1 的末尾，返回的是s1.                |
| strlen(s1);     | 返回字符串 s1 的长度。                                       |
| strcmp(s1, s2); | 如果 s1 和 s2 相同返回 0；如果 s1<s2 返回值小于 0；如果 s1>s2 返回值大于 0。 |
| strchr(s1, ch); | 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。   |
| strstr(s1, s2); | 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。 |
| strcpy(s1, s2); | 复制字符串 s2 到字符串 s。                                   |

```c++
#include <iostream>
#include <cstring>
 
using namespace std;
 
int main ()
{
   char str1[11] = "Hello";
   char str2[11] = "World";
   char str3[11];
   int  len ;
 
   // 复制 str1 到 str3
   strcpy( str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;
 
   // 连接 str1 和 str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;
 
   // 连接后，str1 的总长度
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;
 
   return 0;
}
```

String 类

基本操作示例：

```c++
#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;
 
   // 复制 str1 到 str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;
 
   // 连接 str1 和 str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;
 
   // 连接后，str3 的总长度
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
 
   return 0;
}
```

------

##### 指针

每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址。

```c++
#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var1;
   char var2[10];
 
   cout << "var1 变量的地址： ";
   cout << &var1 << endl;
 
   cout << "var2 变量的地址： ";
   cout << &var2 << endl;
 
   return 0;
}
```

**指针**是一个变量，其值为另一个**变量的地址**，即，内存位置的直接地址。就像其他变量或常量一样，必须在使用指针存储其他变量地址之前，对其进行声明。指针变量声明的一般形式为：

type *var-name;

**type** 是指针的基类型，它必须是一个有效的 C++ 数据类型，**var-name** 是指针变量的名称。用来声明指针的星号 * 与乘法中使用的星号是相同的，在这个语句中，星号是用来指定一个变量是指针。所有指针的值的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，都是一样的，都是一个代表内存地址的长的十六进制数。不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同。

在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为**空**指针。NULL 指针是一个定义在标准库中的值为零的常量。

int  *ptr = NULL;

可以对指针进行四种算术运算：++、--、+、-。这里ptr+1或-1表示移动4 个字节。指针也可以用关系运算符进行比较，如 ==、< 和 >。如果 p1 和 p2 指向两个相关的变量，比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。注：这里比较的是地址的大小而不是所指内容的大小。

指针和数组是密切相关的。事实上，指针和数组在很多情况下是可以互换的。例如，一个指向数组开头的指针，可以通过使用指针的算术运算或数组索引来访问数组。

```c++
#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中的数组地址
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "var[" << i << "]的内存地址为 ";
      cout << ptr << endl;
 
      cout << "var[" << i << "] 的值为 ";
      cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr++;
   }
   return 0;
}
```

也可以将指针地址存入数组中，即所谓的指针数组：

```c++
int  var[MAX] = {10, 100, 200};
   int *ptr[MAX];
 
   for (int i = 0; i < MAX; i++)
   {
      ptr[i] = &var[i]; // 赋值为整数的地址
   }
```

C++ 允许从函数返回指针。必须在定义函数时声明这是一个返回指针的函数，如下所示：

```c++
int * myFunction()
{
...
}
```

------

##### 引用

引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。引用很容易与指针混淆，它们之间有三个主要的不同：

- 不存在空引用。引用必须连接到一块合法的内存。
- 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
- 引用必须在创建时被初始化。指针可以在任何时间被初始化。

```c++
int&  r = i;
double& s = d;
```

C++之所以增加引用类型， 主要是把它作为函数参数，以扩充函数传递数据的功能。

```c++
#include <iostream>
using namespace std;
 
// 函数声明
void swap(int& x, int& y);
 
int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
 
   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;
 
   /* 调用函数来交换值 */
   swap(a, b);
 
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
 
   return 0;
}
 
// 函数定义
void swap(int& x, int& y)
{
   int temp;
   temp = x; /* 保存地址 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y  */
  
   return;
}
```

------

#####日期 & 时间

为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 \<ctime> 头文件。使用结构 tm 格式化时间如下：

```c++
#include <iostream>
#include <ctime>
 
using namespace std;
 
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
 
   cout << "1970 到目前经过秒数:" << now << endl;
 
   tm *ltm = localtime(&now);
 
   // 输出 tm 结构的各个组成部分
   cout << "年: "<< 1900 + ltm->tm_year << endl;
   cout << "月: "<< 1 + ltm->tm_mon<< endl;
   cout << "日: "<<  ltm->tm_mday << endl;
   cout << "时间: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}

/* 
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}
*/
```

------

##### 数据结构

结构是 C++ 中另一种用户自定义的可用的数据类型，它允许存储不同类型的数据项。

```c++
struct type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3;
...
} object_names;

struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;
```

实例：

```c++
#include <iostream>
#include <cstring>
 
using namespace std;
 
// 声明一个结构体类型 Books 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
int main( )
{
   Books Book1;        // 定义结构体类型 Books 的变量 Book1
   Books Book2;        // 定义结构体类型 Books 的变量 Book2
 
   // Book1 详述
   strcpy( Book1.title, "C++ 教程");
   strcpy( Book1.author, "Runoob"); 
   strcpy( Book1.subject, "编程语言");
   Book1.book_id = 12345;
 
   // Book2 详述
   strcpy( Book2.title, "CSS 教程");
   strcpy( Book2.author, "Runoob");
   strcpy( Book2.subject, "前端技术");
   Book2.book_id = 12346;
 
   return 0;
}
```

也可以把结构作为函数参数，传参方式与其他类型的变量或指针类似。

可以定义指向结构的指针，方式与定义指向其他类型变量的指针相似，如下所示：

```c++
struct Books *struct_pointer;
```

现在，可以在上述定义的指针变量中存储结构变量的地址。为了查找结构变量的地址，需要把 & 运算符放在结构名称的前面，如下所示：

```c++
struct_pointer = &Book1;
```

为了使用指向该结构的指针访问结构的成员，必须使用 -> 运算符，如下所示：

```c++
struct_pointer->title;
```

可以使用typedef 更简单地定义结构

```c++
typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}Books;
// 这样直接可以用Books 定义结构
Books Book1, Book2;
```

------

##### 类 & 对象

定义一个类，本质上是定义一个数据类型的蓝图。这实际上并没有定义任何数据，但它定义了类的名称意味着什么，也就是说，它定义了类的对象包括了什么，以及可以在这个对象上执行哪些操作。类的定义如下：

```c++
class Box
{
   public:
      double length;   // 盒子的长度
      double breadth;  // 盒子的宽度
      double height;   // 盒子的高度
};

Box Box1;          // 声明 Box1，类型为 Box
Box Box2;          // 声明 Box2，类型为 Box

// box 1 详述
Box1.height = 5.0; 
Box1.length = 6.0; 
Box1.breadth = 7.0;
 
// box 1 的体积
volume = Box1.height * Box1.length * Box1.breadth;
```

关键字 **public** 确定了类成员的访问属性。类的对象的公共数据成员可以使用直接成员访问运算符 (.) 来访问。

**类成员函数**

类的成员函数是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。类成员函数是类的一个成员，它可以操作类的任意对象，可以访问对象中的所有成员。

```c++
class Box
{
   public:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
   
      double getVolume(void)
      {
         return length * breadth * height;
      }
      // 成员函数声明 double getVolume(void);
};
/*
double Box::getVolume(void)
{
    return length * breadth * height;
}
*/
Box Box1;                // 声明 Box1，类型为 Box
v = Box1.getVolume();    // 计算Box1的体积
```

**类访问修饰符**

数据封装是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。类成员的访问限制是通过在类主体内部对各个区域标记 **public、private、protected** 来指定的。关键字 **public、private、protected** 称为访问修饰符。代码中没有声明的，默认为**private**成员。

```c++
class Base {
   public:
  // 公有成员
   protected:
  // 受保护成员
   private:
  // 私有成员
};
```

public成员在程序中类的外部是可访问的。您可以不使用任何成员函数来设置和获取公有变量的值，

private成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。

protected成员变量在派生类（即子类）中是可访问的，

**类的构造函数**

类的**构造函数**是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。

构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。构造函数可用于为某些成员变量设置初始值。

```c++
class Line
{
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // 这是构造函数
 
   private:
      double length;
};
 
// 成员函数定义，包括构造函数
Line::Line( double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
}

// 程序的主函数
int main( )
{
   Line line(10.0);
   return 0;
}
```

假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化，同理地，您可以使用上面的语法，只需要在不同的字段使用逗号进行分隔，如下所示：

```c++
C::C( double a, double b, double c): X(a), Y(b), Z(c)
{
  ....
}
```

**类的析构函数**

类的**析构函数**是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。 

析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。

```c++
Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}
```

**友元函数**

类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。

```c++
class Box
{
   double width;
public:
   double length;
   friend void printWidth( Box box );
   void setWidth( double wid );
};
```

再定义void printWidth( Box box );函数可以直接访问width变量。

**内联函数**

通常与类一起使用。如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。引入内联函数的目的是为了解决程序中函数调用的效率问题，程序在编译器编译的时候，编译器将程序中出现的内联函数的调用表达式用内联函数的函数体进行替换，而对于其他的函数，都是在运行时候才被替代。这其实就是个空间代价换时间的i节省。所以内联函数一般都是1-5行的小函数。在使用内联函数时要留神：

- 在内联函数内不允许使用循环语句和开关语句；
- 内联函数的定义必须出现在内联函数第一次调用之前；
- 类结构中所在的类说明内部定义的函数是内联函数。

**this 指针**

在 C++ 中，每一个对象都能通过 **this** 指针来访问自己的地址。**this** 指针是所有成员函数的隐含参数。因此，在成员函数内部，它可以用来指向调用对象。因此，在成员函数内部，它可以用来指向调用对象。友元函数没有 **this** 指针，因为友元不是类的成员。只有成员函数才有 **this** 指针。

```c++
class Box
{
...
      int compare(Box box)
      {
         return this->Volume() > box.Volume();
      }
...
};
// this 就是指自己对象
```

**指向类的指针**

访问指向类的指针的成员(包括函数)，需要使用成员访问运算符 **->**。

```c++
Box Box1(3.3, 1.2, 1.5);    // Declare box1
Box Box2(8.5, 6.0, 2.0);    // Declare box2
Box *ptrBox;                // Declare pointer to a class.

// 保存第一个对象的地址
ptrBox = &Box1;
cout << ptrBox->Volume() << endl;
```

**类的静态成员**

可以使用 **static** 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。静态成员在类的所有对象中是共享的。

如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。静态成员函数即使在类对象不存在的情况下也能被调用，**静态函数**只要使用类名加范围解析运算符 **::** 就可以访问。

------

**继承**

