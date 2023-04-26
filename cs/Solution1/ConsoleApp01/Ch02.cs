using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


/*
    - 기본 데이터형
        : C#의 데이터형 object로부터 파생된 객체
        : System.Object == object            
        : 데이터형은 CTS에서 정의된 객체
        : CLR에서 돌아갈 때는 기본형은 CTS에서 정의된 System.Object 형태로 재컴파일 되어서 돌아간다.
 
    - 정수형
        : bool      System.Boolean      1byte
          char      System.Char         2byte (유니코드)(c, c++은 1byte)
          byte      System.Byte         1byte
          sbyte     System.SByte        1byte
          short     System.Int16        2byte
          ushort    System.UInt16       2byte
          int       System.Int32        4byte
          uint      System.UInt32       4byte
          long      System.Int64        8byte
          ulong     System.UInt64       8byte
 
    - 실수형
        : float     System.Single       4byte
          double    System.Double       8byte
          decimal   System.Decimal      16byte

    - 문자열형
        : string    System.String

    - char형
        : C, C++ 에서는 아스키코드를 사용하기 때문에 1byte 이지만, C#은 유니코드를 사용하기 때문에 2byte 이다.
        : char형의 암시적 값 변환
            : ushort, int, uint, long, ulong, float, double, decimal

    - byte      (0 ~ 255)
    - sbyte     (-128 ~ 127)
    - short     (-32768 ~ 32767)
    - ushort    (0 ~ 65535)
    - int       (-2,147,483,648 ~ 2,147,483,647)
    - uint      (0 ~ 4,294,967,295)

    - float형
        : 소수점 뒤에 f, F 접미사 명시 없으면 double형임.
    
    - short형의 유효 범위 값을 출력
        : public const short MinValue
          public const short MaxValue

    - string형
        : C/C++ 은 문자열 끝에 0, '\0' 을 넣어줌으로써 문자열 표현
        : C#은 문자열에 '+', ==, [index] 사용 가능
        : 문자열에 '\'를 포함하는 경우
            @"C:\temp\test.txt"   ==  "C:\\temp\\test.txt" 

    - 암시적 데이터형 var
        : 대입되는 데이터에 따라 데이터형 결정
        : var을 사용할 수 없는 예
            1) null 값 초기화, 매개변수로는 사용 못함
            2) var는 지역변수로만 사용가능, 클래스 멤버로는 사용 못함
            3) 연속적으로 초기화 하는 경우
                int m = 10, n = 20; (o)
                var m = 10, n = 20; (x)
              
    - nullable 형
        : null을 허용하지 않는 데이터형(기본형)에 null값을 허용
        : 형식
            데이터형? 변수명;
        : ex)
            int? var1;
            bool? var2 = null;  // bool형은 true, false 밖에 못 쓰는데 이 경우에는 null까지 사용할 수 있다.
        : 기본형에 nullable형을 적용하면 기존에 제공하는 메서드 외에 몇가지 변수(속성)를 더 제공한다.
            .HasValue - true, false
            .Value    - 읽기 전용

    - 데이터 변환
        : ToString()                    // 기본데이터형 -> 문자열
        : 기본 데이터형.Parse("문자열")  // 문자열 -> 기본 데이터형
        : Convert.ToInt32()
          Convert.ToSingle()
          Convert.ToXXXXX()

    - 박싱
        : 데이터 형을 최상위 object 형으로 변환하여 heap에 저장
            int m = 123;
            object obj = m;
    - 언박싱
        : heap에 저장된 형식을 다시 원래의 형식으로 변환
            int n = (int)obj;

    - 표준 입력
        : Console.ReadKey()
            : 사용자가 눌린 키 한 문자 정보를 리턴하는 메서드
            : 원형
                public static ConsoleKeyInfo ReadKey()
                public static ConsoleKeyInfo ReadKey(bool intercept)    // true-화면 출력 안 함, false(default)-화면 출력
            : ConsoleKeyInfo
                구조체
                키의 문자와 Shift, Alt, Ctrl 보조키 상태 포함
            : ConsoleKeyInfo 속성
                1) ConsoleKeyInfo.Key
                2) ConsoleKey 열거형 값 - public enum ConsoleKey
                        ConsoleKey.A, ConsoleKey.Escape 등... (MSDN 에서 찾아 볼 것)
                3) ConsoleKeyInfo.KeyChar
                        눌린 키의 유니코드를 얻는 속성으로 대소문자 등을 모두 구분할 수 있다.
        : Console.ReadLine()
            : 엔터키가 눌려질 때까지 입력 받은 문자열을 리턴하는 메서드
            : 활용
                입력 받은 문자열을 숫자로 사용할 때는 Convert.ToInt32() 등의 메서드를 사용한다.
            
*/
namespace ConsoleApp01
{
    class Ch02
    {
        static bool b1;

