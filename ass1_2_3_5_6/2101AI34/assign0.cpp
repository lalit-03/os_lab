#include <bits/stdc++.h>
using namespace std;

int strcomp(char* x, char* y, int lenx, int leny){
	for(int i = 0; i<min(lenx,leny); i++){
		if(x[i] > y[i]) return -1;
		else if(x[i] < y[i]) return 1;
	}
	if(lenx > leny) return -1;
	else if(lenx < leny) return 1;
	return 0;
}

int len(char *x){
	int ans = 0;
	while(x[ans] != '\0')ans++;
	return ans;
}

void strsort(char a[][20], char **b, int n){
	for(int i=0; i<n; i++){
		for(int j=1; j<n; j++){
			int lx = len(b[j-1]);
			int ly = len(b[j]);
			if(strcomp(b[j-1], b[j], lx, ly) == -1){
				char* temp = b[j-1];
				b[j-1] = b[j];
				b[j] = temp;
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	char data[50][20]{};
	char* b[n]{};
	for(int i=0; i<n; i++){
		cin >> data[i];
		b[i] = data[i];
	}

	strsort(data, b, n);

	cout <<"Here goes the sorted way:\n";
	for(int i=0;i<n;i++) cout<<b[i]<<'\n';
	return 0;
}
