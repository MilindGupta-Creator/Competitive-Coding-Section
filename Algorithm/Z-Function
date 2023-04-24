/*
	Time Complexity: O(N * M)
	Space Complexity: O(1),

	where N and M is the length of string S and P respectively.
*/

int zAlgorithm(string s, string p, int n, int m)
{

	int count = 0;
	for (int i = 0; i <= n - m; i++)
	{
		int j;

		// For each i, we're checking if the substring matches P or not.
		for (j = 0; j < m; j++)
		{
			if (p[j] != s[i + j])
			{
				break;
			}

		}

		// Found a Substring that matches P.
		if (j == m)
		{
			count++;
		}

	}

	return count;
}
