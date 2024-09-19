#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int initialPowerGlobal=0; // global power variable for access inside backTrack function to recharge

vector<vector<vector<vector<vector<int>>>>> dp; // global dp

bool backTrack(vector<int> &circlePowers, int currPower,int rechargeCount, int skips, int index, bool isLastSkipped) {

	if(currPower<0) return false; // If abhimanyu lost his last circle's battle so return false

	if(index==circlePowers.size()) return true; // if he reaches outside the 11th circle he wins
	
	
	if(dp[currPower][rechargeCount][skips][index][isLastSkipped] !=-1) 
		return dp[currPower][rechargeCount][skips][index][isLastSkipped]; // if returning memoised solution if it is already solved

	bool result=false;
	

	if((index==3 || index==7) && !isLastSkipped) {
		//case: when abhimanyu has to fight both last circle and current circle, i.e he defeated last enemy but they recovered and attacked from behind

		if(currPower<(circlePowers[index] + circlePowers[index-1]/2) && rechargeCount>0) //his enemy's total power = (current enemy's power) + (last enemy's power)/2
			result|= backTrack(circlePowers,initialPowerGlobal, rechargeCount-1, skips, index, isLastSkipped); // he recharges himself to fight current enemy


		result|= backTrack(circlePowers,currPower-(circlePowers[index] + circlePowers[index-1]/2),rechargeCount, skips, index+1,false);
	} else {

		if(currPower<circlePowers[index] && rechargeCount>0)
			result|= backTrack(circlePowers,initialPowerGlobal, rechargeCount-1, skips, index, isLastSkipped); // he recharges himself to fight current enemy


		result|= backTrack(circlePowers,currPower-circlePowers[index],rechargeCount, skips, index+1,false);
	}

	if(skips>0) result|= backTrack(circlePowers,currPower,rechargeCount,skips-1,index+1,true); // skips the current enemy circle

	return dp[currPower][rechargeCount][skips][index][isLastSkipped]= result; // memoizing the current solution
}

void solve() {
	int k=11, p,a,b;
	vector<int> circlePowers(k);
	
	for(int i=0; i<k; ++i) cin>>circlePowers[i]; // taking all circle powers as input

	cin>>p>>a>>b; // taking power, number of skips and number of recharges possible as input
	
	//if there are greater than or equal to 11 skips Abhimanyu can skip all cirles and win
	if(a>=11){
		cout<<"YES\n";
		return;
	} 
	
	b= min(b,11);  // there is no need of more than 11 recharges
	
	dp.resize(p+1, vector<vector<vector<vector<int>>>>(12, vector<vector<vector<int>>>(12, vector<vector<int>>(12, vector<int>(3, -1))))); // initialize with -1
	
	initialPowerGlobal=p;	
    bool result= backTrack(circlePowers,p,b,a,0,false); // calling backTrack + memoization function to get result 
    
    if(result) cout<<"YES\n"; // yes Abhimanyu can cross all 11 circles
    else cout<<"NO\n";  // no Abhimanyu cannot cross all 11 circles
}

int main() {
	ll t;
	cin>>t;
	while(t--) {
		solve();
	}
}