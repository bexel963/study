/*
    - 운영체제와 닷넷 프레임워크
	    Microsoft.NET Framework 4.5.1 멀티 타기팅 팩(한...
	

    - .NET Framework의 구성 요소
	
	    : 클래스 라이브러리 - Window Form, ASP.NET
		          - ADO.NET
		          - 기본 클래스 라이브러리(BCL)

	    : 공용언어런타임(CLR)


    - 클래스 라이브러리

	    : C#언어 + 클래스 라이브러리 => C# 프로그래밍
	    : MSDN을 참고(msdn.Microsoft.com) -> 여기있는 예문 많이 보기
	    : 클래스 라이브러리
		    - Window Form: 윈도우 응용 프로그램 제작을 위한 클래스 라이브러리
		    - ASP.NET: 웹 클래스 라이브러리
		    - ADO.NET: 데이터베이스 클래스 라이브러리


    - CLR(Common Language Runtime)

	    : 컴파일된 C# 코드(중간언어)를 재컴파일하여 실행하는 역할
	    : MSIL, IL(Intermediate Languate), 중간언어
		    - Visual Studio 에서 C# 코드를 컴파일한 코드
			    -> *.exe, *.dll (어셈블리, assembly)
			    -> exe 파일은 c, c++과 달리 바로 실행할 수 있는 기계어 코드가 아니라, 닷넷프레임워크가 exe파일의 내용을 읽어서 해당 os 맞게끔 재 컴파일을 한 후 실행한다.
			    -> 그래서 exe파일을 실행파일이라 하지않고, 어셈블리라고 부른다.

    - CTS(Common Type System)

	    : 공통 데이터형과 형식 정의
	    : int -> System.Int32 / float -> System.Single

    - CLS(Common Language Specification)

	    : 공통 언어 사양 정의, 닷넷 언어가 지켜야 할 최소 코드 규칙


    - C# 언어

	    : C++ 언어 기반 + java의 장점 = C# 언어
	    : 사용범위 - XML, Web, NetWork, 데이터베이스, 게임, loT 등....


    - C# 프로그램 실행 과정

	    1. C# 소스 파일 + 리소스 + 참조 (Visual Studio -> CTRL + F5)
	    C# 컴파일러가 컴파일...

	    2. 관리되는 어셈블리(.exe or .dll) MSIL 메타데이터 (사용자가 -> .exe파일 더블클릭)
	    CLR이 로드한 IL 메타데이터 및 참조..
	    CLR이 아래부분 수행...

	    3. .NET Framework
		    : 공용 언어 런타임 보안 / 가비지 수집 / JIT 컴파일러  <- .NET Framework 클래스 라이브러리 사용
	    네이티브 기계어 코드로 변환..

	    4. OS
	    실행...


    - 프로젝트

	    : C#에서 필요로 하는 여러 파일에 대한 정보 및 컴파일 옵션 정보 등 포함

    - 솔루션

	    : 다수의 프로젝트를 하나의 솔루션 안에서 다룰 수 있음
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
    - Console.Write(), Console.WriteLine()
        : public static void Write(bool value);
          public static void Write(string format, Object arg0);
          public static void WriteLine(bool value);
          public static void WriteLine(string format, Object arg0);

        : Console.Write(변수 또는 데이터);
          Console.Write("{0} {1}", 변수1, 변수2);

        : 출력 형식 문자를 사용한 출력
            C - 통화($) 표시
            D - 10진수 정수
            E - 지수형태
            F - 부동소수점
            G - 기본
            N - 콤마
            P - %단위
            X - 16진수

    - C# 키워드(77개)

        : C 키워드(26개)
            break, case, char, const, continue, default, do, double, else, enum, extern, float, for
            goto, if, int, long, return, short, sizeof, static, struct, switch, typeof, void, while

        : C++ 키워드(19개)
            bool, catch, class, false, finally, namespace, new, private, protected, explicit, operator
            public, this, throw, true, try, using, virtual, volatile    

        : C# 키워드(32개)
            abstract, as, base, byte, checked, decimal, delegate, event, fixed, foreach, in, interface
            internal, implicit, is, lock, null, object, out, override, params, readonly, ref, sbyte, sealed
            string, uint, ulong, unchecked, unsafe, ushort, volatile
     
*/
namespace ConsoleApp01
{
    class Ch01
    {
        static void Main(String[] args)
        {
            Console.WriteLine("Hello World");
            Console.WriteLine("{0}, {1}", 3.14f, 12);
            Console.WriteLine("{0} + {1} = {2}", 1, 2, 1 + 2);
            Console.WriteLine("{0:C} {1:P} {0:X}", 123, 123.45, 123);
        }
    }
}
