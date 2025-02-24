using System;

namespace Força_Bruta___Brute_Force
{
    class Program
    {
        public static int[] TwoSum(int[] nums, int target)
        {
            int[] numeros = { 1, 2 };
            for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (target == nums[i] + nums[j])
                    {
                        numeros[0] = i;
                        numeros[1] = j;
                        break;
                    };
                };
            };

            return numeros;
        }


        static void Main(string[] args)
        {
            int[] resultado = TwoSum(new int[] { 2, 3, 4, 5 }, 6);
            Console.WriteLine($"{resultado[0]}, {resultado[1]}");
        }
    }
}
