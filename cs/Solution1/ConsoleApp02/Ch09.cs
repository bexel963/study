using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

/*
    - 직렬화 (serialize)
        : 이진 파일의 경우...
          기존에는 구조체나 클래스의 멤버 변수를 각각 명시하여 그에 맞는 데이터를 읽거나 저장 했는데,
          직렬화를 사용하면 해당 구조체나 클래스의 내용을 한꺼번에 읽거나 저장할 수 있다.

        : (StreamWriter, StreamReader) / (BinaryWriter, BinaryReader) -> 기본 데이터형만 저장 및 읽기 (불편함)
        : FileStream, BinaryFormatter                                 -> 구조체, 클래스 저장 및 읽기 (편함)
        : BinaryFormatter 네임스페이스
            using System.Runtime.Serialization.Formatters.Binary;
        
        : 직렬화 대상 설정
            [Serializable]      [Serializable]
            struct A            class A
            {                   {
                ....                ....
            }                   }

        : BinaryFormatter
            public void Serialize(Stream serializationStream, object graph) -> 데이터 쓰기 (구조체 or 클래스 -> 메모리)
            public object Deserialize(Stream serializationStream)           -> 데이터 읽기 (메모리          -> 구조체 or 클래스)

    - 역직렬화 (NonSerialize)     
        : 직렬화 구문에서 직렬화 대상에서 제외
            [Serializable]     
            class TestClass
            {
                int nValue;

                [NonSerialized]
                string strMessage;
            }

    - 켈렉션의 직렬화
        : 컬렉션
            같은 데이터형의 임의의 메모리 또는 연속적인 메모리를 다룰 수 있도록 하는 클래스
            ArrayList

    - 제네릭을 이용한 직렬화
        : 제네릭
            C++ 의 템플릿과 같음
            저장하고자 하는 데이터 타입을 외부에서 고정(설정)해서 사용
            List<T>
*/
namespace ConsoleApp02
{
    [Serializable]
    struct Data
    {
        public int var1;
        public float var2;
        public string str1;
    }
    [Serializable]
    struct Data2
    {
        public int var1;
        public float var2;

        [NonSerialized]
        public string str1;        
    }
    [Serializable]
    struct Data3
    {
        public int data;
        public string str;
        public Data3(int data1, string str1)
        {
            data = data1;
            str = str1;
        }
    }
    class Ch09
    {
        public static void Main(string[] args)
        {
            // 직렬화
            Data[] data = new Data[2];

            data[0].var1 = 1;
            data[0].var2 = 0.5f;
            data[0].str1 = "Test1";
            data[1].var1 = 2;
            data[1].var2 = 2.5f;
            data[1].str1 = "Test2";

            using (FileStream fs1 = new FileStream("serial.dat", FileMode.Create))
            {
                BinaryFormatter bf = new BinaryFormatter();
                bf.Serialize(fs1, data);    // 한 번에 구조체의 내용이 전부 해당 스트림을 통해 저장된다.
            }

            Data[] resultData;

            using (FileStream fs2 = new FileStream("serial.dat", FileMode.Open))
            {
                BinaryFormatter bf2 = new BinaryFormatter();
                resultData = (Data[])bf2.Deserialize(fs2);  // 한 번에 읽기
            }

            for (int i = 0; i < resultData.Length; i++)
                Console.WriteLine("{0} {1} {2}", resultData[i].var1, resultData[i].var2, resultData[i].str1);

            Console.WriteLine();

            // 역직렬화
            Data2[] data2 = new Data2[2];
            data2[0].var1 = 1;
            data2[0].var2 = 0.5f;
            data2[0].str1 = "Test1";
            data2[1].var1 = 2;
            data2[1].var2 = 2.5f;
            data2[1].str1 = "Test2";

            using (FileStream fs3 = new FileStream("serial2.dat", FileMode.Create))
            {
                BinaryFormatter bf3 = new BinaryFormatter();
                bf3.Serialize(fs3, data2);
            }

            Data2[] resultData2;

            using (FileStream fs4 = new FileStream("serial2.dat", FileMode.Open))
            {
                BinaryFormatter bf4 = new BinaryFormatter();
                resultData2 = (Data2[])bf4.Deserialize(fs4);  
            }

            for (int i = 0; i < resultData2.Length; i++)
                Console.WriteLine("{0} {1} {2}", resultData2[i].var1, resultData2[i].var2, resultData2[i].str1);

            Console.WriteLine();

            // 컬렉션 & 제네릭 직렬화
            List<Data3> resultList;
            List<Data3> dataList = new List<Data3>();

            dataList.Add(new Data3(7, "test1"));
            dataList.Add(new Data3(12, "test2"));
            dataList.Add(new Data3(14, "test3"));
            dataList.Add(new Data3(16, "test4"));
            dataList.Add(new Data3(16, "test5"));

            using (FileStream fs5 = new FileStream("generic.dat", FileMode.Create))
            {
                BinaryFormatter bf5 = new BinaryFormatter();
                bf5.Serialize(fs5, dataList);
            }
            using (FileStream fs6 = new FileStream("generic.dat", FileMode.Open))
            {
                BinaryFormatter bf6 = new BinaryFormatter();
                resultList = (List<Data3>)bf6.Deserialize(fs6);
            }

            for (int i = 0; i < resultList.Count; i++)
                Console.WriteLine("{0} {1}", resultList[i].data, resultList[i].str);
        }
    }
}

/*
    - 파일 입출력 정리
    
        <입출력 단위>                                <클래스>             
           바이트                         File, FileStream + BitConverter
           텍스트                         StreamWriter, StreamReader + FileStream
           이진                           BinaryWriter, BinaryReader + FileStream
           구조체와 클래스                [Serializable] + BinaryFormatter, [Serializable] + 컬렉션 + BinaryFormatter
 
*/