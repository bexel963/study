using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


/*
    - 스트림
        : 파일, 네트워크 등에서 데이터를 바이트 단위로 읽고 쓰는 클래스
        : Stream 클래스는 상위 기본 클래스임.

    - 스트림을 상속 받는 클래스들
        : FileStream, MemoryStream, NetworkStream, SqlFileStream 등...

    - using System.IO 선언

    - 파일 스트림 (FileStream)
        : 파일 입출력을 다루는 기본 클래스
            System.Object - System.MarshalByRefObject -> System.IO.Stream -> System.IO.FileStream
        : byte[] 배열로 데이터를 읽거나 저장함
            형변환이 요구됨

    - 기본적으로 파일 스트림을 이용해서 데이터를 읽고 쓰고 하는 작업을 하지만, 이 과정을 좀 더 쉽게 수행하기 위해 다음과 같은 클래스를 제공한다.
        : StreamWriter / StreamReader   -> 메모리에 0, 1로 저장된 데이터를 텍스트(1byte) 단위로 쓰거나 읽는다.
        : BinaryWriter / BinaryReader   -> 메모리에 0, 1로 저장된 데이터를 특정 데이터형을 이용해서 그 형식의 단위(ex.4byte, 8byte, ...)로 데이터를 읽고 쓴다.
        : 위 클래스 들은 파일 스트림 클래스와 같이 사용을 한다.

    - 파일 정보 설정 (FileStream 클래스의 객체 생성 시) 
        : public FileStream(string path, FileMode mode, FileAccess access)

    - FileMode 열거형
        : Append, Create, CreateNew, Open, OpenOrCreate, Truncate

    - FileAccess 열거형
        : Read, ReadWrite, Write

    - 텍스트 파일처리
        : StreamWrite, StreamReader
        : 텍스트 파일의 특징
            1) 기본 단위가 1 바이트
            2) 아스키코드 기반
            => 저장할 때는 텍스트 파일 형태(아스키코드)의 1바이트로 저장 하지만, C# 에서 이것을 읽을 때는 아스키코드를 유니코드로 인코딩하여 읽어햐 한다.

    - StreamWriter
        : 파일 쓰기
        : 상속 계층
            System.Object -> System.MarshalByRefObject -> System.IO.TextWrite -> System.IO.StreamWriter
                public class StreamWriter : TextWriter
        : 메서드
            Write(), WriteLine();
        : 객체 생성과 해제
            FileStream fs = new FileStream("test.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);
            sw.Close();        
        : using문
            using(StreamWriter sw = new StreamWriter(new FileStream("test.txt", FileMode.Create)))
            {
                // 파일 입출력 처리
            }   // using문이 끝나면 sw.Close()가 자동으로 호출된다.
    
    - StreamReader
        : 파일 읽기
        : 상속 계층
            System.Object -> System.MarshalByRefObject -> System.IO.TextReader -> System.IO.StreamReader
                public class StreamReader : TextReader
        : 메서드
            Read(), ReadLine()
*/
namespace ConsoleApp02
{
    class Ch06
    {
        public static void Main(string[] args)
        {
            int value = 12;
            float value2 = 3.14f;
            string str1 = "Hello World!";

            // 파일 쓰기 기본
            FileStream fs = new FileStream("test.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);
            sw.WriteLine(value);
            sw.WriteLine(value2);
            sw.WriteLine(str1);
            sw.Close();

            // using문 사용
            using(StreamWriter usw = new StreamWriter(new FileStream("test2.txt", FileMode.Create)))
            {
                usw.WriteLine(value);
                usw.WriteLine(value2);
                usw.WriteLine(str1);
            }

            // StreamWriter 만 사용
            // FileStream을 사용하면 FileStream 하나를 생성해 두고, 이것을 읽기용도 또는 쓰기용도로 나눠서 사용할 수 있지만
            // StreamWriter 만 사용하면 단순히 쓰기용도로만 사용하고 끝내버린다는 차이점이 있다.
            StreamWriter onlysw = new StreamWriter("test3.txt");
            onlysw.WriteLine(value);
            onlysw.WriteLine(value2);
            onlysw.WriteLine(str1);
            onlysw.Close();

            // 파일 읽기
            FileStream fs2 = new FileStream("test.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs2);
            int first = int.Parse(sr.ReadLine());
            float second = float.Parse(sr.ReadLine());
            string third = sr.ReadLine();
            sr.Close();
            Console.WriteLine("{0}, {1}, {2}", first, second, third);

            using(StreamReader sr2 = new StreamReader(new FileStream("test.txt", FileMode.Open)))
            {
                int ufirst = int.Parse(sr2.ReadLine());
                float usecond = float.Parse(sr2.ReadLine());
                string uthird = sr2.ReadLine();
                sr2.Close();
                Console.WriteLine("{0}, {1}, {2}", ufirst, usecond, uthird);
            }

            StreamReader sr3 = new StreamReader("test.txt");
            int onlyfirst = int.Parse(sr3.ReadLine());
            float onlysecond = float.Parse(sr3.ReadLine());
            string onlythird = sr3.ReadLine();    
            Console.WriteLine("{0}, {1}, {2}", onlyfirst, onlysecond, onlythird);
        }
    }
}
