using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;

/*
    - string 데이터 분리
        public string[] Split(new char[] separator)
            string.Split(new char[] {',', '.', ''});
*/
namespace ConsoleApp02
{
    struct GRADE
    {
        public int kor;
        public int eng;
        public int math;
        public int total;
        public float average;
    }
    class Ch07
    {
        public static void Main(string[] args)
        {
            string str = "국어: 90 영어: 100 수학: 70";
            string[] str_Element = str.Split(new char[] { ' ' });

            int kor = int.Parse(str_Element[1]);
            int eng = int.Parse(str_Element[3]);
            int math = int.Parse(str_Element[5]);
            int total = kor + eng + math;
            float average = total / 3.0f;

            Console.WriteLine("{0} {1} {2} {3} {4}", kor, eng, math, total, Math.Round(average));

            Console.WriteLine("-----------------<파일로 점수 쓰고 읽기>------------------\n");

            string str2;
            Console.Write("성적 처리를 위한 학생 수를 입력해 주세요: ");
            int nCount = int.Parse(Console.ReadLine());
            
            GRADE[] Grade = new GRADE[nCount];
            StreamWriter sw = new StreamWriter("score.txt");
            sw.WriteLine("학생수:{0}", nCount);
            for(int i=0; i<nCount; i++)
            {
                Console.WriteLine("{0}번 학생의 점수를 국어 영어 수학 순서로 입력해 주세요", i+1);
                str2 = Console.ReadLine();
                string[] DataString = str2.Split(new char[] { ' ' });
                Grade[i].kor = int.Parse(DataString[0]);
                Grade[i].eng = int.Parse(DataString[1]);
                Grade[i].math = int.Parse(DataString[2]);
                Grade[i].total = Grade[i].kor + Grade[i].eng + Grade[i].math;
                Grade[i].average = (float)Math.Round(total / 3.0f);
            }

            for (int i = 0; i < nCount; i++)
                sw.WriteLine("{0}, {1}, {2}, {3}, {4:f1}", Grade[i].kor, Grade[i].eng, Grade[i].math, Grade[i].total, Grade[i].average);
            sw.Close();

            string str3;
            Console.Write("파일명을 입력해 주세요: ");
            string fileName = Console.ReadLine();
            StreamReader sr = new StreamReader(fileName + ".txt");
            str3 = sr.ReadLine();
            string[] strData2 = str3.Split(new char[] { ':' });
            int nCnt = int.Parse(strData2[1]);
            Console.WriteLine("------------------------------------");
            for(int i=0; i<nCnt; i++)
            {
                str3 = sr.ReadLine();
                string[] strData3 = str3.Split(new char[] { ',' });
                Console.WriteLine("{0} {1} {2} {3} {4}", strData3[0], strData3[1], strData3[2], strData3[3], strData3[4]);                
            }
            Console.WriteLine("------------------------------------");
            sr.Close();
        }
    }
}
