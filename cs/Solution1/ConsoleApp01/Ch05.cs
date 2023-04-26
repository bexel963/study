using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
    - 배열
        : C# 에서의 배열은 전부 참조형으로 사용된다. 
            -> C, C++은 선언만으로 메모리가 생성되어 사용할 수 있지만, C#은 new를 통해 메모리를 생성해 줘야한다.
        : 같은 데이터형 + 변수명 + 순차적인 메모리 나열
        : 참조형 -> C, C++과 달리 new를 통해 생성 (객체 역할을 함)
        : Array클래스 로부터 파생된 참조형
        : foreach 사용 가능
        : 형식
            데이터형[] 배열명; -> 참조형태임을 강조하기 위해 '[]'를 데이터형 뒤에 쓴다.

            ex) int[] array;
                array = new int[] { 1, 2, 3 };      /// 컴파일러에 의해서 크기 결정됨. 
                array = new int[3] { 1, 2, 3 };

                int[] array = new int[3] { 1 ,2, 3 };
                int[] array = new int[] { 1 ,2, 3 };
                int[] array = { 1, 2, 3 };
        : Array.Length 속성
       
    - 이차원 배열
        : C, C++과 달리 행과 열, 면은 콤마(,)로 구분
        : 형식
            데이터형[,] 배열명;
            데이터형[,,] 배열명;
            
            ex) int[,] array1 = new int[2, 2];
                int[,,] array2 = new int[2, 3, 2];

                int[,] array3 = new int[2,2] { {1,2}, {3,4} };
                int[,,] array4 = new int[2,3,2] { {{1,2}, {3,4}, {5,6}}, {{7,8}, {9,10}, {11,12}} };
                int[,] array5 = new int[,] { {1,2}, {3,4} };
                int[,,] array6 = new int[,,] { {{1,2}, {3,4}}, {{5,6}, {7,8}} };

                int[,] array7 = { {1,2}, {3,4}, {5,6} };
                int[,] array8 = { {{1,2}, {3,4}, {5,6}}, {{7,8}, {9,10}, {11,12}} };
    
    - 가변 배열
        : C, C++ 에서는 이중 포인터를 이용하여 구현해 사용했지만, C#에서는 키워드 하나로 편리하게 사용할 수 있다.
        : 형식
            데이터형[][] 배열명;
            ex) int[][] array_name;
                int[][] array = new int[3][];
                array[0] = new int[2];
                array[1] = new int[3];
                array[2] = new int[4];

                int[][] array = new int[3][];
                array[0] = new int[2] { 1, 2 };
                array[1] = new int[3] { 3, 4, 5 };
                array[2] = new int[4] { 6, 7, 8, 9 };

                int[][] array = new int[3][];
                array[0] = new int[] { 1, 2 };
                array[1] = new int[] { 3, 4, 5 };
                array[2] = new int[] { 6, 7, 8, 9 };

                int[][] array = new int[][]     // 행이 3개인 것을 컴파일러가 인식한다.
                {
                    new int[] { 1, 2, 3 };
                    new int[] { 4, 5, 6 };
                    new int[] { 7, 8, 9 };
                }
                int[][] array = 
                {
                    new int[] { 1, 2, 3 };
                    new int[] { 4, 5, 6 };
                    new int[] { 7, 8, 9 };
                }

        - 일차원 배열을 함수로 전달
            : int[] array = { 1, 2, 3, 4 };     // 메모리를 생성했기 때문에 객체이다.
              
              func(array);

              void func(int[] arr)              // 메모리를 생성 안 했기 때문에 참조형이다.(참조형 배열 변수)
              {
                ...
              }              

        - 이차원 배열을 참조로 전달
            : int[,] array = { {1,2,3}, {4,5,6} };
            
              SetArray(array);
              SetArray(new int[,] { {1,2,3}, {4,5,6} };

              void SetArray(int[,] arr)
              {
                ...
              }

        - 배열을 리턴하는 함수
            : 배열이 참조하는 객체의 주소값을 리턴하는 것이다. 

        - 배열의 메서드들
            : 배열은 Array 클래스로부터 파생된 객체이다.
            : 종류
                1) 배열 초기화 메서드
                    public static void Clear( Array arr, int index, int length );   -> index 번째부터 length개 만큼 0으로 초기화 한다.
