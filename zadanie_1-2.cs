namespace Sample
{
    class Test
    {
        public static void Main(string[] args)
        {
            // 1. zadanie
            // int[] bankovky = {500, 200, 100, 50, 20, 10, 5, 2, 1};
            // int[] kusy = new int[9];
            // int suma = 0;
            // Console.WriteLine("Zadajte sumu na rozmenenie: ");
            // suma = Int32.Parse(Console.ReadLine());

            // for (int i = 0; i < bankovky.Length; i++)
            // {
            //     int zvysok = suma / bankovky[i];
            //     suma -= bankovky[i] * zvysok;
            //     kusy[i] = zvysok;
            // }

            // for (int i = 0; i < kusy.Length; i++)
            // {
            //     if (kusy[i] != 0)
            //     {
            //         Console.WriteLine($"{bankovky[i]} €: {kusy[i]}");
            //     }
            // }

            // 2. zadanie
            string[] vstup = Console.ReadLine().Split(' ');
            int vyska = Int32.Parse(vstup[2]);
            int sirka = Int32.Parse(vstup[1]);
            int mod = Int32.Parse(vstup[0]);
            string repeated;
            int vnutro = sirka - 2;
            string[] vypln = new string[vnutro];
            string result;

            if (mod == 0)
            {
                for (int i = 0; i < vyska; i++)
                {
                    repeated = new string('X', sirka);
                    Console.WriteLine(repeated);
                }
            }
            else if (mod == 1)
            {
                for (int i = 0; i < vyska; i++)
                {
                    if (i == 0 || i == vyska - 1)
                    {
                        repeated = new string('X', sirka);
                        Console.WriteLine(repeated);
                    }
                    else
                    {
                        repeated = new string(' ', vnutro);
                        Console.WriteLine($"X{repeated}X");
                    }
                }
            }
            else if (mod == 2)
            {
                int num = 0;
                for (int i = 0; i < vyska; i++)
                {
                    if (i == 0 || i == vyska - 1)
                    {
                        repeated = new string('X', sirka);
                        Console.WriteLine(repeated);
                    }
                    else
                    {
                        for (int j = 0; j < vnutro; j++)
                        {
                            if (num == 10)
                            {
                                num = 0;
                            }
                            vypln[j] = num.ToString();
                            num++;
                        }

                        result = string.Join("", vypln);
                        Console.WriteLine($"X{result}X");
                    }
                }
            }
            else if (mod == 3)
            {
                for (int i = 0; i < sirka; i++)
                {
                    repeated = new string(' ', i);
                    Console.Write(repeated);
                    Console.WriteLine("X");
                }
            }
            else if (mod == 6)
            {
                for (int i = 0; i < vyska; i++)
                {
                    if (i == 0)
                    {
                        repeated = new string('X', sirka);
                        Console.WriteLine(repeated);
                    }
                    else
                    {
                        repeated = new string(' ', (sirka - 1) / 2);
                        Console.WriteLine($"{repeated}X");
                    }
                }
            }
            else if (mod == 9)
            {
                int num = 0;
                for (int i = 0; i < vyska; i++)
                {
                    if (i == 0 || i == vyska - 1)
                    {
                        repeated = new string('X', sirka);
                        Console.WriteLine(repeated);
                    }
                    else
                    {
                        for (int j = 0; j < vnutro; j++)
                        {
                            vypln[j] = num.ToString();
                            num += vyska - 2;
                            if (num >= 10)
                            {
                                num %= 10;
                            }
                        }

                        result = string.Join("", vypln);
                        Console.WriteLine($"X{result}X");
                    }
                    num = i;
                }
            }
            else
            {
                Console.WriteLine("Wrong mod!");
            }
        }
    }
}