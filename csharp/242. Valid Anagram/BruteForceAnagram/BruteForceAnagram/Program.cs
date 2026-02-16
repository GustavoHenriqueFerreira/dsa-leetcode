using System;
using System.Collections.Generic;
using System.Linq;

namespace BruteForceAnagram
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(IsAnagram("listen", "silent")); // True
            Console.WriteLine(IsAnagram("letter", "world"));   // False
        }

        public static bool IsAnagram(string s, string t)
        {
            Dictionary<char, int> firstWord = new Dictionary<char, int>();
            Dictionary<char, int> secondWord = new Dictionary<char, int>();
            int amountCharacterBiggestWord = s.Length;

            if (s.Length != t.Length) 
                return false;

            if (t.Length > s.Length)
                amountCharacterBiggestWord = t.Length;

            for (int i = 0; i < amountCharacterBiggestWord; i++)
            {
                if (s.Length >= amountCharacterBiggestWord)
                {
                    char characterFirstWord = s[i];

                    firstWord[characterFirstWord] = firstWord.GetValueOrDefault(characterFirstWord, 0) + 1;
                }

                if (t.Length >= amountCharacterBiggestWord)
                {
                    char characterSecondWord = t[i];

                    secondWord[characterSecondWord] = secondWord.GetValueOrDefault(characterSecondWord, 0) + 1;
                }
            }

            // equal amount of character
            if (firstWord.Count == secondWord.Count)
            {
                // same frequency of each letter in word
                bool equalsOrNot = firstWord.All(letter => secondWord.TryGetValue(letter.Key, out int value) && value == letter.Value);
                return equalsOrNot;
            }

            return false;
        }
    }
}
