#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class BigInteger
{	
	public:
	string num;
	BigInteger(string a)
	{
		num = a;
	}
	
	string multiply(BigInteger fn,BigInteger sn)
	{
		int carry = 0;
		int answer[100000] = {0};
		vector<int> f;
		vector<int> s;
	//	cout<<"fn "<<fn.num<<endl;
	//	cout<<"sn "<<sn.num<<endl;
		for(int i = 0 ; i<fn.num.size(); i++)
		{
			if(fn.num[i] != '-')		
				f.push_back(fn.num[i]-'0');
		}
		
		for(int i = 0 ; i<sn.num.size(); i++)
		{	
			if(sn.num[i] != '-')	
				s.push_back(sn.num[i]-'0');
		}
		reverse(f.begin(),f.end());
		reverse(s.begin(),s.end());
 /*		cout<<"fn ";
		for(int i = 0;i<f.size();i++)
		{
			cout<<f[i];
		}
		cout<<endl;
		cout<<"sn ";
		for(int i = 0;i<s.size();i++)
		{
			cout<<s[i];
		}
		cout<<endl; */
		int k =0;
		for(long long int i =0;i<s.size();i++)
		{
			int k=0;
			for(long long int j=0;j<f.size();j++)
			{
				long long int mult=0;
				long long int result = f[j]*s[i];
				mult = answer[i+j]+(result+carry);
				//cout<<mult<<endl;
				answer[i+j] = mult%10;
				carry = mult/10;	
				k++;
							
			}
			answer[i+k] = carry;
			carry = 0;
			k++;
		}
		int length = f.size() + s.size();
		reverse(answer,answer+length);
		int l=0;
		if(fn.num[0] == '-' && sn.num[0] != '-')
			cout<<'-';
		if(fn.num[0] != '-' && sn.num[0] == '-')
			cout<<'-';
		ostringstream os;
		for(int i = 0;i<length;i++)
		{
	//		cout<<answer[i];
			os << answer[i];
		}
		string st(os.str());
		st.erase(0, st.find_first_not_of('0'));
		//cout<<"st "<<st<<endl;
		return st;
	}
	
	string substract(BigInteger fn,BigInteger sn)
	{
		int carry = 0;
		vector<int> f;
		vector<int> s;
		int answer[100000] = {0};
		long long int flen;
		long long int slen;
		long long int length;
		if(fn.num == sn.num)
		{
			return "0";
		}
		if(fn.num[0] != '-')
			flen = fn.num.size();
		else
			flen = fn.num.size()-1;
		if(sn.num[0] != '-')
			slen = sn.num.size();
		else
			slen = sn.num.size()-1;
		length = flen > slen ? flen : slen;
		if(flen >= slen)
		{
			length = flen;
			int r = flen - slen;
			while(r--)
			{
				if(sn.num[0] == '-')
					sn.num.insert(1,"0");
				else
					sn.num = "0" + sn.num;
			}
		}
		else
		{
			length = slen;
			int r = slen - flen;
			string str = fn.num;
			while(r--)
			{
				if(fn.num[0] == '-')
					fn.num.insert(1,"0");
				else
					fn.num = "0" + fn.num;
			}
		}
		if(fn.num[0] == '-' && sn.num[0] != '-')
		{
			for(int i = 1 ; i<length+1; i++)
			{					
				f.push_back(fn.num[i]-'0');
			}
			
			for(int i = 0 ; i<length; i++)
			{		
				s.push_back(sn.num[i]-'0');
			}
			reverse(f.begin(),f.end());
			reverse(s.begin(),s.end());
			carry = 0;
			int carry = 0;
			for(long long int i =0;i<length;i++)
			{
				long long int result = f[i]+s[i];
				answer[i] = (result+carry)%10;
				carry = (result+carry)/10;
				answer[i+1] = carry;	
			}
			reverse(answer,answer+length+1);
		//	cout<<'-';
			ostringstream os;
			for(int i = 0;i<length+1;i++)
			{
				os<<answer[i];
			}
			string st(os.str());
			st.erase(0, st.find_first_not_of('0'));
			st = "-"+st;
			return st;
		}
		else if(fn.num[0] != '-' && sn.num[0] == '-')
		{
			for(int i = 0 ; i<length; i++)
			{					
				f.push_back(fn.num[i]-'0');
			}
			
			for(int i = 1 ; i<length+1; i++)
			{		
			//	cout<<sn.num[i]<<" ";
				s.push_back(sn.num[i]-'0');
			}
			reverse(f.begin(),f.end());
			reverse(s.begin(),s.end());
			carry = 0;
			
			int carry = 0;
			for(long long int i =0;i<length;i++)
			{
				long long int result = f[i]+s[i];
				answer[i] = (result+carry)%10;
				carry = (result+carry)/10;
				answer[i+1] = carry;	
			}
			reverse(answer,answer+length+1);
			ostringstream os;
			for(int i = 0;i<length+1;i++)
			{
				os<<answer[i];
			}
			string st(os.str());
			st.erase(0, st.find_first_not_of('0'));
			return st;
		}
		else
		{
			if( fn.num[0] == '-')
			{	
				for(int i = 1 ; i<length; i++)
				{		
					f.push_back(9-(fn.num[i]-'0'));
				}
			}
			else
			{
				for(int i = 0 ; i<length; i++)
				{		
					f.push_back(fn.num[i]-'0');
				//	cout<<f[i]<<" ";
				}
			}
		
			if(sn.num[0] == '-')
			{
				for(int i = 1 ; i<length; i++)
				{		
					s.push_back(sn.num[i]-'0');
				}
			}
			else
			{
				for(int i = 0 ; i<length; i++)
				{		
					s.push_back(9-(sn.num[i]-'0'));
				//	cout<<s[i]<<" ";
				}
			}
		
		reverse(f.begin(),f.end());
		reverse(s.begin(),s.end());
	//	for(int i =0;i<length;i++)
	//	{
	//		cout<<f[i]<<" ";
	//	}
		carry = 0;
		for(long long int i =0;i<length;i++)
		{
				long long int result = f[i]+s[i];
				answer[i] = (result+carry)%10;
				carry = (result+carry)/10;
				answer[i+1] = carry;
				//cout<<answer[i]<<" ";
		}		
		//cout<<answer[length]<<endl;
		if(answer[length] != 0)
		{
			int result;
			int temp  = answer[length];
			answer[0] =answer[0]+temp;
			carry = 0;
			carry = answer[0] / 10;
			int i = 0;			
			if(carry != 0)
			{
				while(carry!=0)
				{
					result = answer[i];
					answer[i] = result % 10;
					carry = result / 10;
					answer[i+1] = answer[i+1]+carry;
					i++;
				}
			}
			answer[length] = 0;
			reverse(answer,answer+length+1);
		//	cout<<answer[0]<<endl;
		//	cout<<l<<endl;
			ostringstream os;
			for(int i = 0;i<length+1;i++)
			{
				os<<answer[i];
			}
			string st(os.str());
			st.erase(0, st.find_first_not_of('0'));
			return st;
		}
		else
		{
		//	cout<<"here"<<endl;
			for(long long int i=0;i<length;i++)
			{
				answer[i] = 9-answer[i];
			//	cout<<answer[i]<<" ";
			}
			reverse(answer,answer+length+1);
			ostringstream os;
			for(int i = 0;i<length+1;i++)
			{
				os<<answer[i];
			}
			string st(os.str());
			st.erase(0, st.find_first_not_of('0'));
			st = "-"+st;
			return st;
		}	
	}
}

	void factorial(BigInteger fn)
	{
    	stringstream ss(fn.num);
    	int num = 0;
    	string result = "1";
    	ss >> num;
    	if(num == 0)
    		cout<<1<<endl;
    	else if(num == 1)
    		cout<<1<<endl;
    	else
    	{
    		for(int i=2; i<=num;i++)
			{
				ostringstream st;
				st<<i;
				string f = st.str();
		//		cout<<"f "<<f<<endl;
				BigInteger sn(f);
			    BigInteger fn(result);
			//    cout<<"result "<<result<<endl;
			//	cout<<"fn number"<<fn.num<<endl;
			//	cout<<"sn number"<<sn.num<<endl;
				result.replace(result.begin(),result.end(),multiply(fn,sn));
		//	    cout<<"main "<<result<<endl;			
			}
			cout<<result<<endl;	
		}
	}
	
	string gcdoftwonumber(BigInteger fn, BigInteger sn)
	{
		string fnum,snum,result;
		fnum = fn.num;
		snum = sn.num;
		
		while(fnum != snum)
		{
			result = substract(fnum,snum);
			if(result[0] == '-')
				snum = substract(snum,fnum);
			else
				fnum = substract(fnum,snum);
		}
		return fnum;
	}
	
	string division(BigInteger fn)
	{
		string num = fn.num;
	//	cout<<num;
	//	int borrow =0;
		int a[100000] = {0};
		vector<int> f;
		for(long long int i = 0 ; i<fn.num.size(); i++)
		{		
			a[i] = fn.num[i]-'0';
			f.push_back(fn.num[i] - '0');
			//cout<<f[i]<<" ";
		}
		//f.push_back(0);
		for(long long int i =0;i<f.size();i++)
		{
			if(a[i] < 2)
			{
				int val = a[i]*10 + a[i+1];
				a[i+1] = val;
				a[i] = 0;
			}
			else
			{
				int res = a[i] /2;
				int rem = a[i] %2;
				a[i] = res;
				a[i+1] = rem*10 + a[i+1];
			}
		}
		long long int length = f.size();
		ostringstream os;
	//	a[length] = a[length] /10;
		for(int i = 0;i<length;i++)
		{
	//		cout<<answer[i];
			os << a[i];
		}
		string st(os.str());
		st.erase(0, st.find_first_not_of('0'));
		//cout<<"st "<<st<<endl;
		return st;
	}
	
	string fastexponential(BigInteger fn, BigInteger sn)
	{
		string base = fn.num;
		string power = sn.num;
		string result = "1";
		while(power != "")
		{
		//	string div = division(power);
		//	cout<<div<<endl;
			if(power[power.size()-1] == '1' || power[power.size()-1] == '3' || power[power.size()-1] == '5' || power[power.size()-1] == '7' || power[power.size()-1] == '9')
			{
				BigInteger fn(base);
				BigInteger sn(power);
				result = multiply(result,base);
			}
			power  = division(power);
			base  = multiply(base,base);				
		}
		return result;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int choice;
		cin>>choice;
		if(choice == 1)
		{
			string x;
			cin>>x;
			string y;
			cin>>y;
			BigInteger fn(x);
			BigInteger sn(y);
			cout<<fn.fastexponential(fn,sn)<<endl;
		}
		if(choice == 2)
		{
			string x;
			cin>>x;
			string y;
			cin>>y;
			BigInteger fn(x);
			BigInteger sn(y);
			cout<<fn.gcdoftwonumber(fn,sn)<<endl;
		}
		if(choice == 3)
		{
			string x;
			cin>>x;
			BigInteger fn(x);
			fn.factorial(fn);
		}
	}
	return 0;
}
