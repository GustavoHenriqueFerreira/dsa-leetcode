namespace TopKFrequentElements
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"{Solution.TopKFrequent(new int[] { 1, 2, 3, 1 }, 1)[0]},{Solution.TopKFrequent(new int[] { 1, 2, 3, 1 }, 1)[1]}");
        }
    }
    public class Solution
    {
        public static int[] TopKFrequent(int[] nums, int k)
        {
            Dictionary<int, int> frequencyOfNums = new Dictionary<int, int>();

            for (int i = 0; i < nums.Length; i++)
            {
                if (frequencyOfNums.ContainsKey(nums[i]))
                    frequencyOfNums[nums[i]]++;
                else
                    frequencyOfNums[nums[i]] = 1;
            }

            var heap = new PriorityQueue<int, int>();
            foreach (KeyValuePair<int, int> entry in frequencyOfNums)
            {
                heap.Enqueue(entry.Key, entry.Value);
                if (heap.Count > k)
                {
                    heap.Dequeue();
                }
            }

            int[] res = new int[k];
            for (int i = 0; i < k; i++)
            {
                res[i] = heap.Dequeue();
            }
            return res;
        }
    }
}
