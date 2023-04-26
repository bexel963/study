using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
    - 참조 형식 
        
        System.Object---->   System.ValueType    ->      System.Enum
              |
              |
              ----------->   System.String, System.Array, ...., 사용자 정의 클래스 및 인터페이스

    - 값 형식

        System.ValueType 중 System.Int32, System.Boolean, ..., 사용자 정의 구조체
        System.Enum 중 모든 열거형...


    - 값 형식
        : System.Object -> System.ValueType 에서 파생됨.
        : 변수가 직접 값을 저장하는 형
        : 기본 데이터형, 구조체, 열거형
        : 선언 vs 생성(new)

    - 참조 형식
        : 한 객체를 참조형 변수가 사용할 때 참조형에 의해 내용이 바뀌면 객체에 영향을 준다.
        : class, interface, delegate, 배열, string
        : 객체와 참조형 사이의 대입은 객체의 메모리 주소가 복사된다.
*/

namespace ConsoleApp01
{
    class Ch03
    {
        /*
            - 구조체
                : 형식
                    public struct 구조체명 
                    { 
                
                    }
                    C++ 에서는 키워드 public이 암시적으로 사용되지만 C# 에서는 이를 명시적으로 작성해 줘야한다.
                : C에서는 C++과 C#과 달리 구조체에 메서드를 넣을 수 없다.
                : 제한 사항
                    1) 구조체에 선언된 const, static 변수만 초기화 가능. 나머지는 초기화 할 수 없다.
                    2) 구조체 안에 선언할 수 있는 생성자는 매개변수가 반드시 있어야 함     
                    3) 구조체를 같은 구조체에 대입하게 되면 값이 복사된다.
                    4) 구조체는 값 형식이고 클래스는 참조 형식이다.
                    5) 구조체는 값 형식이므로 선언만으로도 사용 가능
                    6) new를 사용했을 대만 생성자가 호출되고 기본값으로 초기화 된다.
                    7) 구조체는 C++과 달리 구조체 또는 클래스에 상속할 수 없다.
                    8) 구조체는 인터페이스를 상속하여 메서드를 구현할 수 있다.
        */
        public struct MyStruct
        {
            public const float PI = 3.14f;
            public static int Age = 12;
            public int val;     // 초기화 못 함.

            public MyStruct(int v)  // 이렇게 초기화 해야함.
            {
                val = v;
            }
        }
        class MyClass
        {
            public int age;
        }
        public struct MyStruct2
        {
            public int Age;
            public float Num2;
            public bool IsReady;
        }

        public struct Grade
        {
            public int kor;
            public int eng;
            public int math;
            public int sum;
            public float avg;

            public void Compute(int k, int e, int m)
            {
                sum = k + e + m;
                avg = sum / 3.0f;
            }
        }

        /*
            - 열거형
                : 상수를 문자열로 대치하여 선언 (상수에 의미 부여)
                : 형식
                    enum 열거형 명칭 { 문자열1, 문자열2 };
                    enum 열거형 명칭 { 문자열1 = 상수, 문자열2 = 상수 };
                    enum 열거형 명칭 { 문자열1 = 상수, 문자열2 };
                : 기본은 int형 이지만 char형을 제외한 형식을 지정할 수 있다.
                    enum Days : byte { Sun = 0, Mon, Tue, Wed, Thu };   // byte로 지정...
                : 기본적으로 열거형 변수의 값은 열거형 변수에만 사용해야 한다. 
                  열거형 변수가 아닌 변수에 열거형 값을 대입할 때는 데이터형을 명시해야한다.(캐스팅)
        */
        enum Days { Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat };
        
        static void Main(string[] args)
        {
            Console.WriteLine("-------------------------열거형-------------------------");
            int nValue = (int)Days.Mon;
            Days day = Days.Tue;
            Console.WriteLine("{0}, {1}", nValue, day);
            Console.WriteLine("-------------------------------------------------------");

            Console.WriteLine("-------------------------구조체-------------------------");

            Console.WriteLine("{0}, {1}", MyStruct.PI, MyStruct.Age);
            MyStruct ms;
            ms.val = 10;
            Console.WriteLine(ms.val);

            MyStruct testStruct1;   // 값 형식: 기본형과 동일하게 선언한 것만으로도 메모리가 생성됨. (선언만으로 바로 사용 가능)
            testStruct1.val = 100;
            MyStruct testStruct2 = new MyStruct(200);
            MyStruct testStruct3 = new MyStruct();  // 기본 생성자에 의해 해당 멤버가 0으로 자동으로 세팅된다.
            Console.WriteLine("{0}, {1}, {2}", testStruct1.val, testStruct2.val, testStruct3.val);

            MyStruct copy1, copy2;
            copy1.val = 999;
            copy2 = copy1;
            Console.WriteLine("{0}, {1}, {2}", copy1.val, copy2.val, copy1);

            MyStruct testS1 = new MyStruct();
            MyStruct testS2 = new MyStruct();
            testS1.val = 12;
            testS2 = testS1;
            testS2.val = 24;
            Console.WriteLine("{0}, {1}", testS1.val, testS2.val);  // 12, 24 -> 구조체는 값 형식

            MyClass testC1 = new MyClass();
            MyClass testC2 = new MyClass();
            testC1.age = 12;
            testC2 = testC1;
            testC2.age = 24;
            Console.WriteLine("{0}, {1}", testC1.age, testC2.age);  // 24, 24 -> 클래스틑 참조 형식...

            MyStruct2 ms2 = new MyStruct2();
            Console.WriteLine("{0}, {1}, {2}", ms2.Age, ms2.Num2, ms2.IsReady); // bool은 초기값이 False 이다.

            Console.WriteLine("국, 영, 수 점수를 차례로 입력: ");
            Grade grade = new Grade();
            grade.kor = Convert.ToInt32(Console.ReadLine());
            grade.eng = Convert.ToInt32(Console.ReadLine());
            grade.math = Convert.ToInt32(Console.ReadLine());
            grade.Compute(grade.kor, grade.eng, grade.math);
            Console.WriteLine("국어:{0}, 영어:{1}, 수학:{2} -> 총합:{3}, 평균:{4:f1}", grade.kor, grade.eng, grade.math, grade.sum, grade.avg);

            Console.WriteLine("-------------------------------------------------------");

            Console.WriteLine("-------------------------형식-------------------------");

            int nVal1 = 12;
            int nVal2 = new int();
            Console.WriteLine("{0}, {1}", nVal1, nVal2);

            int[] Array1 = { 1, 2, 3 };
            int[] RefArray; // 참조형 배열 변수
            RefArray = Array1;
            RefArray[1] = 20;
            Console.WriteLine("{0}, {1}, {2}", Array1[0], Array1[1], Array1[2]);

        }
    }
}
