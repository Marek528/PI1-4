namespace Sample
{
    class Test
    {
        public static void Main(string[] args)
        {
            Console.Write("Zadaj mod vykreslenia: ");
            char mod = char.Parse(Console.ReadLine());

            Console.Write("Zadaj vstupne cisla: ");
            string[] inputValues = Console.ReadLine().Split(' ');
            int size = Int32.Parse(inputValues[0]);
            int range = Int32.Parse(inputValues[1]);

            int[] num = new int[size];
            Console.Write("Zadaj cisla: ");
            string[] numbers = Console.ReadLine().Split(' ');
            if (numbers.Length != size)
            {
                Console.WriteLine("Zadali ste nespravny pocet cisel");
                return;
            }

            // pretypovanie zadanych cisel na int
            for (int i = 0; i < numbers.Length; i++)
            {
                num[i] = Int32.Parse(numbers[i]);
            }

            //vytvorenie pola s cislami [range, range+8]
            int[] rangeOfNum = new int[9];;
            if (mod == 'h')
            {
                for (int i = 0; i < rangeOfNum.Length; i++)
                {
                    rangeOfNum[i] = range + i;
                }
            }
            else
            {
                for (int i = 0; i < rangeOfNum.Length; i++)
                {
                    rangeOfNum[i] = i + 1;
                }
            }

            // vypocitanie poctu cisel v rangeOfNum
            int count = 0;
            int[] rangeOfNumCount = new int[9];
            for (int i = 0; i < rangeOfNum.Length; i++)
            {
                count = 0;

                for (int j = 0; j < num.Length; j++)
                {
                    if (rangeOfNum[i] == num[j])
                    {
                        count++;
                        continue;
                    }
                }

                rangeOfNumCount[i] = count;
            }

            // vypocitanie neplatnych cisel
            int invalid = 0;
            for (int i = 0; i < num.Length; i++)
            {
                for (int j = 0; j < rangeOfNum.Length; j++)
                {
                    if (mod == 'h' && (num[i] < range || num[i] > range + 8))
                    {
                        invalid++;
                        break;
                    }
                    else if (mod == 'v' && (num[i] < 1 || num[i] > 9))
                    {
                        invalid++;
                        break;
                    }
                }
            }

            if (mod == 'h')
            {
                for (int i = 0; i < rangeOfNum.Length; i++)
                {
                    if (rangeOfNum[i].ToString().Length < rangeOfNum[8].ToString().Length)
                    {
                        Console.WriteLine($" {rangeOfNum[i]} {new string('#', rangeOfNumCount[i])}");
                    }
                    else
                    {
                        Console.WriteLine($"{rangeOfNum[i]} {new string('#', rangeOfNumCount[i])}");
                    }
                }
                Console.WriteLine($"invalid: {new string('#', invalid)}");
            }
            else if (mod == 'v')
            {
                // max hodnota v rangeOfNumCount / invalid
                count = 0;
                for (int i = 0; i < rangeOfNumCount.Length; i++)
                {
                    if (rangeOfNumCount[i] > count)
                    {
                        count = rangeOfNumCount[i];
                    }
                }
                if (invalid > count)
                {
                    count = invalid;
                }

                for (int i = count; i >= 0; i--)
                {
                    if (i > 0)
                    {
                        if (invalid >= i)
                        {
                            Console.Write("# ");
                        }
                        else
                        {
                            Console.Write("  ");
                        }

                        for (int j = 0; j < rangeOfNum.Length; j++)
                        {
                            if (rangeOfNumCount[j] >= i)
                            {
                                Console.Write("# ");
                            }
                            else
                            {
                                Console.Write("  ");
                            }
                        }
                        Console.WriteLine();
                    }
                    else
                    {
                        Console.Write("i ");
                        for (int j = 0; j < rangeOfNum.Length; j++)
                        {
                            Console.Write($"{rangeOfNum[j]} ");
                        }
                    }
                }
            }
            else
            {
                Console.WriteLine("Neplatny mod vykreslenia");
                return;
            }
        }
    }
}