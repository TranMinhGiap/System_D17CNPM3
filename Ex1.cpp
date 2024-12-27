#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> And;
vector<pair<int,int>> Or;
vector<pair<int,int>> XoR;

void input(int Arr[], int n){
	for(int i = 0 ; i < n ; i++){
		cout << endl << "Input element " << i + 1 << " : ";
		cin >> Arr[i];
	}
}

void inputAnd(int n){
	int tmp1, tmp2;
	for(int i = 0 ; i < n ; i++){
		cout << endl << "Enter the second pair of numbers " << i + 1 << " : ";
		cout << endl << "Element 1 : ";
		cin >> tmp1; 
		cout << endl << "Element 2 : ";
		cin >> tmp2; 
		And.push_back({tmp1, tmp2});
	}
}
void inputOr(int n){
	int tmp1, tmp2;
	for(int i = 0 ; i < n ; i++){
		cout << endl << "Enter the second pair of numbers " << i + 1 << " : ";
		cout << endl << "Element 1 : ";
		cin >> tmp1; 
		cout << endl << "Element 2 : ";
		cin >> tmp2; 
		Or.push_back({tmp1, tmp2});
	}
}
void inputXoR(int n){
	int tmp1, tmp2;
	for(int i = 0 ; i < n ; i++){
		cout << endl << "Enter the second pair of numbers " << i + 1 << " : ";
		cout << endl << "Element 1 : ";
		cin >> tmp1; 
		cout << endl << "Element 2 : ";
		cin >> tmp2; 
		XoR.push_back({tmp1, tmp2});
	}
}

string binary(int n){
	vector<int> vt;
	int tmp;
	string ans = "";
	while(n != 0){
		tmp = n % 2;
		vt.push_back(tmp);
		n = n / 2;
	}
	for(int i = vt.size() - 1 ; i >= 0 ; i--){
		ans += vt[i] + '0';
	}
	while(ans.length() < 8){
		ans = ans.insert(0,"0");
	}
	return ans;
}

string hex(int n){
	char idx = 'A'; 
	int du;
	string ans = "";
	while(n != 0){
		du = n % 16;
		if(du >= 10){
			char tmp = idx + (du - 10);
			ans = tmp + ans;
		}
		else{
			ans = ans.insert(0,to_string(du));
		}
		n = n / 16;
	}
	return ans;
}

int convert(string s){
	int ans = 0;
	int idx = 0;
	for(int i = s.length() - 1 ; i >= 0 ; i--){
		if(s[i] == '1'){
			ans += pow(2,idx);
			idx++;
		}
		else{
			idx++;
		}
	}
	return ans;
}

void outputAnd(){
	string s1, s2; 
	string ans = ""; 
	for(auto it : And){
		s1 = binary(it.first);
		s2 = binary(it.second);
		for(int i = 0 ; i < s1.length() ; i++){
		if(s1[i] == '1' && s2[i] == s1[i]){
			ans += '1';
		}
		else{
			ans += '0';
		}
	}
	cout << endl << it.first << " & " << it.second << " --> " << convert(ans) << " (" << ans << ")";
	}
}

void outputOr(){
	string s1, s2; 
	string ans = ""; 
	for(auto it : Or){
		s1 = binary(it.first);
		s2 = binary(it.second);
		for(int i = 0 ; i < s1.length() ; i++){
		if(s1[i] == '1' || s2[i] == '1'){
			ans += '1';
		}
		else{
			ans += '0';
		}
	}
	cout << endl << it.first << " | " << it.second << " --> " << convert(ans) << " (" << ans << ")";
	}
}

void outputXoR(){
	string s1, s2; 
	string ans = ""; 
	for(auto it : XoR){
		s1 = binary(it.first);
		s2 = binary(it.second);
		for(int i = 0 ; i < s1.length() ; i++){
		if(s1[i] == s2[i]){
			ans += '1';
		}
		else{
			ans += '0';
		}
	}
	cout << endl << it.first << " ^ " << it.second << " --> " << convert(ans) << " (" << ans << ")";
	}
}

void outputBinary(int Arr[], int n){
	for(int i = 0 ; i < n ; i++){
		cout << endl << "Element " << i + 1 << " : " << Arr[i] << " --> " << binary(Arr[i]) << endl;
	}
}

void outputHex(int Arr[], int n){
	for(int i = 0 ; i < n ; i++){
		cout << endl << "Element " << i + 1 << " : " << Arr[i] << " --> " << hex(Arr[i]) << endl;
	}
}

int main(){
	int n1, n2, n3, n4, n5;
	do{
		cout << endl << "Enter the number of elements to convert to bits : ";
		cin >> n1;
	}while(n1 <= 0);
	int Arr[n1];
	input(Arr,n1);
	cout << endl << "Convert numbers to bits" << endl; 
	outputBinary(Arr,n1);
	do{
		cout << endl << "Enter the number of elements to convert to hex : ";
		cin >> n2;
	}while(n2 <= 0);
	int Hex[n2];
	input(Hex,n2);
	cout << endl << "Convert numbers to Hex" << endl; 
	outputHex(Hex,n2);
	do{
		cout << endl << "Enter the number of value pairs for the and operator : "; 
		cin >> n3;
	}while(n3 <= 0);
	inputAnd(n3);
	cout << endl << "And operation result" << endl; 
	outputAnd();
	do{
		cout << endl << "Enter the number of value pairs for the Or operator : "; 
		cin >> n4;
	}while(n4 <= 0);
	inputOr(n4);
	cout << endl << "Or operation result" << endl; 
	outputOr();
	do{
		cout << endl << "Enter the number of value pairs for the XoR operator : "; 
		cin >> n5;
	}while(n5 <= 0);
	inputXoR(n5);
	cout << endl << "XoR operation result" << endl; 
	outputXoR();
	return 0;
}
