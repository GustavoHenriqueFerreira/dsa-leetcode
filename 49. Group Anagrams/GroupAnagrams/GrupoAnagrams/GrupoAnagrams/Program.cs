using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GrupoAnagrams
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Solution.GroupAnagrams(new string[] { "ovo", "voo", "bola", "boa", "oba" }));
        }

        public class Solution
        {
            public static IList<IList<string>> GroupAnagrams(string[] strs)
            {
                Dictionary<string, List<string>> res = new Dictionary<string, List<string>>();

                foreach (string word in strs)
                {
                    int[] count = new int[26];
                    foreach (char letter in word)
                    {
                        count[letter - 'a']++;
                    }

                    string key = string.Join(",", count);

                    if (!res.ContainsKey(key))
                        res[key] = new List<string>();

                    res[key].Add(word);
                }

                return res.Values.Cast<IList<string>>().ToList();
            }
        }
    }
}