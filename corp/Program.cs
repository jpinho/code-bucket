using System;
using System.Collections.Generic;

namespace CorpInterview
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			var nums = new int[]{ 1, 2, 3, 4, 5, 6 };
			var letters = new int[]{ 'a', 'b', 'c', 'd', 'e', 'f' };
			var result = ClapIt (nums, letters);

			Console.WriteLine ("in: [1, 2, 3, 4, 5, 6] [a, b, c, d, e, f]");
			Console.Write ("out: "); 
			Print (result);
		}

		public static int[][] ClapIt(int[] nums, int[] letters){
			var lstOdd = new List<int> (nums.Length);
			var lstEvenRvs = new List<int> (nums.Length);

			for (int odd = 0, even = nums.Length-1; odd < nums.Length || even > 0; odd += 2, even -= 2) {
				lstOdd.Add (nums[odd]);
				lstOdd.Add (letters [odd]);
				lstEvenRvs.Add (nums[even]);
				lstEvenRvs.Add (letters [even]);
			}

			return new int[2][]{ lstOdd.ToArray (), lstEvenRvs.ToArray () };
		}

		public static void Print(int[][] result){
			for (int i = 0; i < result.Length; i++) {
				Console.Write ("[ ");
				for (int j = 0; j < result [i].Length; j++) {
					if(Char.IsLetter((char)result[i][j]))
						Console.Write ((char)result[i][j] + " ");
					else
						Console.Write (result[i][j] + " ");
				}
				Console.Write ("] ");
			}
		}
	}
}