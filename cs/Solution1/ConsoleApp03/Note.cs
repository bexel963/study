/*
    - 프로젝트 목표
        : C# 기본 문법 활용
        : 프로그래밍에 대한 이해 (논리적 사고)
        : 필요한 부분을 MSDN에서 검색하여 스스로 찾아 학습하는 능력

    - 프로젝트 개요
        : 전기 밥솥에서 스마트 밥솥으로 업그레이드
        : 쌀(밥통과 연결된 쌀통), 물(정수기), 씻기 등을 자동화
        : 가전 제품 동작(순차적)을 프로그래밍으로 구현
        : 역동적인 프로그래밍 구현 -> 시각 + 청각

    - 밥통
        : 사용자 입력 -> 메뉴
        : 진행상황 디스플레이...

    - 프로젝트를 위한 필수 클래스와 메서드
        : 콘솔창 관련 클래스와 메서드
            : 화면 출력 클래스
                Console
            : 화면 출력 메서드
                Console.Beep()
                Console.Clear()
                Console.SetCursorPosition()
                Console.SetWindowSize()
                Thread.Sleep()  // 1초 = 1000ms
            : 콘솔 색상관련 속성
                Console.BackgroundColor
                Console.ForegroundColor
*/

/*
    - 기획서
        : 생각을 정리하고 문서화
        : 세부적인 기획서 작성 -> 코드가 간결해짐 (필요한 기능만 잘 구현하게 됨)
        : 업그레이드 되는 프로그램
        : 기획서 항목
            개요(이것을 왜 만드는지....), 기능, 개선 사항

    - 프로그램 화면
        : 화면 디자인이 바뀌면 코드도 바뀜
        : 화면 디자인은 사용자 인터페이스이다.
            간결하지만 시각적으로 충분한 화면 구성
*/

using System;
using System.Threading;

class Note
{
    public static void Main(string[] args)
    {
        Console.SetWindowSize(100, 40);
        Random rand = new Random();
        ConsoleColor[] color = { ConsoleColor.Blue, ConsoleColor.Cyan, ConsoleColor.Red, ConsoleColor.Yellow, ConsoleColor.Green, ConsoleColor.Magenta, ConsoleColor.Gray };
        
        while(true)
        {
            Console.Clear();
            for(int i=0; i<30; i++)
            {
                Console.ForegroundColor = color[rand.Next(7)];
                Console.SetCursorPosition(rand.Next(100), rand.Next(40));
                Console.Write("Hello World!!");
            }
            Thread.Sleep(200);  // 0.2s
        }
    }
}
