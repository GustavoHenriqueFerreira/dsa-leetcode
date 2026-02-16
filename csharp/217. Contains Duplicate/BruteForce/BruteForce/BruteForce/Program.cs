using System;
using System.Collections.Generic;

namespace BruteForce
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new int[] { 1, 2, 3, 1 };
            Console.WriteLine(new Solution().hasDuplicate(nums));
        }
    }

    public class Solution
    {
        public bool hasDuplicate(int[] nums)
        {
            List<int> addedNumbers = new List<int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (i == 0)
                {
                    addedNumbers.Add(nums[0]);
                    continue;
                }

                int currentNumber = nums[i];
                for (int j = 0; j < addedNumbers.Count; j++)  // complexity: O(n^2)
                {
                    if (currentNumber == addedNumbers[j])
                        return true;
                }
            }

            return false;
        }
    }
}