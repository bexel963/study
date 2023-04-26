using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
    - 단한 연상자
        : C, C++과 달리 ! 는 bool형에만 사용 가능하다.
        : 1과 1아 아닌 수로 bool을 나타내는 C, C++과 달리 true, false 키워드를 제공하고 이것만 쓰도록 한정한다.

    - 산술 연산자
        : string에서 +는 문자열 연결
        : 정수/부동소수 + "문자열" = "문자열"   <-> C,C++ 에서는 이것을 함수로 했다.

    - 관계연산자의 결과
        : C, C++ 에서는 0, 1 이었지만 C# 에서는 true, false 이다.

    - is 연산자 
        : 형식 호환을 조사하는 연산자.
        : 과거에 함수로 하던것을 키워드로 만들었다.
        : 형식
            '변수' is '클래스형 or 데이터형'
        : 결과는 true, false
        : 박싱/언박싱 변환, 참조 변환에서 사용.

    - as 연산자
        : 형변환을 하고, 그 여부에 대한 조사를 함 (불변환은 null 리턴)
        : 캐스트 연산자의 역할
        : 참조, 박싱, 언박싱, null형에 사용
        : 형식
            결과형(nullable형) = 참조형, 언박싱, 박싱 as 변환형

    - 병합 연산자
        : null 조사
        : 형식
            C = A ?? B
                A가 null이 아니면 A를 C에 대입
                A가 null이면 B를 C에 대입
        : if-else 문으로 할 것을 간단히 처리할 수 있다.

    - if ~ else
        : C, C++ 에서는 조건식 결과가 0 or 0 이외의 값 이었지만, C#에서는 true, false 이다.

    - switch, case
        : C, C++ 에서는 정수, 문자상수 두 개만 사용 가능 하지만, C#에서는 문자열도 사용할 수 있다.
        : C, C++ 과 달리 case와 default에는 break 가 반드시 있어야 한다.

    - foreach
        : 처음부터 끝까지 순차적인 값을 반복하여 읽는다. -> 읽기 전용
        : 형식
            foreach( 데이터형 변수 in 배열명(컬렉션명))
            {

            }

    - 예외 처리
        : 예외
            런타임 시에 발생할 수 있는 오류
        : 예외 처리 방법
            1) if ~ else
            2) try ~ catch
        : 형식
            try
            {
                // 예외가 발생할 수 있는 코드
            } catch( 예외처리객체 e)
            {
                // 예외 처리
            }
        : System.Exception 파생 객체만 사용
            OverFlowException, FormatException, DivideByZeroException, FileNotFoundException, IndexOutOfRangeException, ....
        : try문 안에서 초기화한 변수를 try문 밖에서 사용할 수 없다.
            -> 웬만하면 try문 안에서 초기화 하지 않는것이 좋다.
        : finally
            예외 발생과 상관없이 항상 실행되는 구문
            파일 닫기와 같은 반드시 실행되어야 할 내용을 넣어준다.

        : 다중 예외 처리
        
        : throw
            예외 상황을 임의로 발생시키는 역할
            System.Exception 파생된 객체만 사용
            try문과 그 외에서 사용 가능

*/
namespace ConsoleApp01
{
    class A { }
    class B { }

    class Ch04
    {
        public static void Main(String[] args)
        {
            // is 연산자
            int nValue = 10;
            if (nValue is float)
                Console.WriteLine("호환됨.");
            else
                Console.WriteLine("호환 안 됨.");

            if(nValue is object)
                Console.WriteLine("호환됨.");
            else
                Console.WriteLine("호환 안 됨.");

            object obj = nValue;    // 박싱
            if(obj is int)          // 언박싱 되는지??
                Console.WriteLine("호환됨.");
            else
                Console.WriteLine("호환 안 됨.");

            // as 연산자
            string str1 = "123";
            object obj2 = str1;             // 박싱
            string str2 = obj as string;    // 언박싱 되나?? 되면 문자열로 바뀌어 str2로 저장되고 안 되면 null이 저장된다. -> 여기서는 null 반환
            Console.WriteLine(str2);        // str2 == null -> string은 nullable(?)을 사용하지 않아도 null값을 저장할 수 있다.

            A test1 = new A();
            object obj3 = test1;
            B test2 = obj3 as B;    // null 반환
            if (test2 == null)
                Console.WriteLine("형변환 실패");
            else
                Console.WriteLine("형변환 성공");

            // ?? 연산자
            int? x = null;
            int y = x ?? -1;
            Console.WriteLine(y);
            x = 10;
            y = x ?? -1;
            Console.WriteLine(y);

            // foreach
            int[] arr = { 1, 2, 3, 4 };
            foreach (int n in arr)
            {
                Console.WriteLine(n);
                // n = n + 1; -> n은 읽기 전용이라 변경이 안 된다.
            }                

            ArrayList List = new ArrayList();
            List.Add(1);
            List.Add(2);
            List.Add(3);
            List.Add(4);
            foreach (int n in List)
                Console.WriteLine(n);

            Console.WriteLine("-----------------------------------------\n");

            int[] array = { 1, 2, 3 };
            try
            {
                Console.WriteLine("try 문에서 예외 발생 시킵니다.");
                array[3] =99;
                Console.WriteLine("@@@@@");
            }
            catch(IndexOutOfRangeException e)
            {
                Console.WriteLine("배열 인덱스 에러 발생");
                Console.WriteLine(e.ToString());
                array[2] = 99;
            }
            finally
            {
                Console.WriteLine("finally는 예외 발생과 상관없이 항상 실행되는 구문입니다.");
            }

            foreach (int n in array)
                Console.WriteLine(n);

            int m;
            try
            {
                m = 12; // try문 안에서 변수 초기화
                Console.WriteLine("tyy문 출력: {0}", m);
            }
            catch
            {
                Console.WriteLine("예외 발생");
            }
            //Console.WriteLine("try문 밖에서 변수 출력 {0}", m);   // Error) try문 안에서 초기화한 변수를 try문 밖에서 사용할 수 없다.

            // throw
            try
            {
                int result = GetNumber(3);
            }
            catch
            {
                Console.WriteLine("배열 인덱스 관련 예외 발생!!");
            }
            
        }

        static int GetNumber(int index)
        {
            int[] nums = { 300, 600, 900 };
            if(index >= nums.Length)
            {
                throw new IndexOutOfRangeException();   // 예외 발생
            }
            return nums[index];
        }
    }
}

