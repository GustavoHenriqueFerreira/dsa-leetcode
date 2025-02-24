using System;
using System.Collections.Generic;

namespace HashSet
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
            HashSet<int> foundNumbers = new HashSet<int>();

            for (int i = 0; i < nums.Length; i++)  //complexity: O(n)
            {
                if (!foundNumbers.Add(nums[i]))
                    return true;
            }

            return false;
        }
    }
}