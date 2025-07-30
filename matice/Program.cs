namespace Matice
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] board1 = {
                { 1, 0, 1, 0, 1 },
                { 1, 1, 0, 0, 0 },
                { 0, 1, 1, 0, 1 },
                { 1, 0, 1, 1, 0 }
            };

            int[,] board2 = {
                { 0, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
                { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 0, 1, 0, 0, 0, 1, 1 },
                { 0, 1, 1, 1, 0, 1, 1, 0, 0, 1 },
                { 1, 1, 1, 0, 0, 1, 1, 1, 1, 0 },
                { 0, 1, 0, 0, 0, 0, 1, 1, 1, 1 },
                { 0, 0, 1, 1, 1, 1, 0, 1, 1, 0 },
                { 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
                { 1, 1, 0, 0, 0, 0, 1, 1, 0, 1 },
                { 0, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
                { 1, 1, 1, 0, 1, 1, 1, 1, 0, 0 },
                { 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
                { 1, 0, 1, 1, 1, 1, 0, 0, 1, 0 },
                { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
                { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
                { 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 },
                { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0 },
                { 1, 0, 1, 1, 0, 0, 1, 0, 1, 1 },
                { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
                { 0, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
                { 0, 0, 0, 0, 1, 0, 1, 0, 1, 1 },
                { 1, 0, 0, 1, 1, 1, 0, 1, 0, 0 },
                { 1, 0, 1, 1, 0, 0, 1, 0, 0, 1 },
                { 1, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
                { 1, 0, 1, 0, 0, 1, 1, 1, 0, 1 },
                { 1, 1, 0, 1, 1, 0, 0, 0, 0, 1 }
            };

            Console.WriteLine(GetMaxCoins(board1));
            Console.WriteLine(GetMaxCoins(board2));
        }

        static int GetMaxCoins(int[,] board)
        {
            int row = board.GetLength(0);
            int column = board.GetLength(1);

            int[,] maxCoinsBoard = new int[row, column];
            maxCoinsBoard[0, 0] = board[0, 0];

            for (int j = 1; j < column; j++)
            {
                maxCoinsBoard[0, j] = maxCoinsBoard[0, j - 1] + board[0, j];
            }

            for (int i = 1; i < row; i++)
            {
                maxCoinsBoard[i, 0] = maxCoinsBoard[i - 1, 0] + board[i, 0];
            }

            for (int i = 1; i < row; i++)
            {
                for (int j = 1; j < column; j++)
                {
                    maxCoinsBoard[i, j] = Math.Max(maxCoinsBoard[i - 1, j], maxCoinsBoard[i, j - 1]) + board[i, j];
                }
            }

            return maxCoinsBoard[row - 1, column - 1];
        }
    }
}
