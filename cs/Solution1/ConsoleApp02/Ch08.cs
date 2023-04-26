using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
    - 이진 파일 읽기와 쓰기
        : BinaryWriter / BinaryReader
        : 메소드
            ReadBoolean(), ReadByte(), ReadBytes(Int32)
            ReadChar(), ReadChars(Int32)
            ReadDecimal(), ReadDouble(), ReadInt16()
            ReadInt32(), ReadInt64()
            ReadSByte(), ReadSingle(), ReadString()
            ReadUInt16(), ReadUInt32(), ReadUInt64()

            Write()     <- 쓰기는 이거 하나임. (오버로딩)

    - BinaryWriter
        : Write()

    - BinaryReader
        : BinaryReader(Stream) // 디폴트로 UTF-8로 세팅됨.
          BinaryReader(Stream, Encoding)
          BinaryReader(Stream, Encoding, Boolean)
*/
namespace ConsoleApp02
{
    struct Data
    {
        public int var1;
        public float var2;
    }
    class Ch08
    {
        public static void Main(string[] args)
        {
            using (BinaryWriter bw = new BinaryWriter(new FileStream("binarytest.dat", FileMode.Create)))
            {
                bw.Write(12);
                bw.Write(3.14f);
                bw.Write("Hello world!");
            }

            int var1;
            float var2;
            string str1;
                                                        // Open은 파일 클래스의 static 메서드 (이렇게 스트림 생성해도 됨.)
            using (BinaryReader br = new BinaryReader(File.Open("binarytest.dat", FileMode.Open)))
            {
                var1 = br.ReadInt32();
                var2 = br.ReadSingle();
                str1 = br.ReadString();
            }
            Console.WriteLine("{0} {1} {2}", var1, var2, str1);

            Console.WriteLine("-----------------------------");

            Data[] DataArray = new Data[2];

            DataArray[0].var1 = 7;
            DataArray[0].var2 = 3.14f;
            DataArray[1].var1 = 12;
            DataArray[1].var2 = 0.5f;

            BinaryWriter bw2 = new BinaryWriter(File.Open("stbinary.txt", FileMode.Create));
            for(int i=0; i<DataArray.Length; i++)
            {
                bw2.Write(DataArray[i].var1);
                bw2.Write(DataArray[i].var2);
            }
            bw2.Close();

            int var3;
            float var4;

            BinaryReader br2 = new BinaryReader(File.Open("stbinary.txt", FileMode.Open));
            
            while(true)
            {
                try
                {
                    var3 = br2.ReadInt32();
                    var4 = br2.ReadSingle();
                    Console.WriteLine("{0} {1}", var3, var4);
                }
                catch(EndOfStreamException e)   // 파일 끝에 도달한 예외
                {
                    br2.Close();
                    break;
                }
            }
        }
    }
}
