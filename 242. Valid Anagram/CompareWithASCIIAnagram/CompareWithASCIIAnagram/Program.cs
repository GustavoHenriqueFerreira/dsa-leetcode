using System;
using System.Collections.Generic;

namespace CompareWithASCIIAnagram
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(IsAnagram("hello", "hello"));
        }

        public static bool IsAnagram(string s, string t)
        {
            if (s.Length != t.Length)
                return false;

            // all letter
            int[] count = new int[26];

            for (int i = 0; i < s.Length; i++)
            {
                count[s[i] - 'a']++; // using ascii
                count[t[i] - 'a']--; // compare with amount of letter in each word, all zeros = anagram (same letters with same frequency)
            }

            foreach (int val in count)
            {
                if (val != 0)
                    return false;
            }

            return true;
        }
    }
}