        static void Main(string[] args)
        {
            bool b2 = true;

            Console.WriteLine(b1);
            Console.WriteLine(b2);
            Console.WriteLine("{0} {1}", b1, b2);
            Console.WriteLine("-------------------------------");

            int i = '7';
            Console.WriteLine("{0} {1} {2}", i, i + 1, (char)(i+1));
            Console.WriteLine("-------------------------------");

            byte by1 = 30;
            byte by2 = 40;
            int num = by1 + by2;
            Console.WriteLine(num);
            Console.WriteLine("-------------------------------");

            Console.WriteLine(System.Int16.MinValue);
            Console.WriteLine(System.Int16.MaxValue);
            Console.WriteLine(short.MinValue);
            Console.WriteLine(short.MaxValue);
            Console.WriteLine(float.MaxValue);
            Console.WriteLine("-------------------------------");

            string str1 = "abc";
            string str2 = "def";
            string result = str1 + str2;
            Console.WriteLine("{0}({1})에서 다섯번째 문자는 '{2}' 이다.", result, result.Length, result[4]);

            if(result == "abdef")
            {
                Console.WriteLine("같음");
            }
            else
            {
                Console.WriteLine("다름");
            }

            string str3 = "C:\\temp\\test.txt";
            string str4 = @"C:\temp\test.txt";
            Console.WriteLine("{0}, {1}", str3, str4);
            Console.WriteLine("-------------------------------");

            var v1 = 10;
            var v2 = 3.14f;
            var v3 = v1 + v2;       //소수점 첫째자리까지 출력
            Console.WriteLine("{0} + {1:f1} = {2}", v1, v2, v3);
            Console.WriteLine("-------------------------------");

            int? nullNum = null;
            if (nullNum.HasValue)
                Console.WriteLine("올바른 값");
            else
                Console.WriteLine("null 값");
            Console.WriteLine("null : {0}", nullNum);   // null값은 정의되지 않은 값이기 때문에 콘솔에 출력할 수 없다.
            Console.WriteLine("-------------------------------");

            Console.WriteLine("---------------데이터 변환----------------");
            int value1 = 127;
            string cstr = value1.ToString();
            Console.WriteLine(cstr);

            int value2 = Convert.ToInt32(cstr); // Convert클래스 안에 ToInt32()가 static으로 정의되어있어서 객체 생성없이 바로 사용 가능.

            string cstr2 = "3.14";
            float value3 = float.Parse(cstr2);  // CLR이 아래 코드로 컴파일 한다.
                  value3 = System.Single.Parse(cstr2);
            Console.WriteLine(value3);
            Console.WriteLine("-------------------------------");

            Console.WriteLine("---------------박싱과 언박싱----------------");
            int i3 = 123;
            object obj = i3;                        // 박싱
            Console.WriteLine("{0}", (int)obj);     // 언박싱

            int i4 = 456;
            object o = i4;
            i4 = 789;
            Console.WriteLine("{0} {1}", i4, (int)o);   // 기본형을 박싱하면 별도의 heap 메모리에 메모리를 할당하기 때문에,
                                                        // o는 기존 기본형의 메모리(i4)와 공유하지 않는다.
            Console.WriteLine("-------------------------------");

            Console.WriteLine("---------------표준 입력(ReadKey)----------------");
            ConsoleKeyInfo keyInfo;
            do
            {
                // keyInfo = Console.ReadKey(true);     // true -> 화면 출력 안 함
                keyInfo = Console.ReadKey();            // 인자 안 주면 false임 -> 화면 출력 함
                if (keyInfo.Key == ConsoleKey.A)        // 대소문자를 구분하지 않고 눌린 키에 대해서만 입력받음.
                    Console.WriteLine("[대소문자 구분X]a가 눌렸다!!");
                if(keyInfo.KeyChar == 'a')
                    Console.WriteLine("[대소문자 구분O]a가 눌렸다!!");
            } while (keyInfo.Key != ConsoleKey.Escape);
            Console.WriteLine("표준 입력 종료!");
            Console.WriteLine("-------------------------------");

            Console.WriteLine("---------------표준 입력(ReadLine)----------------");
            int kor, eng, math, total;
            float avg;

            Console.Write("국어 점수 입력: ");
            kor = Convert.ToInt32(Console.ReadLine());
            Console.Write("영어 점수 입력: ");
            eng = Convert.ToInt32(Console.ReadLine());
            Console.Write("수학 점수 입력: ");
            math = Convert.ToInt32(Console.ReadLine());

            total = kor + eng + math;
            avg = total / 3.0f;
            Console.WriteLine("{0} {1} {2} {3} {4:f1}", kor, eng, math, total, avg);
        }
    }
}
