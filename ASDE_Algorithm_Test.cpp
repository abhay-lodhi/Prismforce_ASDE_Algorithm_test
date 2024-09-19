#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int startingPower = 0; // global power variable for access inside backTrack function to recharge

vector<vector<vector<vector<vector<int>>>>> dp; // global dp

bool backTrack(vector<int> &circlePowers, int currPower, int rechargeCount, int skips, int index, bool isLastSkipped)
{
	// If abhimanyu lost his last circle's battle so return false
	if (currPower < 0)
		return false;

	// if he reaches outside the 11th circle he wins
	if (index == circlePowers.size())
		return true;

	// if returning memoised solution if it is already solved
	if (dp[currPower][rechargeCount][skips][index][isLastSkipped] != -1)
		return dp[currPower][rechargeCount][skips][index][isLastSkipped];

	bool result = false;

	if ((index == 3 || index == 7) && !isLastSkipped)
	{ // case: when abhimanyu has to fight both last circle and current circle, i.e he defeated last enemy but they recovered and attacked from behind

		// his enemy's total power = (current enemy's power) + (last enemy's power)/2
		if (currPower < (circlePowers[index] + circlePowers[index - 1] / 2) && rechargeCount > 0)
		{

			// he recharges himself to fight current enemy
			result |= backTrack(circlePowers, startingPower, rechargeCount - 1, skips, index, isLastSkipped);
		}

		result |= backTrack(circlePowers, currPower - (circlePowers[index] + circlePowers[index - 1] / 2), rechargeCount, skips, index + 1, false);
	}
	else
	{ // all other cases

		// he recharges himself to fight current enemy
		if (currPower < circlePowers[index] && rechargeCount > 0)
			result |= backTrack(circlePowers, startingPower, rechargeCount - 1, skips, index, isLastSkipped);

		result |= backTrack(circlePowers, currPower - circlePowers[index], rechargeCount, skips, index + 1, false);
	}

	// skips the current enemy circle
	if (skips > 0)
		result |= backTrack(circlePowers, currPower, rechargeCount, skips - 1, index + 1, true);

	// memoizing and returning the solution from current state
	return dp[currPower][rechargeCount][skips][index][isLastSkipped] = result;
}

void solve()
{
	int k = 11, p, a, b;
	vector<int> circlePowers(k);

	// taking all circle powers as input
	for (int i = 0; i < k; ++i)
		cin >> circlePowers[i]; 

	// taking power, number of skips and number of recharges possible as input
	cin >> p >> a >> b; 

	// if there are greater than or equal to 11 skips Abhimanyu can skip all cirles and win
	if (a >= 11)
	{
		cout << "YES\n";
		return;
	}

	// there is no need of more than 11 recharges
	b = min(b, 11); 

	// initialize dp with -1
	dp.resize(p + 1, vector<vector<vector<vector<int>>>>(12, vector<vector<vector<int>>>(12, vector<vector<int>>(12, vector<int>(3, -1))))); 

	startingPower = p;

	bool result = backTrack(circlePowers, p, b, a, 0, false); // calling backTrack + memoization function to get result

	if (result)
		cout << "YES\n"; // yes Abhimanyu can cross all 11 circles
	else
		cout << "NO\n"; // no Abhimanyu cannot cross all 11 circles
}

int main()
{
	// ll t;
	// cin >> t;
	// while (t--)
	// {
		solve();
	// }
}