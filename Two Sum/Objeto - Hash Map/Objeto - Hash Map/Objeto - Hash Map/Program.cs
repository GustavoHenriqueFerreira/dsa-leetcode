using System;
using System.Collections.Generic;

namespace Objeto___Hash_Map
{
    public class Program
    {
        public static int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> map = new Dictionary<int, int>();

            for (int i = 0; i < nums.Length; i++)
            {
                int complemento = target - nums[i];

                if (map.ContainsKey(complemento))
                {
                    return new int[] { map[complemento], i }; // se o complemento existe no map, encontra o indice do numero que tem complemento e o atual 
                };

                map[nums[i]] = i; //adiciona o valor que não é complemento do alvo no map, atrelado ao seu indice
            };

            return new int[0];
        }

        static void Main(string[] args)
        {
            int[] resultado = TwoSum(new int[] { 2, 3, 7, 9, 4 }, 6); // Resultado Esperado = [0, 4]
            Console.WriteLine($"{resultado[0]} {resultado[1]}");
        }
    }
}
