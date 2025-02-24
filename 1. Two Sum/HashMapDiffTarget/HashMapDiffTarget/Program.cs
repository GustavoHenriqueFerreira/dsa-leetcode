public class Program
{
    static void Main()
    {
        Console.WriteLine($"{Solution.TwoSum([1, 2, 3, 5], 7)[0]}, {Solution.TwoSum([1, 2, 3, 5], 7)[1]}");
    }

    public class Solution
    {
        public static int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> valuesOfNums = new Dictionary<int, int>();

            for (int i = 0; i < nums.Length; i++)
            {
                int diffTarget = target - nums[i]; //idea to find the complement of sum to the target

                if (valuesOfNums.ContainsKey(diffTarget)) // if the complement exists, return current value and complement
                    return new int[] { valuesOfNums[diffTarget], i };

                if (!valuesOfNums.ContainsKey(nums[i]))
                    valuesOfNums.Add(nums[i], i);
            }

            return [];
        }
    }
}