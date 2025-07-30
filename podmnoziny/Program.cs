namespace Podmnoziny
{
    class Program
    {
        static int amount = 0;
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            int suma = int.Parse(args[1]);
            string[] numbersString = lines[0].Split(' ');

            int[] numbers = new int[numbersString.Length];
            for (int i = 0; i < numbersString.Length; i++)
            {
                numbers[i] = int.Parse(numbersString[i]);
            }

            List<int> podmnozina = [];
            GenerateSubsets(numbers, 0, podmnozina, suma);
            Console.WriteLine(amount);
        }

        static int SumArray(List<int> arr)
        {
            int sum = 0;
            for (int i = 0; i < arr.Count; i++)
            {
                sum += arr[i];
            }
            return sum;
        }

        static void GenerateSubsets(int[] numbers, int index, List<int> currentSubset, int suma)
        {
            if (currentSubset.Count is not 0)
            {
                Console.WriteLine("{" + string.Join(", ", currentSubset) + "}");
            }

            int sum = SumArray(currentSubset);
            if (sum == suma)
            {
                amount++;
            }

            for (int i = index; i < numbers.Length; i++)
            {
                currentSubset.Add(numbers[i]);
                GenerateSubsets(numbers, i + 1, currentSubset, suma);
                currentSubset.RemoveAt(currentSubset.Count - 1);
            }
        }
    }
}