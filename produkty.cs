using System.Globalization;

namespace Produkty
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.GetCultureInfo("cs-CZ");
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            string data = File.ReadAllText(args[0]);
            Product[] products = ParseData(data);

            Console.WriteLine("Produkty:");
            foreach (var item in products)
            {
                if (!item.Quantity.HasValue)
                {
                    Console.WriteLine($"{item.Name}: neznáme množstvo; {item.Price} €");
                }
                else
                {
                    Console.WriteLine($"{item.Name}: {item.Quantity} ks; {item.Price} €");
                }
            }

            double sum = GetTotalProductsPrice(products);
            double averageWeight = GetAverageItemWeight(products);

            Console.WriteLine($"\nCelková cena produktov: {sum} €");
            Console.WriteLine($"Priemerná váha položky: {averageWeight} kg");
        }

        private static Product[] ParseData(string data)
        {
            string productName = "";
            double price = 0;
            int? quantity = 0;
            Weight? weight = null;
            int numberIndex;

            List<Product> products = new List<Product>();
            string[] lines = data.Split(['\n', '\r'], StringSplitOptions.RemoveEmptyEntries);

            foreach (string line in lines)
            {
                string trimmedLine = line.Trim();
                numberIndex = trimmedLine.IndexOfAny("0123456789".ToCharArray());

                if (trimmedLine.StartsWith('-') && !trimmedLine.StartsWith("- price:") && !trimmedLine.StartsWith("- quantity:") && !trimmedLine.StartsWith("- weight:"))
                {
                    if (productName != "")
                    {
                        products.Add(new Product(productName, price, quantity, weight ?? new Weight(WeightUnit.g, 0)));
                    }

                    productName = trimmedLine.Trim('-').Trim(':').Trim();
                    price = 0;
                    quantity = null;
                    weight = null;   
                }
                else if (trimmedLine.StartsWith("- price:"))
                {
                    price = double.Parse(trimmedLine.Substring(numberIndex), CultureInfo.InvariantCulture);
                }
                else if (trimmedLine.StartsWith("- quantity:"))
                {
                    quantity = int.Parse(trimmedLine.Substring(numberIndex), CultureInfo.InvariantCulture);
                }
                else if (trimmedLine.StartsWith("- weight:"))
                {
                    weight = ParseWeight(trimmedLine.Substring(numberIndex));
                }
            }

            if (productName != "")
            {
                products.Add(new Product(productName, price, quantity, weight ?? new Weight(WeightUnit.g, 0)));
            }

            return products.ToArray();
        }


        private static Weight ParseWeight(string weight)
        {
            string[] parts = weight.Split(' ');
            double value = double.Parse(parts[0], CultureInfo.InvariantCulture);
            WeightUnit unit = (WeightUnit)Enum.Parse(typeof(WeightUnit), parts[1]);

            return new Weight(unit, value);
        }

        private static double GetTotalProductsPrice(Product[] products)
        {
            double sum = 0;

            foreach (var item in products)
            {
                sum += item.Price * (item.Quantity.HasValue ? item.Quantity.Value : 0);
            }

            return sum;
        }

        private static double GetAverageItemWeight(Product[] products)
        {
            double sum = 0;
            int count = 0;

            foreach (var item in products)
            {
                sum += Weight.GetNormalizedValue(item.Weight.Unit, item.Weight.Value);
                count++;
            }

            return Math.Round(sum / count, 3);
        }
    }

    class Product
    {
        public string Name { get; private set; }
        public double Price { get; private set; }
        public int? Quantity { get; private set; }
        public Weight Weight { get; private set; }

        public Product(string name, double price, int? quantity, Weight weight)
        {
            Name = name;
            Price = price;
            Quantity = quantity;
            Weight = weight;
        }
    }

    public struct Weight
    {
        public WeightUnit Unit { get; private set; }
        public double Value { get; private set; }

        public Weight(WeightUnit unit, double value)
        {
            Unit = unit;
            Value = value;
        }

        public static double GetNormalizedValue(WeightUnit unit, double value)
        {
            if (unit == WeightUnit.g)
            {
                return value / 1000;
            }
            else if (unit == WeightUnit.dkg)
            {
                return value / 100;
            }
            else
            {
                return value;
            }
        }
    }

    public enum WeightUnit
    {
        kg,
        dkg,
        g
    }
}