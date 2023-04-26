using System;

namespace ConsoleApp03
{
    class Program
    {
        public static int MainMenuIndex = 0;

        static void RiceCookerBox(int x, int y)
        {
            int height = 20;
            Console.SetCursorPosition(x, y);
            Console.Write("┌──────────────────────────────────────────┐");
            for (int i = 1; i < height; i++)
            {
                Console.SetCursorPosition(x, y + i);
                Console.Write("|                                     |");
            }
            Console.SetCursorPosition(x, y + height);
            Console.Write("└──────────────────────────────────────────┘");
        }

        static void Menu(int x, int y, string[] MenuItem)
        {
            ConsoleKeyInfo InputKey;            

            while(true)
            {
                for (int i = 0; i < MenuItem.Length; i++)
                {                    
                    if (MainMenuIndex == i)
                    {
                        Console.BackgroundColor = ConsoleColor.Yellow;
                        Console.ForegroundColor = ConsoleColor.Black;
                        Console.SetCursorPosition(x, y + i);
                        Console.Write(MenuItem[i]);
                        Console.BackgroundColor = ConsoleColor.Black;
                        Console.ForegroundColor = ConsoleColor.White;
                    }
                    else
                    {
                        Console.SetCursorPosition(x, y + i);
                        Console.Write(MenuItem[i]);
                    }                                          
                }
                InputKey = Console.ReadKey(true);
                if (InputKey.Key == ConsoleKey.Enter)
                    break;
                else if(InputKey.Key == ConsoleKey.UpArrow)
                {
                    MainMenuIndex--;
                    if (MainMenuIndex < 0)
                        MainMenuIndex = 0;
                }
                else if(InputKey.Key == ConsoleKey.DownArrow)
                {
                    MainMenuIndex++;
                    if (MainMenuIndex == MenuItem.Length)
                        MainMenuIndex = MenuItem.Length - 1;
                }
            }
        }
        static void Main(string[] args)
        {
            // 메뉴
            Console.SetWindowSize(99, 36);
            RiceCookerInfo RCInfo = new RiceCookerInfo(10000, 5000);
            SoundPlayer Sound = new SoundPlayer();

            string[] MenuItem = { "   전원   ", "   뚜껑   ", "   취사   ", "   보온   ", "   취소   ", "  인원수  ", "    쌀    ", "    물    " };

            while(true)
            {
                OutFrame();
                RiceBox(16, 11);
                Cover(RCInfo.CoverOpenClose);
                RiceInfo(RCInfo);
                PowerLine(RCInfo.Power);
                RiceHeight(50, 2, RCInfo.Rice);
                WaterHeight(74, 2, RCInfo.Water);

                Menu(65, 25, MenuItem);
                if (MainMenuIndex == 9)
                    break;

            }
        }
    }
}