*/
namespace ConsoleApp01
{
    class Ch05
    {
        public static void Main(string[] args)
        {
            // 배열의 메서드들
            int[] mArray1 = { 1, 2, 3, 4, 5 };
            Array.Clear(mArray1, 2, 3);     // 암시적으로 int 가 object 로 업캐스팅 된다.
            foreach (int n in mArray1)
                Console.Write(n + " ");
            Console.WriteLine();

            Array.Clear(mArray1, 0, mArray1.Length);
            foreach (int n in mArray1)
                Console.Write(n + " ");
            Console.WriteLine();

            int[] mArray2 = { 1, 2, 3, 4 };
            int[] mCloneArray = (int[])mArray2.Clone(); // Clone()의 리턴 타입은 object 이다.
                                                        // C# 에서는 int[] 도 테이터 형식으로 본다.
            mCloneArray[2] = 30;
            foreach (int n in mArray2)
                Console.Write(n + " ");
            Console.WriteLine();

            foreach (int n in mCloneArray)
                Console.Write(n + " ");
            Console.WriteLine();

            string[] days = { "일", "월", "화", "수", "목", "금", "토" };
            string[] daysClone = (string[])days.Clone();
            foreach (string str in daysClone)
                Console.Write(str + " ");
            Console.WriteLine();



            // 1차원 배열
            int[] nArray = { 1, 2, 3, 4 };
            for (int i = 0; i < 4; i++)
                Console.Write("{0} ", nArray[i]);
            Console.WriteLine();

            foreach (int n in nArray)
                Console.Write("{0} ", n);
            Console.WriteLine();

            string[] Days = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
            foreach (string str in Days)
                Console.Write(str + " ");
            Console.WriteLine();

            // 2차원 배열
            int[,] array1 = new int[2, 2];
            array1[0, 0] = 1;
            array1[0, 1] = 2;
            array1[1, 0] = 3;
            array1[1, 1] = 4;

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    Console.Write(array1[i, j] + " ");
            Console.WriteLine();

            int[,] array2 = { { 1, 2 }, { 3, 4 } };
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    Console.Write(array2[i, j] + " ");
            Console.WriteLine();

            string[,,] strArray = { { { "ab", "cd" }, { "ef", "gh" } }, { { "ij", "kl" }, { "mn", "op" } } };
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        Console.Write(strArray[i, j, k] + " ");
            Console.WriteLine();

            // 가변 배열
            int[][] arr = new int[2][];
            arr[0] = new int[3] { 1, 2, 3 };
            arr[1] = new int[2] { 4, 5 };

            for (int i = 0; i < arr.Length; i++)
                for (int j = 0; j < arr[i].Length; j++)
                    Console.Write(arr[i][j]);
            Console.WriteLine();

            int[][][] arr2 = new int[2][][];        // 행/열/면
            arr2[0] = new int[2][];
            arr2[1] = new int[3][];

            arr2[0][0] = new int[] { 1, 2, 3 };
            arr2[0][1] = new int[] { 4, 5 };
            arr2[1][0] = new int[] { 6, 7, 8 };
            arr2[1][1] = new int[] { 9, 10 };
            arr2[1][2] = new int[] { 11, 12 };

            for (int i = 0; i < arr2.Length; i++)
                for (int j = 0; j < arr2[i].Length; j++)
                    for (int k = 0; k < arr2[i][j].Length; k++)
                        Console.Write(arr2[i][j][k] + " ");
            Console.WriteLine();

            // 일차원 배열을 함수로 전달하기
            string[] EngDays = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
            TransArray(EngDays);
            foreach (string str in EngDays)
                Console.Write(str + " ");
            Console.WriteLine();

            // 배열 리턴하기
            int[] nArr1;
            int[,] nArr2;

            nArr1 = CreateArray1(5);
            nArr2 = CreateArray2(2, 3);

            for (int i = 0; i < nArr1.Length; i++)
                Console.Write(nArr1[i]);
            Console.WriteLine();

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    Console.Write(nArr2[i, j]);
            Console.WriteLine();
        }
        
        static int[] CreateArray1(int length)
        {
            int[] arr = new int[length];
            for (int i = 0; i < arr.Length; i++)
                arr[i] = i + 1;

            return arr;
        }
        static int[,] CreateArray2(int row, int col)
        {
            int[,] arr = new int[row,col];
            int val = 1;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    arr[i, j] = val;
                    val++;
                }                    
            }
                                    
            return arr;
        }
        static void TransArray(string[] arr)
        {
            string[] HangulDays = { "일", "월", "화", "수", "목", "금", "토" };
            for (int i = 0; i < arr.Length; i++)
                arr[i] = HangulDays[i];
        }
    }
}
